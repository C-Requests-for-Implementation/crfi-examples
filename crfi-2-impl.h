// type_counter.h
//
// increment the value of the counter
// every time this file is included
//
// this uses a value representation that can
// easily be converted to a single literal, for pasting
//
// value is handled by binary representation but
// stored in a record of single-bit fields rather than
// as a composite expression
// this can be used as the argument to a simple eval
// or a pretty-print, even supporting different fmts
// (0b, 0x, etc) - select with $PFX$_COUNTER_PRINT
//
// 20-bit hex by default
//

// no whole-file guard, repeatable inclusion

#ifndef $PFX$_COUNTER_RECORD

  // starting value of zero
  #define $PFX$_COUNTER_RECORD (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)

#else

  #undef  $PFX$_COUNT_COPY_BIT_0
  #undef  $PFX$_COUNT_COPY_BIT_1
  #undef  $PFX$_COUNT_COPY_BIT_2
  #undef  $PFX$_COUNT_COPY_BIT_3
  #undef  $PFX$_COUNT_COPY_BIT_4
  #undef  $PFX$_COUNT_COPY_BIT_5
  #undef  $PFX$_COUNT_COPY_BIT_6
  #undef  $PFX$_COUNT_COPY_BIT_7
  #undef  $PFX$_COUNT_COPY_BIT_8
  #undef  $PFX$_COUNT_COPY_BIT_9
  #undef  $PFX$_COUNT_COPY_BIT_10
  #undef  $PFX$_COUNT_COPY_BIT_11
  #undef  $PFX$_COUNT_COPY_BIT_12
  #undef  $PFX$_COUNT_COPY_BIT_13
  #undef  $PFX$_COUNT_COPY_BIT_14
  #undef  $PFX$_COUNT_COPY_BIT_15
  #undef  $PFX$_COUNT_COPY_BIT_16
  #undef  $PFX$_COUNT_COPY_BIT_17
  #undef  $PFX$_COUNT_COPY_BIT_18
  #undef  $PFX$_COUNT_COPY_BIT_19

  #define $PFX$_COUNT_COPY_BIT_0  0
  #define $PFX$_COUNT_COPY_BIT_1  0
  #define $PFX$_COUNT_COPY_BIT_2  0
  #define $PFX$_COUNT_COPY_BIT_3  0
  #define $PFX$_COUNT_COPY_BIT_4  0
  #define $PFX$_COUNT_COPY_BIT_5  0
  #define $PFX$_COUNT_COPY_BIT_6  0
  #define $PFX$_COUNT_COPY_BIT_7  0
  #define $PFX$_COUNT_COPY_BIT_8  0
  #define $PFX$_COUNT_COPY_BIT_9  0
  #define $PFX$_COUNT_COPY_BIT_10 0
  #define $PFX$_COUNT_COPY_BIT_11 0
  #define $PFX$_COUNT_COPY_BIT_12 0
  #define $PFX$_COUNT_COPY_BIT_13 0
  #define $PFX$_COUNT_COPY_BIT_14 0
  #define $PFX$_COUNT_COPY_BIT_15 0
  #define $PFX$_COUNT_COPY_BIT_16 0
  #define $PFX$_COUNT_COPY_BIT_17 0
  #define $PFX$_COUNT_COPY_BIT_18 0
  #define $PFX$_COUNT_COPY_BIT_19 0

  #define $PFX$_INCRVAL ($PFX$_COUNTER + 1)

  // update new values for bits

  #if $PFX$_INCRVAL & (1ul << 0ul)
    #undef  $PFX$_COUNT_COPY_BIT_0
    #define $PFX$_COUNT_COPY_BIT_0 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 1ul)
    #undef  $PFX$_COUNT_COPY_BIT_1
    #define $PFX$_COUNT_COPY_BIT_1 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 2ul)
    #undef  $PFX$_COUNT_COPY_BIT_2
    #define $PFX$_COUNT_COPY_BIT_2 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 3ul)
    #undef  $PFX$_COUNT_COPY_BIT_3
    #define $PFX$_COUNT_COPY_BIT_3 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 4ul)
    #undef  $PFX$_COUNT_COPY_BIT_4
    #define $PFX$_COUNT_COPY_BIT_4 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 5ul)
    #undef  $PFX$_COUNT_COPY_BIT_5
    #define $PFX$_COUNT_COPY_BIT_5 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 6ul)
    #undef  $PFX$_COUNT_COPY_BIT_6
    #define $PFX$_COUNT_COPY_BIT_6 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 7ul)
    #undef  $PFX$_COUNT_COPY_BIT_7
    #define $PFX$_COUNT_COPY_BIT_7 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 8ul)
    #undef  $PFX$_COUNT_COPY_BIT_8
    #define $PFX$_COUNT_COPY_BIT_8 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 9ul)
    #undef  $PFX$_COUNT_COPY_BIT_9
    #define $PFX$_COUNT_COPY_BIT_9 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 10ul)
    #undef  $PFX$_COUNT_COPY_BIT_10
    #define $PFX$_COUNT_COPY_BIT_10 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 11ul)
    #undef  $PFX$_COUNT_COPY_BIT_11
    #define $PFX$_COUNT_COPY_BIT_11 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 12ul)
    #undef  $PFX$_COUNT_COPY_BIT_12
    #define $PFX$_COUNT_COPY_BIT_12 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 13ul)
    #undef  $PFX$_COUNT_COPY_BIT_13
    #define $PFX$_COUNT_COPY_BIT_13 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 14ul)
    #undef  $PFX$_COUNT_COPY_BIT_14
    #define $PFX$_COUNT_COPY_BIT_14 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 15ul)
    #undef  $PFX$_COUNT_COPY_BIT_15
    #define $PFX$_COUNT_COPY_BIT_15 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 16ul)
    #undef  $PFX$_COUNT_COPY_BIT_16
    #define $PFX$_COUNT_COPY_BIT_16 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 17ul)
    #undef  $PFX$_COUNT_COPY_BIT_17
    #define $PFX$_COUNT_COPY_BIT_17 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 18ul)
    #undef  $PFX$_COUNT_COPY_BIT_18
    #define $PFX$_COUNT_COPY_BIT_18 1
  #endif

  #if $PFX$_INCRVAL & (1ul << 19ul)
    #undef  $PFX$_COUNT_COPY_BIT_19
    #define $PFX$_COUNT_COPY_BIT_19 1
  #endif

  // update actual bits

  #undef $PFX$_COUNT_BIT_0
  #undef $PFX$_COUNT_BIT_1
  #undef $PFX$_COUNT_BIT_2
  #undef $PFX$_COUNT_BIT_3
  #undef $PFX$_COUNT_BIT_4
  #undef $PFX$_COUNT_BIT_5
  #undef $PFX$_COUNT_BIT_6
  #undef $PFX$_COUNT_BIT_7
  #undef $PFX$_COUNT_BIT_8
  #undef $PFX$_COUNT_BIT_9
  #undef $PFX$_COUNT_BIT_10
  #undef $PFX$_COUNT_BIT_11
  #undef $PFX$_COUNT_BIT_12
  #undef $PFX$_COUNT_BIT_13
  #undef $PFX$_COUNT_BIT_14
  #undef $PFX$_COUNT_BIT_15
  #undef $PFX$_COUNT_BIT_16
  #undef $PFX$_COUNT_BIT_17
  #undef $PFX$_COUNT_BIT_18
  #undef $PFX$_COUNT_BIT_19

  #define $PFX$_COUNT_BIT_0  0
  #define $PFX$_COUNT_BIT_1  0
  #define $PFX$_COUNT_BIT_2  0
  #define $PFX$_COUNT_BIT_3  0
  #define $PFX$_COUNT_BIT_4  0
  #define $PFX$_COUNT_BIT_5  0
  #define $PFX$_COUNT_BIT_6  0
  #define $PFX$_COUNT_BIT_7  0
  #define $PFX$_COUNT_BIT_8  0
  #define $PFX$_COUNT_BIT_9  0
  #define $PFX$_COUNT_BIT_10 0
  #define $PFX$_COUNT_BIT_11 0
  #define $PFX$_COUNT_BIT_12 0
  #define $PFX$_COUNT_BIT_13 0
  #define $PFX$_COUNT_BIT_14 0
  #define $PFX$_COUNT_BIT_15 0
  #define $PFX$_COUNT_BIT_16 0
  #define $PFX$_COUNT_BIT_17 0
  #define $PFX$_COUNT_BIT_18 0
  #define $PFX$_COUNT_BIT_19 0

  #if $PFX$_COUNT_COPY_BIT_0
    #undef  $PFX$_COUNT_BIT_0
    #define $PFX$_COUNT_BIT_0 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_1
    #undef  $PFX$_COUNT_BIT_1
    #define $PFX$_COUNT_BIT_1 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_2
    #undef  $PFX$_COUNT_BIT_2
    #define $PFX$_COUNT_BIT_2 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_3
    #undef  $PFX$_COUNT_BIT_3
    #define $PFX$_COUNT_BIT_3 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_4
    #undef  $PFX$_COUNT_BIT_4
    #define $PFX$_COUNT_BIT_4 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_5
    #undef  $PFX$_COUNT_BIT_5
    #define $PFX$_COUNT_BIT_5 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_6
    #undef  $PFX$_COUNT_BIT_6
    #define $PFX$_COUNT_BIT_6 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_7
    #undef  $PFX$_COUNT_BIT_7
    #define $PFX$_COUNT_BIT_7 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_8
    #undef  $PFX$_COUNT_BIT_8
    #define $PFX$_COUNT_BIT_8 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_9
    #undef  $PFX$_COUNT_BIT_9
    #define $PFX$_COUNT_BIT_9 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_10
    #undef  $PFX$_COUNT_BIT_10
    #define $PFX$_COUNT_BIT_10 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_11
    #undef  $PFX$_COUNT_BIT_11
    #define $PFX$_COUNT_BIT_11 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_12
    #undef  $PFX$_COUNT_BIT_12
    #define $PFX$_COUNT_BIT_12 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_13
    #undef  $PFX$_COUNT_BIT_13
    #define $PFX$_COUNT_BIT_13 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_14
    #undef  $PFX$_COUNT_BIT_14
    #define $PFX$_COUNT_BIT_14 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_15
    #undef  $PFX$_COUNT_BIT_15
    #define $PFX$_COUNT_BIT_15 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_16
    #undef  $PFX$_COUNT_BIT_16
    #define $PFX$_COUNT_BIT_16 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_17
    #undef  $PFX$_COUNT_BIT_17
    #define $PFX$_COUNT_BIT_17 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_18
    #undef  $PFX$_COUNT_BIT_18
    #define $PFX$_COUNT_BIT_18 1
  #endif

  #if $PFX$_COUNT_COPY_BIT_19
    #undef  $PFX$_COUNT_BIT_19
    #define $PFX$_COUNT_BIT_19 1
  #endif

  #undef $PFX$_INCRVAL


  #undef $PFX$_COUNTER_RECORD
  #define $PFX$_COUNTER_RECORD \
     ($PFX$_COUNT_BIT_0        \
     ,$PFX$_COUNT_BIT_1        \
     ,$PFX$_COUNT_BIT_2        \
     ,$PFX$_COUNT_BIT_3        \
     ,$PFX$_COUNT_BIT_4        \
     ,$PFX$_COUNT_BIT_5        \
     ,$PFX$_COUNT_BIT_6        \
     ,$PFX$_COUNT_BIT_7        \
     ,$PFX$_COUNT_BIT_8        \
     ,$PFX$_COUNT_BIT_9        \
     ,$PFX$_COUNT_BIT_10       \
     ,$PFX$_COUNT_BIT_11       \
     ,$PFX$_COUNT_BIT_12       \
     ,$PFX$_COUNT_BIT_13       \
     ,$PFX$_COUNT_BIT_14       \
     ,$PFX$_COUNT_BIT_15       \
     ,$PFX$_COUNT_BIT_16       \
     ,$PFX$_COUNT_BIT_17       \
     ,$PFX$_COUNT_BIT_18       \
     ,$PFX$_COUNT_BIT_19)

#endif

// convert record to either expression or single literal
#ifndef $PFX$_COUNTER_EVAL

  #define $PFX$_COUNTER_EVAL( B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9  \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
    ( (B0  << 0ul ) | \
      (B1  << 1ul ) | \
      (B2  << 2ul ) | \
      (B3  << 3ul ) | \
      (B4  << 4ul ) | \
      (B5  << 5ul ) | \
      (B6  << 6ul ) | \
      (B7  << 7ul ) | \
      (B8  << 8ul ) | \
      (B9  << 9ul ) | \
      (B10 << 10ul) | \
      (B11 << 11ul) | \
      (B12 << 12ul) | \
      (B13 << 13ul) | \
      (B14 << 14ul) | \
      (B15 << 15ul) | \
      (B16 << 16ul) | \
      (B17 << 17ul) | \
      (B18 << 18ul) | \
      (B19 << 19ul) )


  // (two level paster)
  #define $PFX$_COUNTER_DOPB( B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9  \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
      0b ## B19##B18##B17##B16##B15##B14##B13##B12##B11##B10##B9##B8##B7##B6##B5##B4##B3##B2##B1##B0 ## ul

  #define $PFX$_COUNTER_PBIN( B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9  \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
      $PFX$_COUNTER_DOPB(B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9       \
                      , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19)


  #define $PFX$_COUNTER_DOH2(Pfx, H0, H1, H2, H3, H4, Sfx)  \
      Pfx ## H0##H1##H2##H3##H4 ## Sfx
  #define $PFX$_COUNTER_DOPH(Pfx, H0, H1, H2, H3, H4, Sfx)  \
      $PFX$_COUNTER_DOH2(Pfx, H0, H1, H2, H3, H4, Sfx)

  #define $PFX$_COUNTER_GHEX(Pfx, Sfx                                          \
                          , B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9   \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
      $PFX$_COUNTER_DOPH (Pfx                                   \
                       , $PFX$_COUNTER_HEXC(B19, B18, B17, B16) \
                       , $PFX$_COUNTER_HEXC(B15, B14, B13, B12) \
                       , $PFX$_COUNTER_HEXC(B11, B10, B9,  B8 ) \
                       , $PFX$_COUNTER_HEXC(B7,  B6,  B5,  B4 ) \
                       , $PFX$_COUNTER_HEXC(B3,  B2,  B1,  B0 ) \
                       , Sfx)

  #define $PFX$_COUNTER_PHEX( B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9  \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
      $PFX$_COUNTER_GHEX (0x, ul                            \
        ,  B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9 \
        , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19)
  #define $PFX$_COUNTER_DHEX( B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9  \
                          , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19) \
      $PFX$_COUNTER_GHEX (/* empty */, /* empty */                    \
        ,  B0,  B1,  B2,  B3,  B4,  B5,  B6,  B7,  B8,  B9 \
        , B10, B11, B12, B13, B14, B15, B16, B17, B18, B19)

  // generate hex digits from bits
  #define $PFX$_COUNTER_HEXC(B0, B1, B2, B3) $PFX$_COUNTER_HEXC_ ##B0##B1##B2##B3

  #define $PFX$_COUNTER_HEXC_0000 0
  #define $PFX$_COUNTER_HEXC_0001 1
  #define $PFX$_COUNTER_HEXC_0010 2
  #define $PFX$_COUNTER_HEXC_0011 3
  #define $PFX$_COUNTER_HEXC_0100 4
  #define $PFX$_COUNTER_HEXC_0101 5
  #define $PFX$_COUNTER_HEXC_0110 6
  #define $PFX$_COUNTER_HEXC_0111 7
  #define $PFX$_COUNTER_HEXC_1000 8
  #define $PFX$_COUNTER_HEXC_1001 9
  #define $PFX$_COUNTER_HEXC_1010 a
  #define $PFX$_COUNTER_HEXC_1011 b
  #define $PFX$_COUNTER_HEXC_1100 c
  #define $PFX$_COUNTER_HEXC_1101 d
  #define $PFX$_COUNTER_HEXC_1110 e
  #define $PFX$_COUNTER_HEXC_1111 f


  // force expand pass
  #define $PFX$_COUNTER_EXPAND(V) V

  #ifndef $PFX$_COUNTER_PRINT
    // default to hex printer: 0x12345ul
    #define $PFX$_COUNTER_PRINT $PFX$_COUNTER_PHEX
  #endif

  // alt formats also accessible, good for name gen
  #define $PFX$_COUNTER_BIN \
    $PFX$_COUNTER_EXPAND ($PFX$_COUNTER_PBIN $PFX$_COUNTER_RECORD)
  #define $PFX$_COUNTER_HEX \
    $PFX$_COUNTER_EXPAND ($PFX$_COUNTER_PHEX $PFX$_COUNTER_RECORD)
  #define $PFX$_COUNTER_EXPR \
    $PFX$_COUNTER_EXPAND ($PFX$_COUNTER_EVAL $PFX$_COUNTER_RECORD)
  #define $PFX$_COUNTER_HEXDIG \
    $PFX$_COUNTER_EXPAND ($PFX$_COUNTER_DHEX $PFX$_COUNTER_RECORD)

#endif

// unconditional, this forces update even after manual reset
#undef $PFX$_COUNTER
#define $PFX$_COUNTER \
    $PFX$_COUNTER_EXPAND ($PFX$_COUNTER_PRINT $PFX$_COUNTER_RECORD)
