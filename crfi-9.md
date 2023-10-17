# Title
Linear math operations

## Status
EXAMPLE

## Abstract
This CRFI provides the most used types required for programming computer graphics:

  - `vec3` -- 3 element vector of floats
  - `vec4` -- 4 element vector of floats (4th component used for homogeneous computations)
  - `mat4x4` -- 4 by 4 elements matrix, computations are done in column major order
  - `quat` -- quaternion

The types are deliberately named like the types in GLSL.
In fact they are meant to be used for the client side computations and passing to
same typed GLSL uniforms.

## Issues
- prefer original interface with output parameters, or value-returns?

## Rationale

Many applications require fundamental 3D rotations and transformations.

By providing a CRFI, users can be assured that they will use the fastest implementation
possible for a given platform to support. If native vector operations are available,
the implementation can decide to use those, or if the implementation is confident that
it will detect and optimize the SIMD operations it can define that. Otherwise, the
operations will remain correct even if implemented using fallback scalar loops.

## Specification

// TODO

## Implementation

See attached file.

## Acknowledgements
Originally by datenwolf: https://github.com/datenwolf/linmath.h
Original licence is WTFPL (public domain).

## Copyright
CC0: This work has been marked as dedicated to the public domain.
