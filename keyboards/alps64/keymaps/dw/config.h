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

//#define MATRIX_HAS_GHOST             // define if matrix has ghost

#define DEBOUNCE    5                  // Set 0 if debouncing isn't needed

//#define LOCKING_SUPPORT_ENABLE       // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
//#define LOCKING_RESYNC_ENABLE        // Locking resynchronize hack

// Bootmagic Lite Support
#define BOOTMAGIC_LITE_ROW 3
#define BOOTMAGIC_LITE_COLUMN 6

#define TAPPING_TERM 200               // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold.

#define CAPS_WORD_IDLE_TIMEOUT 5000    // Set the idle timeout for the caps word function to five seconds.

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
