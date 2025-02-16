// Kyria config.h

/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
    #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DEFAULT_ON true               // Enable RGB lighting upon clearing the EEPROM
//  #define RGBLIGHT_DEFAULT_MODE                  // Configure default RGW mode when EEPROM is cleared
//  #define RGBLIGHT_LAYER_BLINK                   // Enable blinking backlight status "messages"
//  #define RGBLIGHT_LAYERS                        // Up to eight layers are availabl by default
    #define RGBLIGHT_SPLIT                         // If defined, synchronization functionality for split keyboards is added
    #define RGBLIGHT_SLEEP                         // If defined, the RGB lighting will be switched off when the host goes to sleep
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 255
//    #define RGBLIGHT_SETHSV_NOEEPROM(HSV_PURPLE)
    +#undef RGBLIGHT_EFFECT_ALTERNATING
    +#undef RGBLIGHT_EFFECT_BREATHING
    +#undef RGBLIGHT_EFFECT_CHRISTMAS
    +#undef RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD           // Enable rainbow mood animation mode.
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL          // Enable rainbow swirl animation mode.
    +#undef RGBLIGHT_EFFECT_RGB_TEST
    +#undef RGBLIGHT_EFFECT_SNAKE
    +#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    +#undef RGBLIGHT_EFFECT_TWINKLE
#endif

#define ENCODERS_PAD_A { C6 }               // ID MCU pins used by rotary encoder
#define ENCODERS_PAD_B { B5 }               // ID MCU pins used by rotary encoder

/*
 * EC11K encoders have a different resolution than other EC11 encoders.
 * When using the default resolution of 4, if you notice your encoder skipping
 * every other tick, lower the resolution to 2.
 */

#define ENCODER_RESOLUTION 2

// Split Keyboard handedness
//#define EE_HANDS                            // Allows to use either side as the master
#define MASTER_LEFT                         // The left hand board will be master

//#define MATRIX_HAS_GHOST                    // define if matrix has ghost

#define DEBOUNCE    5                       // Set 0 if debouncing isn't needed

// Feature disable options
// These options are also useful to firmware size reduction.
#define NO_ACTION_FUNCTION                  // Disable old-style function handling using fn_actions, action_function() (deprecated)
//#define NO_ACTION_LAYER                     // Disable layers
#define NO_ACTION_MACRO                     // Disable old-style macro handling using MACRO(), action_get_macro() (deprecated)
//#define NO_ACTION_ONESHOT                   // Disable one-shot modifiers
//#define NO_ACTION_TAPPING                   // Disable tap dance and other tapping features
//#define NO_DEBUG                            // Disable debug print - generating a compile error!
//#define NO_PRINT                            // Disable print

#define TAPPING_TERM 195                    // Global: The maximum time allowed between taps of the Auto Shift, Mod TAP, Retro Shift and Tap Dance keys
#define TAPPING_TERM_PER_KEY                // Permits tapping offsets from the global TAPPING_TERM
#define TAP_CODE_DELAY 10                   // Allows media codes to properly register in macros and rotary encoder code

#define LEADER_TIMEOUT 5000                 // Set time out for the Leader function
//#define LEADER_PER_KEY_TIMING               // The Leader key allows to flexibly assign macros to key sequences

// Caps Word configuration options:
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD              // Vanilla QMK Caps Word, define how caps word is toggled on
#define CAPS_WORD_INVERT_ON_SHIFT                   // Tapping shift allows lower case letters, without breaking a caps word session
#define CAPS_WORD_IDLE_TIMEOUT 5000                 // Caps word toggles off if no activity for five seconds (five seconds is the default timeout)
//#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD         // Activate Caps Word via touble tapping  1-Shot Shift key, or by double tapping the Left Shift, or the Left Shift one shot mod
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)  // Activate Caps Word by holding both L & R Ctrl keys

// Combination Configuration Options
#define COMBO_VARIABLE_LEN                  // For gboards combo dictionary
#define COMBO_BUFFER_LENGTH 4               // Size of the combo processing buffer
#define COMBO_TERM 60                       // Set the default time for combos; the default is 50ms
#define COMBO_ONLY_FROM_LAYER 0             // Combo positions configured for layer 0 will work in all alternate base layers

// Home row mod configuration options - QMK
//#define QUICK_TAP_TERM 0                    // Configure the QUICK_TAP_TERM
//#define QUICK_TAP_TERM_PER_KEY              // Configure the QUICK_TAP_TERM_PER_KEY
//#define PERMISSIVE_HOLD                     // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM
//#define PERMISSIVE_HOLD_PER_KEY             // Configuere PERMISSIVE_HOLD per key
//#define TAPPING_FORCE_HOLD                  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
//#define TAPPING_FORCE_HOLD_PER_KEY          // Configure TAPPING_Force_HOLD per key

// Home-row mod configuration options - Achordion
#define ACHORDION_STREAK                    // For Achordion home row mods
//#define IGNORE_MOD_TAP_INTERRUPT            // Mod Tap keys are no longer treated as a special case
#define PERMISSIVE_HOLD                     // If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its hold action instead
//#define PERMISSIVE_HOLD_PER_KEY             // Configuere PERMISSIVE_HOLD per key
#define QUICK_TAP_TERM 120                  // For Achordion home row mods
//#define QUICK_TAP_TERM_PER_KEY              // For Achordion home row mods
//#define TAPPING_FORCE_HOLD                  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
//#define TAPPING_FORCE_HOLD_PER_KEY          // Configure TAPPING_Force_HOLD per key

// Home-row mod configuration options - Bilateral Combinations
//#define BILATERAL_COMBINATIONS              // The last mod-tap hold will be converted to the corresponding mod-tap tap if another key on the same hand is tapped during the hold, unless a key on the other hand is tapped first
//#define IGNORE_MOD_TAP_INTERRUPT            // Mod Tap keys are no longer treated as a special case
//#define PERMISSIVE_HOLD                     // If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its hold action instead
//#define PERMISSIVE_HOLD_PER_KEY             // Configuere PERMISSIVE_HOLD per key
//#define TAPPING_FORCE_HOLD                  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
//#define TAPPING_FORCE_HOLD_PER_KEY          // Configure TAPPING_Force_HOLD per key

// Repeat / AltRepeat configuraiton options:
//#define NO_ALT_REPEAT_KEY                     // Disable the AltRepeat function, but leave Repeat enabled

//#define UNICODE_SELECTED_MODES UC_LNX       // Set Unicode input mode to Linux mode

// Third party features:
// Getreuer Layer Lock:
//#define LAYER_LOCK_IDLE_TIMEOUT 0           // Disable Layer Lock by tapping _Layer key, or if no activity after five minutes. Set the TIMEOUT to 0 and Layer Lock will not time out

// Getreuer Custom Shift Keys:
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT                    // Don't apply custom shift keys when any non-shift mod is held
#define CUSTOM_SHIFT_KEYS_LAYER_MASK (1 << 2) | (1 << 3) | (1 << 4)  // Restrict Custom Shift keys to layers 2, 3 and 4

// Getreuer Sentence Case
#define SENTENCE_CASE_TIMEOUT 5000          // Reset (disable) state after 5 seconds
