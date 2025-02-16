// Clueboard 66 rev2 config.h

#pragma once

#define BACKLIGHT_LEVELS 1               // Backlight configuration

// Underlight configuration
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1
#define RGBLIGHT_EFFECT_BREATHE_MAX 200
#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 666*2
#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 1
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3          // How many LEDs wide to light up
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 1          // The led to start at
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 5         // How many LEDs to travel
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 4           // How many LEDs wide to light up
#define RGBLIGHT_SLEEP                           // Disable illumination when computer is sleeping
//#define RGBLIHT_SPLIT                          // For split ergo boards

//#define LOCKING_SUPPORT_ENABLE       // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
//#define LOCKING_RESYNC_ENABLE        // Tries to keep switch state consistent with keyboard LED state

//#define MATRIX_HAS_GHOST             // define if matrix has ghost

#define DEBOUNCE    5                  // Set 0 if debouncing isn't needed

// Feature disable options
// These options are also useful to firmware size reduction.
#define NO_ACTION_FUNCTION             // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER              // Disable layers
#define NO_ACTION_MACRO                // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
//#define NO_ACTION_ONESHOT            // Disable one-shot modifiers
//#define NO_ACTION_TAPPING            // Disable tap dance and other tapping features
//#define NO_DEBUG                     // Disable debug print
//#define NO_PRINT                     // Disable print

#define TAPPING_TERM 200               // The maximum time allowed between taps of the Auto Shift, Mod TAP, Retro Shift and Tap Dance keys
#define TAPPING_TERM_PER_KEY           // Permits tapping offsets from the global TAPPING_TERM
#define TAP_CODE_DELAY 10              // Allows media codes to properly register in macros and rotary encoder code

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // Define how caps word is toggled on
#define CAPS_WORD_INVERT_ON_SHIFT      // Tapping shift immediately toggles caps word off
#define CAPS_WORD_IDLE_TIMEOUT 3000    // Caps word toggles off if no activity for three seconds

#define LEADER_TIMEOUT 400             // Set time out for the Leader function
//#define LEADER_PER_KEY_TIMING        // The Leader key allows to flexibly assign macros to key sequences

//#define UNICODE_SELECTED_MODES UC_LINX // Set Unicode input mode to Linux mode
#define UNICODE_SELECTED_MODES -1      // A comma separated list of input modes for cycling through; Default is: -1
#define UNICODE_TYPE_DELAY 10          // The amount of time to wait, in milliseconds, between Unicode sequence keystrokes; Default is 10
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))  // The key to tap when beginning a Unicode sequence with the Linux input mode; Default is: LCTL(LSFT(KC_U))

#define TAPPING_TERM 200               // Global: How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold
#define TAPPING_TERM_PER_KEY           // Permits tapping offsets from the global TAPPING_TERM

// Home-row mod configuration options
//#define IGNORE_MOD_TAP_INTERRUPT     // Mod Tap keys are no longer treated as a special case (depricated)
//#define TAPPING_FORCE_HOLD           // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define TAPPING_FORCE_HOLD_PER_KEY     // Configure TAPPING_Force_HOLD per key
#define PERMISSIVE_HOLD                // If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its hold action instead
//#define PERMISSIVE_HOLD_PER_KEY      // Configuere PERMISSIVE_HOLD per key
//#define BILATERAL_COMBINATIONS         // The last mod-tap hold will be converted to the corresponding mod-tap tap if another key on the same hand is tapped during the hold, unless a key on the other hand is tapped first
