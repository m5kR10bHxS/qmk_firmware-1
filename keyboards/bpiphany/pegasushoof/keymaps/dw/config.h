/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

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

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

// Feature disable options
// These options are also useful to firmware size reduction.
//#define NO_DEBUG                     // Disable debug print
//#define NO_PRINT                     // Disable print
#define NO_ACTION_MACRO                // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
#define NO_ACTION_FUNCTION             // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER              // Disable layers
//#define NO_ACTION_TAPPING            // Disable tap dance and other tapping features
//#define NO_ACTION_ONESHOT            // Disable one-shot modifiers

#define CAPS_WORD_IDLE_TIMEOUT 3000    // Set idle timeout for the caps word function to 3 seconds

#define LEADER_TIMEOUT 400             // Set time out for the Leader function

#define UNICODE_SELECTED_MODES UC_LNX  // Set Unicode input mode to Linux mode

#define TAP_CODE_DELAY 10              // Allows media codes to properly register in macros and rotary encoder code

// Home-row mod configuration options
#define TAPPING_TERM 200               // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold.
#define TAPPING_TERM_PER_KEY           // Permits tapping offsets from the global TAPPING_TERM
#define IGNORE_MOD_TAP_INTERRUPT       // Mod Tap keys are no longer treated as a special case
//#define TAPPING_FORCE_HOLD           // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define TAPPING_FORCE_HOLD_PER_KEY     // Configure TAPPING_Force_HOLD per key
#define PERMISSIVE_HOLD                // If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its hold action instead
//#define PERMISSIVE_HOLD_PER_KEY      // Configuere PERMISSIVE_HOLD per key
#define BILATERAL_COMBINATIONS         // The last mod-tap hold will be converted to the corresponding mod-tap tap if another key on the same hand is tapped during the hold, unless a key on the other hand is tapped first
