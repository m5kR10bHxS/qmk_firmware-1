#pragma once

#include "config_common.h"

/* Backlight configuration
 */
#define BACKLIGHT_LEVELS 1

/* Underlight configuration
 */
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1
#define RGBLIGHT_EFFECT_BREATHE_MAX 200
#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 666*2
#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 1
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3   // How many LEDs wide to light up
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 1   // The led to start at
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 5  // How many LEDs to travel
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 4    // How many LEDs wide to light up

//#define MATRIX_HAS_GHOST             // define if matrix has ghost

#define DEBOUNCE    5                  // Set 0 if debouncing isn't needed

//#define LOCKING_SUPPORT_ENABLE       // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
//#define LOCKING_RESYNC_ENABLE        // Locking resynchronize hack

#define TAPPING_TERM 200               // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold.

#define CAPS_WORD_IDLE_TIMEOUT 3000    // Set the idle timeout for the caps word function to three seconds.

#define UNICODE_SELECTED_MODES UC_LNX  // Set the Unicode input mode to the Linux OS character input sequence.

// Feature disable options
// These options are also useful to firmware size reduction.
//#define NO_DEBUG                  // Disable debug print
//#define NO_PRINT                  // Disable print
#define NO_ACTION_MACRO           // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
#define NO_ACTION_FUNCTION        // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER           // Disable layers
//#define NO_ACTION_TAPPING         // Disable tap dance and other tapping features
//#define NO_ACTION_ONESHOT         // Disable one-shot modifiers
