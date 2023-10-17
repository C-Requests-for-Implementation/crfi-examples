# Title
Reusable detemrinistic counter macro

## Status
EXAMPLE

## Abstract
This CRFI defines a COUNTER macro which is incremented manually via
user directive and which can be manually reset. The result is a
single-token value expression suitable for token-pasting.

## Issues
- limited number of slots

## Rationale
Some implementations do provide a builtin `__COUNTER__` macro as an
extension to the Standard set of predefined macro names. This has
a number of problems stemming from the implicit increment behaviour
that makes it unsuitable for library-building, as the concrete value
of the counter cannot be assumed, to allow links between declarations,
and also cannot be assumed to be _stable_ in the course of building a
multi-part statement.

Manual increment of the counter allows explicit control and stability
which is useful for "registration" purposes within library headers.

## Specification
(NOTE: implementations should provide this CRFI as a series of separate
numbered slot files each with their own prefix. Examples describe `SLOTn`
where `n` is an implementation-defined number.
Userss can determine if a slot number is available with `__has_include`.)

One primary interface macro is provided by the CRFI, with some additional
options to control printing:

### The counter

    SLOTn_COUNTER

This macro expands to a single-token integer. The value is the last
incremented value of the slot.

### Increment

    INCREMENT_SLOTn
    #include INCREMENT_SLOTn

The `INCREMENT_SLOTn` macro contains the name of the file controlling the
counter at slot `n`.
The `#include` directive is used to perform an increment. After the first
inclusion, the value is zero, and at every subsequent inclusion the value
is incremented by one.

The value may be manually set by defining it to an arbitrary integer expression.
A subsequent inclusion will increment the value normally and produce a
value in the specified single-token format.

### Print options

Four macros are provided to control the format of the resulting counter value:

    SLOTn_COUNTER_BIN
    SLOTn_COUNTER_HEX
    SLOTn_COUNTER_EXPR
    SLOTn_COUNTER_HEXDIG

`BIN` produces a value in binary constant format (`0b010101`).
`HEX` produces a value in hexadecimal constant format (`0x123abc`).
`HEXDIG` produces a non-prefixed hexadecimal digit sequence (`123abc`). Note that
this is not a valid numeric constant by itself.

`EXPR` produces a value in an expanded expression format. This is suitable for
debugging but cannot be used for token-pasting.

To actually set the print format, the macro

    SLOTn_COUNTER_PRINT

is defined to one of the above macro names.
The default print format is `SLOTn_COUNTER_HEX`.

## Implementation

See attached file.

The intention is that a vendor provide copies of this as numbered
slotfiles:

    #include INCREMENT_SLOT1 // increment counter 1
    #include INCREMENT_SLOT2 // increment separate counter 2

The implementation can generate these from the base file with
`sed 's/$PFX$_/SLOTn_/'` or a dynamic substitution mechanism such as

    // counter-slot1.h
    #include "counter-template.inc" prefix($PFX$_, SLOT1_)
    
    // counter-slot2.h
    #include "counter-template.inc" prefix($PFX$_, SLOT2_)
    
    // etc.

if available.

## Acknowledgements
Inspired by Boost.PP "preprocessor slots", but not implemented in
a similar way.

## Copyright
CC0: This work has been marked as dedicated to the public domain.
