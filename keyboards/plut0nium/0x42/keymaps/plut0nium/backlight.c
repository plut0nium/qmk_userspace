#include "quantum.h"

#ifdef LED_MATRIX_ENABLE
//#include "is31fl3731-simple.h"

const is31_led g_is31_leds[LED_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  LED address
 *   |  | */
    {0, C7_1},   // K00 *** Row 0 ***
    {0, C6_1},   // K01
    {0, C5_1},   // K02
    {0, C4_1},   // K03
    {0, C3_1},   // K04
    {0, C2_1},   // K05
    {0, C1_1},   // K06
    {0, C1_9},   // K07
    {0, C2_9},   // K08
    {0, C3_9},   // K09
    {0, C4_9},   // K0A
    {0, C5_9},   // K0B
    {0, C6_9},   // K0C
    {0, C7_9},   // K0D
    {0, C7_2},   // K10 *** Row 1 ***
    {0, C6_2},   // K11
    {0, C5_2},   // K12
    {0, C4_2},   // K13
    {0, C3_2},   // K14
    {0, C2_2},   // K15
    {0, C1_2},   // K16
    {0, C1_10},  // K17
    {0, C2_10},  // K18
    {0, C3_10},  // K19
    {0, C4_10},  // K1A
    {0, C5_10},  // K1B
    {0, C6_10},  // K1C
    {0, C7_10},  // K1D
    {0, C7_3},   // K20 *** Row 2 ***
    {0, C6_3},   // K21
    {0, C5_3},   // K22
    {0, C4_3},   // K23
    {0, C3_3},   // K24
    {0, C2_3},   // K25
    // {0, C1_3},   // K26
    // {0, C1_11},  // K27
    {0, C2_11},  // K28
    {0, C3_11},  // K29
    {0, C4_11},  // K2A
    {0, C5_11},  // K2B
    {0, C6_11},  // K2C
    {0, C7_11},  // K2D
    {0, C7_4},   // K30 *** Row 3 ***
    {0, C6_4},   // K31
    {0, C5_4},   // K32
    {0, C4_4},   // K33
    {0, C3_4},   // K34
    {0, C2_4},   // K35
    {0, C1_4},   // K36
    {0, C1_12},  // K37
    {0, C2_12},  // K38
    {0, C3_12},  // K39
    {0, C4_12},  // K3A
    {0, C5_12},  // K3B
    {0, C6_12},  // K3C
    {0, C7_12},  // K3D
//    {0, C7_5},   // K40 *** Row 4 ***     > HHKB
//    {0, C6_5},   // K41                   > Encoder
    {0, C5_5},   // K42
    {0, C4_5},   // K43
    {0, C3_5},   // K44
    {0, C2_5},   // K45
//    {0, C1_5},   // K46                   > 2u Split spacebar
//    {0, C1_13},  // K47                   > 2u Split spacebar
    {0, C2_13},  // K48
    {0, C3_13},  // K49
    {0, C4_13},  // K4A
    {0, C5_13},  // K4B
    {0, C6_13},  // K4C
//    {0, C7_13},  // K4D                   > HHKB
};

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13 },
        {  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27 },
        {  28,  29,  30,  31,  32,  33,  NO_LED, NO_LED, 34,  35,  36,  37,  38,  39 },
        {  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53 },
        { NO_LED, NO_LED, 54,  55, 56,  57, NO_LED, NO_LED,  58,  59,  60,  61,  62, NO_LED }
    }, {
        // LED Index to Physical Position
        {   0,   0}, {  24,   0}, {  40,   0}, {  56,   0}, {  72,   0}, {  88,   0}, { 104,   0}, { 120,   0}, { 136,   0}, { 152,   0}, { 168,   0}, { 184,   0}, { 200,   0}, { 224,   0},
        {   0,  16}, {  24,  16}, {  40,  16}, {  56,  16}, {  72,  16}, {  88,  16}, { 104,  16}, { 120,  16}, { 136,  16}, { 152,  16}, { 168,  16}, { 184,  16}, { 200,  16}, { 224,  16},
        {   0,  32}, {  24,  32}, {  40,  32}, {  56,  32}, {  72,  32}, {  88,  32},                           { 136,  32}, { 152,  32}, { 168,  32}, { 184,  32}, { 200,  32}, { 224,  32},
        {   0,  48}, {  24,  48}, {  40,  48}, {  56,  48}, {  72,  48}, {  88,  48}, { 104,  48}, { 120,  48}, { 136,  48}, { 152,  48}, { 168,  48}, { 184,  48}, { 200,  48}, { 224,  48},
                                  {  40,  64}, {  56,  64}, {  72,  64},        {  96,  64},             { 128,  64},        { 152,  64}, { 168,  64}, { 184,  64}, { 200,  64},
    }, {
        // LED Index to Flag
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        1, 4, 4, 4, 4, 4,       4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
              1, 1, 1,   1,   1,   1, 1, 1, 1,
    }
};
#endif // LED_MATRIX_ENABLE