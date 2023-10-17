# Title
Monadic optional and expected values

## Status
EXAMPLE

## Abstract
Monadic option values do not allow direct access to the contained value without
first passing through a check for an invalid or null state. Unlike the builtin
pointer types, this makes it "impossible" to use a non-value such as a null,
because the control flow is integrated with the check for validity and the
branch that makes use of the value cannot be reached without going through the
test, unlike a pointer which can be syntactically dereferenced anywhere.

Both "optional" and "expected" pointer types can be defined and can share operators.

## Issues
- would val = expect (opt) make more sense?
- are pointer types or general value types more useful?
  - tradeoffs: pointers have better usability because they're "more" applicative
               general value types have wider use cases (though this is not C++)
               but are harder to use in signatures
  - provide both?
- anaphoric syntax is probably not idiomatic
- depends on `panic` but does not really aim to define it

## Rationale

Separating the ability to express null state from the ability to dereference an
lvalue reduces the chances of _using_ a pointer that does not refer to a valid
object. "Monadic" option types separate the nullable pointer from the usable
pointer, and hide the conversion inside the check for validity, so that it is
semantically not possible (by following the API) to get the usable pointer to
the object without having either checked it for validity or intentionally cast
away the strong typing for nullable status.

Combining the check for validity with a scope-introducing syntax makes it
more difficult for the name holding the result to be misused, and clearly
delineates the "safe extents" of the non-null _direct_ pointer.

## Specification

This CRFI provides two type specifier macros, four value constructors, and
two new control structures implementing the monadic checks.

The rest of the header is //detail.

### Type specifiers

    Optional(T)
    Expected(T)

These two macros accept a type name, and the result is a type specifying a
_Maybe_-pointer to that type. The `Optional` specifier describes a possibly-null
pointer type, and the `Expected` specifier describes a pointer type for which
the null state would be an error.

Therefore, `Optional(int)` describes a pointer to an `int` that may be null and
which can be accessed by a `just` operation if non-null; and `Expected(int)`
describes a pointer to an `int` that is never expected to be null at any point
access is attempted by a `just` operation.

### Value constructors

    makeOptional(V)   
    makeExpected(V)   

These two macros create a pointer to the named lvalue argument, then package it
inside either an `Optional` or `Expected` type wrapper respectively. The pointer
can be accessed for normal use within a `just` or `expect` block.

    makeNil(T)        
    makeNilExpected(T)

These two macros create a null pointer and give it the respective `Optional` or
`Expected` wrapper type.

It is not an error to pass null values around. It is an error to try to access
the content of a null `Expected` pointer.

### Operators

    just (maybe) {
      ...
    }
    expect (maybe) {
      ...
    }

These two macros describe new control structures that check the value of a _Maybe_
expression, and if it is not null, enter the following compound statement. Within
the compound statement, the underlying pointer value of the _Maybe_ is available as
the anaphoric parameter, `it`. For example:

    Optional(int) oi = makeOptional(x);
    
    just (oi) {
      *it = 6;  // accessible as the native pointer 'it'
    }

`just` may be followed by an `else` branch which will be entered if the value of the
`Optional` is null and therefore the main compound was not entered.
`expect` is similar to `just`, but it is an error if the _Maybe_ was a null value
and a panic will be raised, so no `else` is possible.
Either `Optional` or `Expected` may be passed to both `just` and `expect`. If an
`Expected` is passed to `just`, the behaviour is the same as if `expect` had been
used (panic on a null value).

## Implementation

This implementation provides optional and expected pointers.
For optional and expected inline values, see attached example file.

    require_feature(fptr_obj_casts); // J.5.7 casts
    require_feature(CRFI_1);         // common macros (BEFORE)

    // detail
    struct OptionalTag /* incompletable */;
    struct ExpectedTag /* incompletable */;
    typedef void (* ForceExpect) (int);

    // using a function pointer type relies on J.5.7
    // but has the advantage of being fully applicable
    #define MakeMaybeType(VT, Tag) typeof (typeof (VT) * (*) (struct Tag *))
    #define GetMaybeType(Val, Tag) MakeMaybeType (typeof (Val), Tag)
    #define GetPointerType(Val) typeof ((Val)(0))

    #define Optional(Value) MakeMaybeType (Value, OptionalTag)
    #define Expected(Value) MakeMaybeType (Value, ExpectedTag)

    #define panicCheck(Val) ((Val) != 0 ? 1 : (panic (), 0))

    #define checkValid(Val) (_Generic ((Val)                            \
      , GetPointerType(Val) (*) (struct OptionalTag) : ((Val) != 0)     \
      , GetPointerType(Val) (*) (struct ExpectedTag) : panicCheck (Val) \
      , default  /* simple way to force Expected */  : panicCheck (Val)))

    #define MaybeSelect(Val)  \
      M_BEFORE (auto const JUST_value = (Val))  \
        M_BEFORE (auto const it = (typeof ((Val)(0)))JUST_value)
    #define just(Val)   \
      MaybeSelect (Val) \
        if (checkValid (JUST_value)) /* body */
    #define expect(Val) \
      MaybeSelect (Val) \
        if (!checkValid ((ForceExpect)JUST_value)) { panic(); } else /* body */

    #define makeMaybePtr(VP, Tag)  (GetMaybeType (VP, Tag))&(VP)
    #define makeMaybeNil(T, Tag)   (MakeMaybeType (T, Tag))0

    #define makeOptional(V)    makeMaybePtr (V, OptionalTag)
    #define makeExpected(V)    makeMaybePtr (V, ExpectedTag)
    #define makeNil(T)         makeMaybeNil (T, OptionalTag)
    #define makeNilExpected(T) makeMaybeNil (T, ExpectedTag)

### Example

    void useValue (int x) { printf("%d\n", x); }
    void useNil (void) { printf ("nil\n"); }
    void panic (void) { printf ("panic\n"); }

    void useMaybe    (Optional(int) mi);
    void useExpected (Expected(int) xi);
      
    void use (void)
    {
      int x;
      int * xp;
      struct S {int y;} s;
     
      auto ox = makeOptional (x);
      auto op = makeOptional (xp);
      auto os = makeOptional (s);

      auto ex = makeExpected (x);
      auto ep = makeExpected (xp);
      auto es = makeExpected (s);

      auto nx = makeNil (int);
      auto np = makeNil (typeof (xp));
      auto ns = makeNil (typeof (s));

      auto nxx = makeNilExpected (int);
      auto nxp = makeNilExpected (typeof (xp));
      auto nxs = makeNilExpected (typeof (s));

      just (ox) {
        useValue (*it);
      } else {
        useNil ();
      }

      just (ex) {
        useValue (*it);
      } else {
        useNil ();
      }

      just (nx) {
        useValue (*it);
      } else {
        useNil ();
      }

      just (nxx) {
        useValue (*it);
      } else {
        useNil ();
      }

      expect (ox) {
        useValue (*it);
      }

      expect (ex) {
        useValue (*it);
      }

      expect (nx) {
        useValue (*it);
      }

      expect (nxx) {
        useValue (*it);
      }

      useMaybe (ox);
      useMaybe (nx);
      useExpected (ex);
      // useExpected (ox); // error
    }

## Acknowledgements

Thanks to Chris Bazley for suggesting the idea of `_Nullable` pointers, and
Stanislav (@Reflexive Aero) for suggesting `Expected` in C.

## Copyright
CC0: This work has been marked as dedicated to the public domain.
