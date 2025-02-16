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

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0x6873 //hs "Hasu"
#define PRODUCT_ID      0x6464 //Alps"64"
#define DEVICE_VER      0x0001
#define MANUFACTURER    Hasu
#define PRODUCT         Alps64

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

//#define LOCKING_SUPPORT_ENABLE       // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
//#define LOCKING_RESYNC_ENABLE        // Tries to keep switch state consistent with keyboard LED state

//#define MATRIX_HAS_GHOST             // Enable if matrix has ghost

#define DEBOUNCE    5                  // Default is 5; set to 0 if debouncing isn't needed

// Feature Options
// These options are useful for reducing the firmware size.
#define NO_ACTION_FUNCTION             // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER              // Disable layers
#define NO_ACTION_MACRO                // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
//#define NO_ACTION_ONESHOT            // Disable one-shot modifiers
//#define NO_ACTION_TAPPING            // Disable tap dance and other tapping features
#define NO_DEBUG                       // Disable debug print
//#define NO_PRINT                     // Disable print

#define TAPPING_TERM 200               // How long before a key press becomes a hold
#define TAPPING_TERM_PER_KEY           // Permits tapping offsets from the global TAPPING_TERM
#define TAP_CODE_DELAY 10              // Allows media codes to properly register in macros and rotary encoder code

#define LEADER_TIMEOUT 400             // Set time out for the Leader function
//#define LEADER_PER_KEY_TIMING        // The Leader key allows to flexibly assign macros to key sequences

#define UNICODE_SELECTED_MODES UC_LNX  // Set Unicode input mode to Linux mode

// Combination Configuration Options
#define COMBO_MUST_HOLD_MODS           // Controls if a given combo should fire immediately on tap or if it needs to be held. (default: false)
#define COMBO_HOLD_TERM 150

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // Define how caps word is toggled on
#define CAPS_WORD_INVERT_ON_SHIFT      // Tapping shift immediately toggles caps word off
#define CAPS_WORD_IDLE_TIMEOUT 3000    // Caps word toggles off if no activity for three seconds

// Home-row mod configuration options
#define IGNORE_MOD_TAP_INTERRUPT       // Mod Tap keys are no longer treated as a special case
//#define TAPPING_FORCE_HOLD           // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define TAPPING_FORCE_HOLD_PER_KEY     // Configure TAPPING_Force_HOLD per key
#define PERMISSIVE_HOLD                // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM
//#define PERMISSIVE_HOLD_PER_KEY      // Configuere PERMISSIVE_HOLD per key
//#define BILATERAL_COMBINATIONS       // The last mod-tap hold will be converted to the corresponding mod-tap tap if another key on the same hand is tapped during the hold, unless a key on the other hand is tapped first
