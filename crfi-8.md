# Title
Heavyweight coroutines ("fibres")

## Status
EXAMPLE

## Abstract
This CRFI describes an interface for building full-weight or "stackful"
coroutines. Coroutines provide an intuitive way to write co-operative
code that maintains private state, separating logical work units that
"yield" to the next operation. They can be used to implement generators
that simply maintain a private state across multiple invocations of a
function, or to split an algorithm into multiple processing units that
form a horizontal rather than stack-based call structure.

## Issues
- should calls return a value (needs to be type-generic and means `coro_t`
  cannot be a complete object type) or use an output pointer?

## Rationale

Coroutines provide a useful way to structure code that switches between tasks
co-operatively. Coroutines can be implemented with both full-stack and stackless
semantics.

For more involved tasks that involve repeated re-entry, abstract a lot of local
state, and persist for a relative long time, the overhead of stackful coroutines
can be worthwhile because of the more fluid program organization it permits.

Coroutines allow similar organization of a program into separate work units as
threads, but without the expectation that work will be performed at the same time.
Therefore, coroutines are a code structuring tool rather than a machine resource
management tool.

## Specification
This CRFI intentionally uses the same keywords as CRFI-7.
Only one implementation should be in use at a time.

The stackful-coroutines interface is intentionally very similar to the Standard
threads API, as a coroutine is a cooperative logical thread.

It is unspecified whether coroutine execution takes place in the same C thread as
the calling code. Accessing a `thread_local` object in the caller is undefined.
Any object with static storage duration is shared between all coroutines normally.

### Coroutine objects

    typedef coro_t

A complete object type that holds the state of a coroutine's cooperative thread,
allowing entry and re-entry.

    typedef coro_start_t

A function pointer type for the entry point to a coroutine.
This type is defined to be the same as `thrd_start_t` (i.e. `int (*) (void*)`).

### Return status flags

    coro_success
    coro_error
    coro_nomem

The above status flags are defined to be the same as `thrd_success`, `thrd_error`
and `thrd_nomem` respectively.

### Creation and destruction

    int coro_create (coro_t * coro, coro_start_t func, void * data);

Creates a new coroutine state in the passed `coro_t` object and returns an error
code (TODO) indicating whether the context could be allocated or not. After this
call the coroutine may be entered.

Unlike a corresponding call to `thrd_create`, this call does not immediately
call the entry function. The coroutine is placed in a ready state.

    int coro_free (coro_t * coro);

Dispose of the resources associated with `coro` and place the object back into an
uninitialized state. Returns the status code `coro_success` if the operation was
successful, and `coro_nomem` if memory could not be allocated for the context, or
`coro_error` if creation failed for another reason.

### Calls and yields

All calls into and out of coroutines are performed using a symmetrical interface:

    void * coro_yield (void * result, coro_t * next);
    void * coro_yield (void * result);

The `coro_yield` function passes control to the `coro_t` named by `next`, and gives
it `result` as an argument. If this is the first call to the given coroutine, the
`result` data will be passed as an argument to the start function. Otherwise,
execution of the coroutine context will resume at the point of return of a previous
invocation of `coro_yield` within its state, in which case the `result` pointer
will become the return value of that call.

Execution of the caller **pauses while the coroutine is active** - this does not
produce parallel execution.

The `result` value may point to valid local (i.e. automatic) storage within the
coroutine call stack, and remains valid until the coroutine is explicitly destroyed.
(Within the coroutine call context, normal syntactic object lifetime rules apply.)
NOTE If the pointer is to local storage it is therefore invalidated by `coro_free`.

If no `next` coroutine is specified, control will return to the coroutine (or main
program context) from which this coroutine was last entered. (This avoids needing to
create a coroutine object to represent the implicit state of the main thread.)

## Implementation

Stackful coroutines can be built atop the Standard threads API, although
this will produce a very inefficient implementation if there are many
yields.

A better implementation is possible atop POSIX `setcontext`.

// TODO

## Acknowledgements

based on the threads library in Standard Section 7

## Copyright
CC0: This work has been marked as dedicated to the public domain.
