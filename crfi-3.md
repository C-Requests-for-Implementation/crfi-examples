# Title
Type traits

## Status
EXAMPLE

## Abstract
This CRFI aims to provide a set of queries for type properties.

## Issues
- argument format: type vs. value
  - do we prefer to pass types by name or by `typeof(expr)`?
  - do we prefer to return types by name or as a `typeof` operand?

## Rationale

Fluent generic programming is easier when queries can be expressed in a
composable fashion. It is easier to be able to write

    #define ArrayOperation(A)  \
      static_if (IsArray(A), onArray(A), onFallback(A))

than to try to list every single permutation in the explicit branches of
a `_Generic` selection.

Type traits are also useful for "molding" (partially-specialized queries):

    #define AtLeast(V, N)  _Generic(DeclVal(V)                          \
      , LValType(ArrayElementType(V) [CountOf(V)]) : (CountOf(V) > (N)) \
      , default                                    : false)

The above matches any array with unspecified size and element type, to query
whether the size is above a threshold; rather than having to list sizes and
element types explicitly. This requires the ability to query the argument.

## Specification

When a type argument is expected, either a value or a type name is a valid
argument (i.e. `typeof` will be applied internally).

### Selection

    static_if(P, T, E)

The `static_if` macro provides a ternary operation that does not require both
result branches to have the same type. This is especially useful in queries
for ensuring the when an operand fails a requirement, it can be substituted
for some other placeholder to allow the entire false expression to type check.

The macro can also generally be used as a translation-time ternary operator,
as the value of `P` must be constant. Only one of `T` or `E` will be evaluated.

### Is-Queries

    IsArray(V)
    IsFunction(V)

True if an argument is a function or array designator.
These queries return *false* for expressions that have pointer type, so they
distinguish pre- and post-decayed function and array values.

    IsPointer(V)
    IsArithmetic(V)

True if an argument has a pointer or arithmetic type respectively.

    IsInteger(V)
    IsStandardInteger(V)
    IsBitPrecise(V)
    IsFloating(V)
    IsDecimal(V)
    IsComplex(V)
    IsImaginary(V)

True if an argument has integer, standard-integer, but-precise integer, floating,
decimal floating, complex, or imaginary type, respectively.

`IsImaginary` is not optional but will always return false if the implementation
does not support `_Imaginary` types.

    IsStruct(T)
    IsUnion(T)
    IsEnum(T)

True if an argument has struct, union or enum tag type, respectively.

### Function queries

    ReturnType(F)

A type name describing the returned type of the given function argument.

### Array Queries

    ArrayCount(A)

The number of elements in the array type.
Note that since "multi-dimensional" arrays are actually arrays of array
elements, the result for a type like `int[5][5]` would be 5, not 25.
If the argument does not have array type, the result is 1.

    ArrayElementType(A)

The top-level element type of the array. Again, if the argument has a
"multi-dimensional" array type, the result may itself be an array type.
If the argument does not have array type, the result is the argument
type itself.

    ArrayDimension(A)

The overall number of array derivations in a "multi-dimensional" array.
For an array type like `int[5][5]`, the result would be 2. If there are
any intervening derivations (like an array of pointers to arrays), only
the array derivations outside the "breaking" derivation are counted.
If the argument is not an array type, the result is 0.

### Helpers

    DeclVal(V)

This macro accepts any argument and returns a pointer to a local copy of
the value in a compound literal. This can produce pointers to expressions
that would normally be r-values (e.g. `DeclVal(2+2)`).
This is an evaluated expression and the value can be dereferenced and used.

    LValueType(T)

The type of a pointer to the argument.
This can be paired with `DeclVal` to make matching array and function types
easier in `_Generic`.

## Implementation

See attached file.

## Acknowledgements

## Copyright
CC0: This work has been marked as dedicated to the public domain.
