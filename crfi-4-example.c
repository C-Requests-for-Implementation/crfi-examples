
#include <stdio.h>


struct OptionalTag { char x; };
struct ExpectedTag { char x; };

#define MakeMaybeType(Value, Tag) union {  \
  struct { Value value; _Bool valid; };    \
  struct Tag tag;                          \
}

#define Optional(Value) MakeMaybeType (Value, OptionalTag)
#define Expected(Value) MakeMaybeType (Value, ExpectedTag)

// NOTE it is possible to sim applicative types with typeid

#define checkValid(Val) _Generic (Val.tag  \
  , struct OptionalTag : Val.valid         \
  , struct ExpectedTag : Val.valid ? 1 : (panic (), 0))

#define MaybeSelect(Val)  \
  M_BEFORE (auto JUST_value = (Val))  \
    M_BEFORE (typeof (JUST_value.value) it = JUST_value.value)
#define just(Val)   \
  MaybeSelect (Val) \
    if (checkValid (JUST_value)) /* body */
#define expect(Val) \
  MaybeSelect (Val) \
    if (!JUST_value.valid) { panic(); } else /* body */

// TODO use a way to lookup applicatives
#define GetMaybeType(V, Tag)  \
  MakeMaybeType (typeof (V), Tag)

#define makeMaybeValue(V, Tag)  \
  (GetMaybeType (V, Tag)){ .value = (V), .valid = 1 }
#define makeMaybeNil(T, Tag)  \
  (GetMaybeType (T, Tag)){ .value = {}, .valid = 0 }

#define makeOptional(V) makeMaybeValue (V, OptionalTag)
#define makeExpected(V) makeMaybeValue (V, ExpectedTag)
#define makeNil(T)         makeMaybeNil (T, OptionalTag)
#define makeNilExpected(T) makeMaybeNil (T, ExpectedTag)


// CRFI-1
#define M_BEFORE_AFTER(BEFORE, AFTER)  \
  for (_Bool M_ONCEFOR_enter = 1; M_ONCEFOR_enter ; AFTER )  \
    for (BEFORE ; M_ONCEFOR_enter ; M_ONCEFOR_enter = 0)
      /* { body } */
#define M_BEFORE(BEFORE) M_BEFORE_AFTER(BEFORE, (void)0)
#define M_AFTER(AFTER)   M_BEFORE_AFTER((void)0, AFTER)


void useValue (int x) { printf("%d\n", x); }
void useNil (void) { printf ("nil\n"); }
void panic (void) { printf ("panic\n"); }

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
    useValue (it);
  } else {
    useNil ();
  }

  just (ex) {
    useValue (it);
  } else {
    useNil ();
  }

  just (nx) {
    useValue (it);
  } else {
    useNil ();
  }

  just (nxx) {
    useValue (it);
  } else {
    useNil ();
  }

  expect (ox) {
    useValue (it);
  }

  expect (ex) {
    useValue (it);
  }

  expect (nx) {
    useValue (it);
  }

  expect (nxx) {
    useValue (it);
  }
}
