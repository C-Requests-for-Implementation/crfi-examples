# Title
CRFI feature dependencies

## Status
EXAMPLE

## Abstract
This CRFI describes operators and key identifiers to be used for marking code
as dependent on non-mandatory features, and testing for their availability.

This CRFI also describes the standard way for a CRFI to describe its own
availability to the rest of the system.

## Issues

## Rationale
Code wishing to use a CRFI needs to know that either the implementation
provides it natively, or the library includes provide the feature. Since the
feature may not necessarily be provided as a header, testing `__has_include`
is not sufficient.

This also goes for CRFIs depending on other CRFIs, CRFIs that wish to provide
the implementation by building on non-standard language extensions, and by
extension also for user code that wishes to use the language extensions that
might be built on by CRFIs.

Code can either assert that a feature is definitely available, or query its
availability and use different strategies for different configurations.

## Specification
Two interface macros are provided by this CRFI:

### Feature testing

    has_feature(key)

This macro returns 1 if the feature named by `key` is available, and 0 if not.
This does not depend on a header for the corresponding CRFI already having been
included, and can rather be used as a guide for _whether_ to include such.

### Feature requirement

    require_feature(key)

This macro asserts that the feature named by `key` is available.
If the equivalent call to `has feature` would return 0, a constraint is
violated, causing the implementation to emit an error.

### Feature keys

Individual CRFIs are identified by keys with the consistent pattern:

    CRFI_xx

where `xx` is the CRFI number. Therefore, CRFI-1 is identified by `CRFI_1`,
CRFI-64 is identified by `CRFI_64`, and CRFI-255 is identified by `CRFI_255`.
`CRFI_0` is implicitly available.

Every implementation of a CRFI should mark its availability by defining the
corresponding macro:

    #define CRFI_xx_DEFINED

either in the declaring header or as a predefined macro if built-in. Therefore,

    #define CRFI_1_DEFINED 1    // provided by CRFI-1
    #define CRFI_64_DEFINED 1   // provided by CRFI-64
    #define CRFI_255_DEFINED 1  // provided by CRFI-255

This CRFI therefore provides the macro

    #define CRFI_0_DEFINED 1

and it is expected that all subsequent CRFIs provide the respective macro for
their number.

Non-CRFI extension features are identified by the following list:

    stmt_exprs        // GNU C statement expressions
    block_functions   // Clang block lambdas
    block_specifier   // Clang __block storage class
    nested_functions  // GNU nested functions
    fixed_point       // fixed-point real numbers per TR-18037
    label_fwd_decl    // GNU C block-scoped labels
    label_as_value    // GNU C labels as values (&& and goto*)
    case_ranges       // GNU C range expressions in case constants
    desig_ranges      // GNU C range expressions in designators
    fptr_obj_casts    // Annex J.5.7 function <-> object pointer casts

NO description of these features is provided here. User should refer to the
corresponding vendor documentation. 

## Implementation

It is possible for this feature to be provided as a header, given knowledge of
the rest of the CRFI set provided and targeted compiler:

    #include "platform-CRFI-list.h"  // implementation list of CRFIs
    // #define HAVE_CRFI_1 HAVE_THIS_FEATURE
    // #define HAVE_CRFI_2 DONT_HAVE_THIS_FEATURE
    // #define HAVE_CRFI_3 HAVE_THIS_FEATURE
    // (no entry for 4)
    // #define HAVE_CRFI_5 HAVE_THIS_FEATURE
    // etc.
    
    #include "platfor-extension-list.h" // implementation list of extensions
    // #define HAVE_stmt_exprs       HAVE_THIS_FEATURE
    // #define HAVE_block_functions  DONT_HAVE_THIS_FEATURE
    // #define HAVE_block_specifier  DONT_HAVE_THIS_FEATURE
    // #define HAVE_nested_functions HAVE_THIS_FEATURE
    // (no entry for fixed_point)
    // etc.
    
    #define HAVE_THIS_FEATURE 4c,4r,4f,4i
    #define DONT_HAVE_THIS_FEATURE  // (not strictly needed)
    
    #define HAVE_FEATURE(KEY) M_2ORMORE (CAT(HAVE_, KEY))
    
    #define has_feature(KEY) HAVE_FEATURE (KEY)
    #define require_feature(KEY)  \
      _Static_assert (has_feature (KEY), "require feature " #KEY)

using the following common definitions of `CAT` and `M_2ORMORE`:

    #define CAT(X, Y) CAT_(X, Y)
    #define CAT_(X, Y) X##Y
    
    #define M_NARGS(...) M_NARGS_(__VA_ARGS__, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
      20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
    #define M_NARGS_(_32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, \
      _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N
    
    #define M_2ORMORE(...) M_NARGS_(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)

An ideal implementation would use a compiler builtin:

    #define has_feature(KEY) __builtin_has_feature(KEY)
    #define require_feature(KEY) __builtin_requires(KEY)

## Acknowledgements
The `__has_feature` and `__has_extension` macros from Clang
provide the main basis for this design.

## Copyright
CC0: This work has been marked as dedicated to the public domain.
