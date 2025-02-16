// Alps64 config.h

/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//#include "config_common.h"      // Generating a compile error - Superceeded by the JSON file?

// USB Device descriptor parameter
#define VENDOR_ID       0x6873    //hs "Hasu"
#define PRODUCT_ID      0x6464    //Alps"64"
#define DEVICE_VER      0x0001
//#define MANUFACTURER    Hasu    // Generating a compile error - Superceeded due to the JSON file?
//#define PRODUCT         Alps64  // Generating a compile error - Superceeded due to the JSON file?

// key matrix size
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define MATRIX_COL_PINS {  B0, B1, B2, B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS {  D0, D1, D2, D3, D4, D5, D6, C2 }
#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW

#define LED_CAPS_LOCK_PIN C5

// Bootmagic Lite Support
#define BOOTMAGIC_LITE_ROW 3
#define BOOTMAGIC_LITE_COLUMN 6

//#define LOCKING_SUPPORT_ENABLE              // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
//#define LOCKING_RESYNC_ENABLE               // Tries to keep switch state consistent with keyboard LED state

// Split Keyboard handedness
// #define EE_HANDS                           // Allows to use either side as the master
// #define MASTER_LEFT

//#define MATRIX_HAS_GHOST                    // Enable if matrix has ghost

#define DEBOUNCE 5                          // Default is 5; set to 0 if debouncing isn't neededneeded

// Feature Options
// These options are useful for reducing the firmware size.
#define NO_ACTION_FUNCTION                  // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER                     // Disable layers
#define NO_ACTION_MACRO                     // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
//#define NO_ACTION_ONESHOT                   // Disable one-shot modifiers
//#define NO_ACTION_TAPPING                   // Disable tap dance and other tapping features
//#define NO_DEBUG                            // Disable debug print - generating a compile error!
//#define NO_PRINT                            // Disable print

#define TAPPING_TERM 195                    // How long before a key press becomes a hold - 150ms to 220ms is common range
#define TAPPING_TERM_PER_KEY                // Permits tapping offsets from the global TAPPING_TERM
#define TAP_CODE_DELAY 10                   // Allows media codes to properly register in macros and rotary encoder code

#define LEADER_TIMEOUT 5000                 // Set time out for the Leader function
//#define LEADER_PER_KEY_TIMING               // Increase the time out, for longer Leader Key sequences

// Caps Word configuration options:
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD              // Vanilla QMK Caps Word, define how caps word is toggled on
#define CAPS_WORD_INVERT_ON_SHIFT                   // Tapping shift allows lower case letters, without breaking a caps word session
#define CAPS_WORD_IDLE_TIMEOUT 5000                 // Caps word toggles off if no activity for five seconds (five seconds is the default timeout)
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD         // Activate Caps Word via touble tapping  1-Shot Shift key, or by double tapping the Left Shift, or the Left Shift one shot mod
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)  // Activate Caps Word by holding both L & R Ctrl keys

// Combination Configuration Options
#define COMBO_VARIABLE_LEN                  // For gboards combo dictionary
#define COMBO_BUFFER_LENGTH 4               // Size of the combo processing buffer
#define COMBO_TERM 60                       // Set the default time for combos; the default is 50ms
#define COMBO_ONLY_FROM_LAYER 0             // Combo positions configured for layer 0 will work in all alternate base layers

// Home-row mod configuration options - Achordion
#define ACHORDION_STREAK                    // For Achordion home row mods
//#define IGNORE_MOD_TAP_INTERRUPT            // Mod Tap keys are no longer treated as a special case
#define PERMISSIVE_HOLD                     // If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its hold action instead
//#define PERMISSIVE_HOLD_PER_KEY             // Configuere PERMISSIVE_HOLD per key
//#define QUICK_TAP_TERM 120                  // For Achordion home row mods
//#define QUICK_TAP_TERM_PER_KEY              // For Achordion home row mods
//#define TAPPING_FORCE_HOLD                  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
//#define TAPPING_FORCE_HOLD_PER_KEY          // Configure TAPPING_Force_HOLD per key

// Repeat / AltRepeat configuraiton options:
//#define NO_ALT_REPEAT_KEY                     // Disable the AltRepeat function, but leave Repeat enabled

//#define UNICODE_SELECTED_MODES UC_LNX       // Set Unicode input mode to Linux mode

// Getreuer's Custom Features:
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT                    // Don't apply custom shift keys when any non-shift mod is held
#define CUSTOM_SHIFT_KEYS_LAYER_MASK (1 << 2) | (1 << 3) | (1 << 4)  // Restrict Custom Shift keys to layers 2, 3 and 4
//#define LAYER_LOCK_IDLE_TIMEOUT 0           // Disable Layer Lock by tapping _Layer key, or if no activity after five minutes. Set the TIMEOUT to 0 and Layer Lock will not time out
#define SENTENCE_CASE_TIMEOUT 5000          // Reset (disable) state after 5 seconds
