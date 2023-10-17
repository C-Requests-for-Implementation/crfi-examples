// stdtypetraits.h
//
// start of a traits header
//

// a function identifier will always decay to a pointer to itself
#define SelfDecays(V) _Generic ((0, V)  \
    , typeof(V) * : true                \
    , default     : false)

// simple is-decaying : if the type of the value is the same
// as the type of the expression it can't be an array
// however, this does not generalize to allow function types
// (they cannot be queried, listing them is an error)
#define IsDecaying_wrong(V) _Generic((0, V)  \
    , typeof(V) : false                      \
    , default   : true)

// // no good because typeof(function) cannot appear as a match
// #define IsArray(V)    (IsDecaying_wrong (V) && !SelfDecays (V))
// #define IsFunction(V) (IsDecaying_wrong (V) ||  SelfDecays (V))


// we can take advantage of "molding" queries: the selection
// list is also able to query the type of the operand to ensure
// the types it names are safe

#define PointerDecays(V) _Generic ((0, V)  \
  , typeof (static_if (SelfDecays (V), (TraitsNeverMatchType){}, (V))) : false  \
  , default : true)

#define static_if(P, T, E)      \
  _Generic(&(int[!!(P) + 1]){}  \
    , typeof (int[2]) * : (T)   \
    , typeof (int[1]) * : (E))

// (can't use in defn of static_if)
#define DeclVal(V) (&(typeof(                                \
  static_if (SelfDecays (V), (TraitsNeverMatchType){}, (V))  \
)){0})
#define LValType(T) typeof(T) *

typedef
struct TraitsNeverMatchType { int unused; }
       TraitsNeverMatchType;

#define IsArray(V)    (PointerDecays (V) && !SelfDecays (V))
#define IsFunction(V) (PointerDecays (V) &&  SelfDecays (V))


int arr[10];
int * ptr;

int func (void);
int (*fptr) (void);

_Static_assert (IsArray (arr));
_Static_assert (!IsFunction (arr));

_Static_assert (!IsArray (ptr));
_Static_assert (!IsFunction (ptr));

_Static_assert (IsFunction (func));
_Static_assert (!IsArray (func));

_Static_assert (!IsArray (fptr));
_Static_assert (!IsFunction (fptr));


// more examples of "molding":

// CountOf returns 1 when the query is not an array
// so in that case the branch that isn't used anyway
// substitutes a char array to apply [0] to
#define CountOf(A) (IsArray(A)   \
    ? sizeof(A) / sizeof(static_if (IsArray(A), (A), &(char){0})[0]) \
    : 1)

// ArrayElementType (we could have used this above)
#define ArrayElementType(A)  \
  typeof (static_if (IsArray(A), (A), DeclVal (A))[0])

// MatchAnyArray shows that both the dimension and
// the element type can be substituted before trying
// to make the match, two steps of "molding"

#define MatchAnyArray(V) _Generic(DeclVal(V)           \
  , LValType (ArrayElementType(V) [CountOf(V)]) : true \
  , default                                     : false)

int ia[10];
char ca[10];
float fa[10];
int * ip;
char * cp;
float * fp;
int * i;
char * c;
float * f;
_Static_assert (MatchAnyArray (ia));
_Static_assert (MatchAnyArray (ca));
_Static_assert (MatchAnyArray (fa));
_Static_assert (!MatchAnyArray (ip));
_Static_assert (!MatchAnyArray (cp));
_Static_assert (!MatchAnyArray (fp));
_Static_assert (!MatchAnyArray (i));
_Static_assert (!MatchAnyArray (c));
_Static_assert (!MatchAnyArray (f));

_Static_assert (!MatchAnyArray (func));
_Static_assert (!MatchAnyArray (fptr));

int ia2[5][5];
_Static_assert (MatchAnyArray(ia2));
_Static_assert (MatchAnyArray(ia2[0]));
_Static_assert (!MatchAnyArray(ia2[0][0]));

// IsBitPrecise works the opposite way around
// start by finding the precision which can be applied to any
// integer, then "molding" a query so that only two types need
// to be listed and all non-bitprec integers fall through default
// https://gist.github.com/AlexCeleste/170195deae827f02a95aa03abc5f5c3b#file-bitint-c

// Dimension can be measured by stacking up IsArray
// up to the translation limit (min 12)
#define ArrayDimension(V)  ArrayDimensionLimit (V)

#define ArrayDimensionLimit ArrayDimension5//12 // brevity in example

#define ArrayDimension5(A) (IsArray(A) ? ArrayDimension4((ArrayElementType(A)){0}) + 1 : 0)
#define ArrayDimension4(A) (IsArray(A) ? ArrayDimension3((ArrayElementType(A)){0}) + 1 : 0)
#define ArrayDimension3(A) (IsArray(A) ? ArrayDimension2((ArrayElementType(A)){0}) + 1 : 0)
#define ArrayDimension2(A) (IsArray(A) ? ArrayDimension1((ArrayElementType(A)){0}) + 1 : 0)
#define ArrayDimension1(A) (IsArray(A) ? 1 : 0)

_Static_assert (ArrayDimension (ia) == 1);
_Static_assert (ArrayDimension (ia2) == 2);
int ia3[2][2][2];
int ia5[1][1][1][1][1];
_Static_assert (ArrayDimension (ia3) == 3);
_Static_assert (ArrayDimension (ia5) == 5);
