// Alps64

/*
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

// Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

// If the following features are enabled in rules.mk, then include them in the keymap:
#include "features/achordion.h"  // Enable Getreuer's Achordion for home row mods
#include "g/keymap_combo.h"  // Enable Germ's gboards combo dictionary, see combos.def file: http://combos.gboards.ca/
#include "features/custom_shift_keys.h"  // Enable Getreuer's Custom Shift Keys: https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
// #include "features/layer_lock.h"  // Enable Getreuer's Layer Lock: https://getreuer.info/posts/keyboards/layer-lock/index.html
#include "features/sentence_case.h"  // Enable Getreuer's Sentence Case: https://getreuer.info/posts/keyboards/sentence-case/index.html


// Enable the timer for one-key copy/paste function:
uint16_t copy_paste_timer;


// Layer definitions:
#define _QWERTY   0  // QWERTY base layer
#define _WORKMAN  1  // Workman alternate base
#define _TITANIUM 2  // HD Titanium alternate base
#define _NAV      3  // Navigation layer
#define _NUM      4  // Number & Function layer
#define _CFG      5  // Configuration layer


// Alias definitions for Workman home row mods w/ 1-shot Shift. Note: Some are redundant w/ Titanium:
#define H_ALT  LALT_T(KC_H)  // Tap for H, hold for left Alt
#define N_CTL  RCTL_T(KC_N)  // Tap for N, hold for right Ctrl
#define O_GUI  RGUI_T(KC_O)  // Tap for O, hold for right GUI


// Alias definitions for Titanium home row mods w/ 1-shot Shift:
#define S_GUI  LGUI_T(KC_S)  // Tap for S, hold for left GUI
#define N_ALT  LALT_T(KC_N)  // Tap for N, hold for left Alt
#define T_CTL  LCTL_T(KC_T)  // Tap for T, hold for left Ctrl
#define A_CTL  RCTL_T(KC_A)  // Tap for A, hold for right Ctrl
#define E_ALT  RALT_T(KC_E)  // Tap for E, hold for right Alt
#define I_GUI  RGUI_T(KC_I)  // Tap for I, hold for right GUI


// Miscellaneous Alias definitions:
#define SFT_1ST  OSM(MOD_LSFT)       // One-shot Shift
#define SPC_NAV  LT(_NAV, KC_SPACE)  // Tap for space Hold for the _NAV layer
#define TAB_BK   RCS(KC_T)           // Recover closed browser tab
#define WIN_BK   RCS(KC_N)           // Recover closed browser window


// Tap / Hold - via the Mod Tap function:
#define TH_1     LT(0, KC_1)     // TH = (Tap / Hold) keys
#define TH_2     LT(0, KC_2)     // Tapped, they produce the numbers 1 through 9
#define TH_3     LT(0, KC_3)     // Held, they produce the equivalent number F-Key
#define TH_4     LT(0, KC_4)     // Shifted (1 through 7), they produce the equivalent number Linux TTY terminal.
#define TH_5     LT(0, KC_5)
#define TH_6     LT(0, KC_6)
#define TH_7     LT(0, KC_7)
#define TH_8     LT(0, KC_8)
#define TH_9     LT(0, KC_9)
#define THORN    LT(0, KC_K)     // Test - Can K be used as a Th key, while honoring case?
#define TTY1     LCA(KC_F1)
#define TTY2     LCA(KC_F2)
#define TTY3     LCA(KC_F3)
#define TTY4     LCA(KC_F4)
#define TTY5     LCA(KC_F5)
#define TTY6     LCA(KC_F6)
#define TTY7     LCA(KC_F7)


// Define custom key codes:
enum my_keycodes {
    CC_CCCV = SAFE_RANGE,  // One key copy & paste
    CPY_PST,  // Simple one key copy & paste
    CC_QRTY,  // QWERTY base layer
    CC_TITN,  // Titanium alternate base layer
    CC_WKMN,  // Workman alternate base layer
//    THORN    // th Th
};


// Getreuer's Custom Shift Keys
const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMM, KC_SCLN},  // Shift , is ;
    {KC_DOT,  KC_COLN},  // Shift . is :
    {KC_DQUO, KC_EXLM},  // Shift " is !
    {KC_HOME, KC_END},   // Shift Home is End
    {KC_LABK, KC_RABK},  // Shift < is >
    {KC_MINS, KC_PLUS},  // Shift - is +
    {KC_MPLY, KC_MNXT},  // Shift MPLY is Next
    {KC_QUOT, KC_QUES},  // Shift ' is ?
    {KC_SLSH, KC_ASTR},  // Shift / is *
    {KC_TILD, KC_PIPE},  // Shift ~ is |
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Base Layer: _QWERTY
    * ,-----------------------------------------------------------------------------------------.
    * |GESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
    * |-----------------------------------------------------------------------------------------+
    * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Bk Spc |
    * |-----------------------------------------------------------------------------------------+
    * | Cap Lk  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Shift   |Pg Dn |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  |  GUI  |  Alt  |           Space                 |  Alt  | _NAV  | _NUM  | _CFG  |
    * `-----------------------------------------------------------------------------------------'
    */
  [_QWERTY] = LAYOUT_infinity( \
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN,                   \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPACE,                                    KC_LALT, TG(_NAV), TG(_NUM), TG(_CFG)
  ),

   /* Alternate Base Layer: _WORKMAN
    * ,-----------------------------------------------------------------------------------------.
    * |GESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
    * |-----------------------------------------------------------------------------------------+
    * |  Tab   |  Q  |  D  |  R  |  W  |  B  |  J  |  F  |  U  |  P  |  ;  |   [ |  ]  | Bk Spc |
    * |-----------------------------------------------------------------------------------------+
    * | Bk Spc  |  A  |gui S|alt H|ctl T|  G  |  Y  |ctl N|alt E|gui O|  I  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * |   Shift   |  Z  |  X  |  M  |  C  |  V  |  K  |  L  |  ,  |  .  |  /  |  Shift   |Pg Dn |
    * |-----------------------------------------------------------------------------------------+
    * |Repeat |       |       |           Space Fn _NAV         |1-Shift|Leader | _NUM  |AltRep |
    * `-----------------------------------------------------------------------------------------'
    */
  [_WORKMAN] = LAYOUT_infinity( \
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,          \
    KC_BSPC, KC_A,    S_GUI,   H_ALT,   T_CTL,   KC_G,    KC_Y,    N_CTL,   E_ALT,   O_GUI,   KC_I,    KC_QUOT, KC_ENT,                    \
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN,                   \
    QK_REP,  XXXXXXX, XXXXXXX,                   SPC_NAV,                                     SFT_1ST, QK_LEAD, TG(_NUM), QK_AREP
  ),

   /* Alternate Base Layer: _TITANIUM
    * ,-----------------------------------------------------------------------------------------.
    * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | F11 | F12 |     |     |
    * |-----------------------------------------------------------------------------------------+
    * |        | J Z | G Q |  M  |  P  |  V  | ~ | | . : | / * | " ? | ' ! |     |     |        |
    * |-----------------------------------------------------------------------------------------+
    * |         |  C  |gui S|alt N|ctl T|  K  | , ; |ctl A|alt E|gui I|  H  |     |             |
    * |-----------------------------------------------------------------------------------------+
    * |           | X  |  F  |  L  |  D  |  W  | - + |  U  |  O  |  Y  |  B  |           |Pg Dn |
    * |-----------------------------------------------------------------------------------------+
    * |Repeat |       |   R   |           Space Fn _NAV         |1-Shift|Leader | _NUM  |AltRep |
    * `-----------------------------------------------------------------------------------------'
    */
  [_TITANIUM] = LAYOUT_infinity( \
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_J,    KC_G,    KC_M,    KC_P,    KC_V,    KC_TILD, KC_DOT,  KC_SLSH, KC_DQUO, KC_QUOT, XXXXXXX, XXXXXXX, XXXXXXX,          \
    XXXXXXX, KC_C,    S_GUI,   N_ALT,   T_CTL,   KC_K,    KC_COMM, A_CTL,   E_ALT,   I_GUI,   KC_H,    XXXXXXX, XXXXXXX,                   \
    XXXXXXX, KC_X,    KC_F,    KC_L,    KC_D,    KC_W,    KC_MINS, KC_U,    KC_O,    KC_Y,    KC_B,    XXXXXXX, KC_PGDN,                   \
    QK_REP,  XXXXXXX, KC_R,                      SPC_NAV,                                     SFT_1ST, QK_LEAD, TG(_NUM), QK_AREP
  ),

   /* Navigation Layer: _NAV
    * ,-----------------------------------------------------------------------------------------.
    * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
    * |-----------------------------------------------------------------------------------------+
    * |        |CpsLk|     |WinBK|TabBK|CpPst|     |PG Up| UP  |Home |Vol+ |     |     |        |
    * |-----------------------------------------------------------------------------------------+
    * |         |     | GUI | Alt |Ctrl |CCCV | App |Left | DN  |Right|MPLY |     |             |
    * |-----------------------------------------------------------------------------------------+
    * |           | \   |  @  |  &  |  _  |PtScn|Menu |Pg Dn|Insrt| End |Vol- |          |Pg Up |
    * |-----------------------------------------------------------------------------------------+
    * |Repeat |       |       |                                 |1-Shift|Leader |       |AltRep |
    * `-----------------------------------------------------------------------------------------'
    */
  [_NAV] = LAYOUT_infinity( \
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_CAPS, XXXXXXX, WIN_BK,  TAB_BK,  CPY_PST, XXXXXXX, KC_PGUP, KC_UP,   KC_HOME, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,          \
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, CC_CCCV, KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX, XXXXXXX,                   \
    XXXXXXX, KC_BSLS, KC_AT,   KC_AMPR, KC_UNDS, KC_PSCR, KC_MENU, KC_PGDN, KC_INS,  KC_END,  KC_VOLD, XXXXXXX, KC_PGUP,                   \
    QK_REP,  XXXXXXX, XXXXXXX,                   _______,                                              SFT_1ST, QK_LEAD, XXXXXXX, QK_AREP
  ),

   /* Function Layer: _NUM
    * ,-----------------------------------------------------------------------------------------.
    * |     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | F11 | F12 |     |     |
    * |-----------------------------------------------------------------------------------------+
    * |        |     |     |     |     | < > | / * |  7  |  8  |  9  | F10 |     |     |        |
    * |-----------------------------------------------------------------------------------------+
    * |         |     | GUI | Alt |Ctrl | . : |  0  |  1  |  2  |  3  | F11 |     |             |
    * |-----------------------------------------------------------------------------------------+
    * |           |  #  |  $  |  %  |  ^  |  =  | - + |  4  |  5  |  6  | F12 |           |Pg Up|
    * |-----------------------------------------------------------------------------------------+
    * |Repeat |       |       |                 Space           |1-Shift|Leader  | _NUM | _CFG  |
    * `-----------------------------------------------------------------------------------------'
    */
  [_NUM] = LAYOUT_infinity( \
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_SLSH, TH_7,    TH_8,    TH_9,    KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX,          \
    XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_DOT,  KC_0,    TH_1,    TH_2,    TH_3,    KC_F11,  XXXXXXX, XXXXXXX,                   \
    XXXXXXX, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_MINS, TH_4,    TH_5,    TH_6,    KC_F12,  XXXXXXX, KC_PGUP,                   \
    QK_AREP, XXXXXXX, XXXXXXX,                   KC_SPACE,                                             SFT_1ST, QK_LEAD, _______, TG(_CFG)
  ),

   /* Configuration Layer: _CFG
    * ,-----------------------------------------------------------------------------------------.
    * |Flash|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------------------------+
    * |        |     |     |     |Qwrty|     |     |OnOff|Hue+ |Sat+ |Spd+ |Brt+ |     |        |
    * |-----------------------------------------------------------------------------------------+
    * |         |Dt Up|Dt Dn|Dt Pt|Wrkmn|     |     |Mode |Hue- |Sat- |Spd- |Brt- |             |
    * |-----------------------------------------------------------------------------------------+
    * |           |     |     |     |HD Ti|     |     |     |     |     |     |           |     |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                 |       |       |       | _CFG  |
    * `-----------------------------------------------------------------------------------------'
    */
  [_CFG] = LAYOUT_infinity( \
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CC_QRTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          \
    XXXXXXX, DT_UP,   DT_DOWN, DT_PRNT, CC_WKMN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CC_TITN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   \
    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, _______
    // DT keycodes adjust the dynamic tapping term by 5ms - Note: This offset is not persistent
  )

   /* Combos
    * ,-----------------------------------------------------------------------------------------.
    * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------------------------+
    * |        |     |Lead | Esc | Esc |Bksp |Bksp | Tab | Tab |Lead |     |     |     |        |
    * |-----------------------------------------------------------------------------------------+
    * |         |     |     |     |CapsW| Ent | Ent |CapsW|     |     |     |     |             |
    * |-----------------------------------------------------------------------------------------+
    * |           |     |     |Ctl Q|Ctl Q| Del | Del |Ctl Z|Ctl Z|  .  |     |          |      |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                 |       |       |       |       |
    * `-----------------------------------------------------------------------------------------'
    */
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {  // Offset from tapping_term for home row mods
    switch (keycode) {
        case LALT_T(KC_H):  // Workman
            return TAPPING_TERM + 20;
        case RCTL_T(KC_N):  // Workman
            return TAPPING_TERM + 20;
        case RGUI_T(KC_O):  // Workman
            return TAPPING_TERM + 20;
        case LGUI_T(KC_S):  // Ti
            return TAPPING_TERM + 20;
        case RALT_T(KC_N):  // Ti
            return TAPPING_TERM + 20;
        case LCTL_T(KC_T):  // Ti
            return TAPPING_TERM + 20;
        case RCTL_T(KC_A):  // Ti
            return TAPPING_TERM + 20;
        case RALT_T(KC_E):  // Ti
            return TAPPING_TERM + 20;
        case RGUI_T(KC_I):  // Ti
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}


static bool process_tap_or_long_press_key(  // Handle calls to the Tap / Long Press function - The long press key code is repeated
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      register_code16(long_press_keycode);
    } else {
      unregister_code16(long_press_keycode);
    }
    return false;  // Skip default handling
  }
  return true;  // Continue default handling
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {  // Handle calls to process_record_user
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    if (!process_achordion(keycode, record)) {  // Detect calls to Achordion home row mods
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) {  // Detect calls to Custom Shift keys
        return false;
    }
    if (!process_sentence_case(keycode, record)) {  // Detect calls to Sentence Case
        return false;
    }
    if (get_mods() == MOD_MASK_CTRL) {
        caps_word_on();
        return true;
    }
    switch (keycode) {  // Detect calls to custom keycodes
        case CC_CCCV:   // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(LCTL(KC_C));  // Hold to copy
                } else {
                    tap_code16(LCTL(KC_V));  // Tap to paste
                }
            }
            return false;
            break;
        case CC_QRTY:   // Toggle to the QWERTY alternate base layer
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case CC_TITN:   // Toggle to the HD-Titanium alternate base layer
            if (record->event.pressed) {
                set_single_persistent_default_layer(_TITANIUM);
            }
            return false;
            break;
        case CC_WKMN:   // Toggle to the WORKMAN alternate base layer
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
            break;
        case TH_1:  // KC_1 on tap, KC_F1 on long press
            return process_tap_or_long_press_key(record, (KC_F1));
        case TH_2:  // KC_2 on tap, KC_F2 on long press
            return process_tap_or_long_press_key(record, (KC_F2));
        case TH_3:  // KC_3 on tap, KC_F3 on long press
            return process_tap_or_long_press_key(record, (KC_F3));
        case TH_4:  // KC_4 on tap, KC_F4 on long press
            return process_tap_or_long_press_key(record, (KC_F4));
        case TH_5:  // KC_5 on tap, KC_F5 on long press
            return process_tap_or_long_press_key(record, (KC_F5));
        case TH_6:  // KC_6 on tap, KC_F6 on long press
            return process_tap_or_long_press_key(record, (KC_F6));
        case TH_7:  // KC_7 on tap, KC_F7 on long press
            return process_tap_or_long_press_key(record, (KC_F7));
        case TH_8:  // KC_8 on tap, KC_F8 on long press
            return process_tap_or_long_press_key(record, (KC_F8));
        case TH_9:  // KC_9 on tap, KC_F9 on long press
            return process_tap_or_long_press_key(record, (KC_F9));
        case TH_B:  // KC_B on tap, KC_PIPE on long press
            return process_tap_or_long_press_key(record, (KC_PIPE));
        case KC_F:  // KC_F on tap, KC_Q on long press
            if (record->event.pressed) {
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Was Shift held?
                    del_oneshot_mods(MOD_MASK_SHIFT);  // Thmporarily delete the Shift mod
                    unregister_mods(MOD_MASK_SHIFT);
                    SEND_STRING("Q");
                    register_mods(mods); // Re-enable the Shift mod status
                } else {
                    SEND_STRING("q");
                }
            }
            return false;
            break;
        case KC_K:  // KC_K on tap, Thorn on long press
            if (record->event.pressed) {
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Was Shift held?
                    del_oneshot_mods(MOD_MASK_SHIFT);  // Thmporarily delete the Shift mod
                    unregister_mods(MOD_MASK_SHIFT);
                    SEND_STRING("Th");
                    register_mods(mods); // Re-enable the Shift mod status
                } else {
                    SEND_STRING("th");
                }
            }
            return false;
            break;
        case KC_X:  // KC_X on tap, KC_Z on long press
            if (record->event.pressed) {
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Was Shift held?
                    del_oneshot_mods(MOD_MASK_SHIFT);  // Thmporarily delete the Shift mod
                    unregister_mods(MOD_MASK_SHIFT);
                    SEND_STRING("Z");
                    register_mods(mods); // Re-enable the Shift mod status
                } else {
                    SEND_STRING("z");
                }
            }
            return false;
            break;
    }
    return true;
}


void matrix_scan_user(void) {  // Handle calls to matrix_scan_user
    achordion_task();      // Achordion home row mods
    sentence_case_task();  // Sentence Case
}

/*
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {  // Home row mods:
    switch (keycode) {
        case H_ALT:  // Workman - List keys that should not repeat (home row mods and tap/hold key codes)
        case N_CTL:  // Workman
        case O_GUI:  // Workman
        case S_GUI:  // Titanium
        case N_ALT:  // Titanium
        case T_CTL:  // Titanium
        case A_CTL:  // Titanium
        case E_ALT:  // Titanium
        case I_GUI:  // Titanium
        return true;
    default:         // Keys are permitted to repeat (default action)
        return false;
    }
}
*/

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {  // Alt Repeat dictionary
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    switch (keycode) {
        case KC_G:
            if (shifted) {
                SEND_STRING(SS_TAP(X_BSPC)"Qu"); return KC_NO;  // Erase the G and send an upper case Qu.
            } else {                                            // Otherwise, the last key was lower case g,
                SEND_STRING(SS_TAP(X_BSPC)"qu"); return KC_NO;  // Erase the g and send a lower case qu.
            }
        case KC_J:
            if (shifted) {
                SEND_STRING(SS_TAP(X_BSPC)"Z"); return KC_NO;  // Erase the J and send an upper case Z.
            } else {                                           // Otherwise, the last key was lower case j,
                SEND_STRING(SS_TAP(X_BSPC)"z"); return KC_NO;  // Erase the j and send a lower case z.
            }
        }
    return KC_TRNS;  // Defer to default definitions
    if (mods & MOD_MASK_CTRL) {  // Was Ctrl held?
        switch (keycode) {
            case KC_G:    return C(KC_Q);  // Ctrl + G reverses to Ctrl + Q - Also have combo!
            case KC_J:    return C(KC_Z);  // Ctrl + J reverses to Ctrl + Z - Also have combo!
            case KC_EQL:  return C(KC_0);  // Ctrl + = reverses to Ctrl + 0
            case KC_MINS: return C(KC_0);  // Ctrl + - reverses to Ctrl + 0
        }
    }
    return KC_TRNS;  // Defer to default definitions
    switch (keycode) {
        case KC_A:  return KC_N;  // For "An" bigram
        case KC_C:  return KC_E;  // For "Ce" bigram
        case KC_D:  return KC_E;  // For "De" bigram
        case KC_E:  return KC_R;  // For "Er" bigram
        case KC_H:  return KC_E;  // For "He" bigram
        case KC_I:  return KC_N;  // For "In" bigram
        case KC_L:  return KC_O;  // For "Lo" bigram
        case KC_O:  return KC_N;  // For "On" bigram
        case KC_R:  return KC_E;  // For "Re" bigram
        case KC_T:  return KC_H;  // For "Th" bigram
        case KC_U:  return KC_N;  // For "Un" bigram
    }
    return KC_TRNS;  // Defer to default definitions
}


void leader_end_user(void) {  // https://docs.qmk.fm/ChangeLog/20230226#leader-key-rework
    if (leader_sequence_one_key(KC_A)) {  // Send a set of Angle brackets:
            SEND_STRING("<>" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_one_key(KC_B)) {  // Send a comment Block:
            SEND_STRING("/*\n\n*/" SS_TAP(X_LEFT)); tap_code(KC_LEFT); tap_code(KC_LEFT);
    }
    else if (leader_sequence_one_key(KC_C)) {  // Send a set of Curly brackets:
            SEND_STRING("{}" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_one_key(KC_D)) {  // Send a set of Double quotes:
            SEND_STRING("\"\"" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_one_key(KC_H)) {  // Run the SSH agent:
            SEND_STRING("eval \"$(ssh-agent -s)\"");
    }
    else if (leader_sequence_one_key(KC_L)) {  // Toggle the Caps Lock on / off:
            tap_code(KC_CAPS);
    }
    else if (leader_sequence_one_key(KC_P)) {  // Send a set of Parentheses:
            SEND_STRING("()" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_one_key(KC_Q)) {  // Toggle to the QWERTY base key map:
            tap_code16(CC_QRTY);
    }
    else if (leader_sequence_one_key(KC_S)) {  // Send a set of Square brackets:
            SEND_STRING("[]" SS_TAP(X_LEFT));
    }
    else if (leader_sequence_one_key(KC_T)) {  // Toggle to the Titanium alternate base keymap:
            tap_code16(CC_TITN);
    }
    else if (leader_sequence_one_key(KC_W)) {  // Toggle to the Workman alternate base keymap:
            tap_code16(CC_WKMN);
    }
    else if (leader_sequence_one_key(KC_MINS)) {  // Send the +/- string:
            SEND_STRING("+/-");
    }
}


bool caps_word_press_user(uint16_t keycode) {  // Caps Word - https://docs.qmk.fm/features/caps_word
    switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
                return true;
    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
        return true;
    default:
        return false;  // Deactivate Caps Word.
  }
}
