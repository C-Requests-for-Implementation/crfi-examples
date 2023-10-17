# Title
Lightweight coroutines ("protothreads")

## Status
EXAMPLE

## Abstract
This CRFI describes an interface for building lightweight or "stackless"
coroutines. Stackless coroutines are a useful way to organize state machines
and related code such as event systems, and can be constructed entirely out
of freestanding C features with no use of optional libraries.

## Issues

## Rationale

Coroutines provide a useful way to structure code that switches between tasks
co-operatively. Coroutines can be implemented with both full-stack and stackless
semantics. For simple tasks, lightweight semantics will usually provide better
performance than a full-featured implementation that also needs to consider
context management, as they require only a simple function call to enter; but
this is not as expressive and is generally limited to only simple co-operative
algorithms, as only the outer-level function of the co-routine can perform a
yield - there is no stack state and therefore no ability to restore a nested
call context.

## Specification
This CRFI intentionally uses the same keywords as CRFI-8.
Only one implementation should be in use at a time.

## Implementation

// TODO

## Acknowledgements

Adam Dunkels, Simon Tatham, et al

## Copyright
CC0: This work has been marked as dedicated to the public domain.
