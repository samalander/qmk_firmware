#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Space reduction https://docs.qmk.fm/#/squeezing_avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT

// Tapping Term
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD