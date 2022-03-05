// Pegasus Hoof AKA Fiilco Majestouch II TKL

/*
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

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

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

#define _QWERTY  0  // QWERTY
#define _WORKMAN 1  // Workman
#define _NAV     2  // Navigation
#define _FN      3  // Function
#define _ADJ     4  // Adjustments

enum custom_keycodes {
    qwerty = SAFE_RANGE,
    workman
    CCCV            // Hold to copy, tap to paste
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer: _QWERTY
 * +-------+------+------+------+------+------+-----+------+------+------+------+----+------+------+-------+-------+    +--------+--------+--------+
 * |  Esc  |  xx  |  F1  |  F2  |  F3  |  F4  |  xx |  F5  |  F6  |  F7  |  F8  | XX |  F9  |  F10 |  F11  |  F12  |    | Prt Scr| Scr Lk |  Pause |
 * |-------+-------+-------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    |--------+--------+--------|
 * |  ` ~  |   1   |   2   |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |   Backspace   |    | Insert |  Home  |  Pg Up |
 * |-------+-------+-------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    |--------+--------+--------|
 * |  Tab   |   Q   |   W   |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [ {  |  ] }  |     \ |      |    | Delete |   End  |  Pg Dn |
 * |-------+-------+-------+------+------+------+------+------+------+------+------+-------+-------+---_---+-------|    +--------+--------+--------+
 * | Caps Lk  |   A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; :  |  ' "  |       Enter        |
 * |-------+-------+-------+------+------+------+------+------+------+------+------+-------+-------+---------------|             +--------+
 * |   Shift    |  XX   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  /  ?  |     Shift        |             |   Up   |
 * |-------+-------+-------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    +--------+--------+--------+
 * |  Ctrl |  GUI  |  Alt  |                     Space Fn (_NAV)                   |  Alt  |Leader |  _Fn  |  Ctrl |    |  Left  |  Down  |  Right |
 * +-------+-------+-------+-------------------------------------------------------+-------+-------+-------+-------+    +--------+--------+--------+
*/

 [_QWERTY] = LAYOUT_tkl_ansi( \
   KC_ESC,           KC_F1,  KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,  KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, \
   KC_GRV,  KC_1,    KC_2,   KC_3,  KC_4,  KC_5,    KC_6,    KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, \
   KC_TAB,  KC_Q,    KC_W,   KC_E,  KC_R,  KC_T,    KC_Y,    KC_U,   KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, \
   KC_CLCK, KC_A,    KC_S,   KC_D,  KC_F,  KC_G,    KC_H,    KC_J,   KC_K,  KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                             \
   KC_LSFT,          KC_Z,   KC_X,  KC_C,  KC_V,    KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,            \
   KC_LCTL, KC_LGUI, KC_LALT,              LT(_NAV, KC_SPC),                         KC_RALT, KC_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
 ),

/* Alternate Base Layer: _WORKMAN
 *  --------+-----+------+------+------+------+----+------+------+------+------+----+------+------+-------+-------     +--------+--------+--------+
 * |  Esc   | XX  |  F1  |  F2  |  F3  |  F4  |  XX|  F5  |  F6  |  F7  |  F8  |  XX|  F9  |  F10 |  F11  |  F12  |    | Prt Scr| Scr Lk |  Pause |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    |--------+--------+--------|
 * |  ` ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |   Backspace   |    | Insert |  Home  |  Pg Up |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|    |--------+--------+--------|
 * |  Tab    |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |  [ {  |  ] }  |     \ |      |    | Delete |   End  |  Pg Dn |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|    +--------+--------+--------+
 * |Backspace |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I   |  ' "  |        Enter       |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------|             +--------+
 * |   Shift    |  XX  |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |  , < |  . > |  /  ?  |      Shift       |             |   Up   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    +--------+--------+--------+
 * |  Ctrl  |  GUI |  Alt |                     Space Fn (_NAV)                   |  Alt  |Leader |  _Fn  |  Ctrl |    |  Left  |  Down  |  Right |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------     +--------+--------+--------+
*/

 [_WORKMAN] = LAYOUT_tkl_ansi( \
   KC_ESC,           KC_F1,   KC_F2, KC_F3, KC_F4,   KC_F5, KC_F6,  KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, \
   KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,    KC_6,  KC_7,   KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, \
   KC_TAB,  KC_Q,    KC_D,    KC_R,  KC_W,  KC_B,    KC_J,  KC_F,   KC_U,  KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, \
   KC_BSPC, KC_A,    KC_S,    KC_H,  KC_T,  KC_G,    KC_Y,  KC_N,   KC_E,  KC_O,    KC_I,    KC_QUOT,          KC_ENT,                             \
   KC_LSFT,          KC_Z,    KC_X,  KC_M,  KC_C,    KC_V,  KC_K,   KC_L,  KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,            \
   KC_LCTL, KC_LGUI, KC_LALT,               LT(_NAV, KC_SPC),                       KC_RALT, KC_LEAD, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
 ),

/* Navigation Layer: _NAV
 *  --------+-----+------+------+------+------+----+------+------+------+------+----+------+------+-------+-------     +--------+--------+--------+
 * |   ` ~  |  XX |      |      |      |      | XX |      |      |      |      | XX |      |      |       |       |    |        |        |        |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    |--------+--------+--------|
 * |        |      |      |      |      |      |      |      |      |      |      | Vol-  | Vol+  |    Delete     |    |        |        |        |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|    |--------+--------+--------|
 * |         |      |      |      |      |      |      |Pg Up |  Up  |PtScn |      |       |       |              |    |        |        |        |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|    +--------+--------+--------+
 * | Caps Lk   |      |      |      |      |      |      | Left | Down |Right |Insert |       |                   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------|             +--------+
 * |               |  XX  |      |      |      | CCCV |      |Pg Dn |      |      |       |       |               |             |        |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|    +--------+--------+--------+
 * |        |      |      |                                                       |       |       |       |       |    |        |        |        |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------     +--------+--------+--------+
*/

 [_NAV] = LAYOUT_tkl_ansi( \
 KC_GRV,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_VOLD, KC_VOLU, KC_DEL,  _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PSCR, _______,  _______, _______, _______, _______, _______, _______,
 KC_CLCK, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KS_INS,  _______,
 _______,          _______, _______, _______, CCCV,    _______, KC_PGDN, _______, _______, _______,  _______, _______, _______,
 _______, _______, _______,                   _______,                                     _______, _______, _______,  _______, _______, _______, _______
 ),

// Function Layer: _FN
 [_FN] = LAYOUT_tkl_ansi( \
 UC(0x26a0),             _______,    _______,    _______,    _______,    _______, _______,    _______,    _______,    _______,    _______, _______,    _______,    _______, _______, _______,
 _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,    _______,    _______,    _______,    _______, UC(0x00b1), UC(0x2620), _______, _______, _______,
 _______,    _______,    UC(0x0394), _______,    UC(0x03C9), UC(0x2623), _______, UC(0x2109), UC(0x00b5), UC(0x03c0), _______,    _______, _______,    _______,    _______, _______, _______,
 _______,    UC(0x263a), UC(0x2639), UC(0x2665), UC(0x00ae), _______,    _______, UC(0x2116), _______,    UC(0x03A9), UC(0x221e), _______, _______,
 _______,                _______,    UC(0x2714), UC(0x2103), _______,    _______, UC(0x03bb), _______,    _______,    _______,    _______, _______,    _______,
 _______,    _______,    _______,                            _______,                                                 _______,    _______, _______,    _______,    _______, _______, _______
 ),  
 
 // Adjust Layer: _ADJ (_NAV + _FN)
 [_ADJ] = LAYOUT_tkl_ansi( \
 RESET,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, qwerty,  workman, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, GUI_TOG, _______,                   _______,                                     _______, _______, _______, _______, _______, _______, _______
 ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _FN, _ADJ);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case qwerty:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    
    case workman:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;

    case CCCV:  // One key copy/paste
      if (record->event.pressed) {
          copy_paste_timer = timer_read();
      } else {
          if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold to copy
              tap_code16(LCTL(KC_C));
          } else { // Tap to paste
              tap_code16(LCTL(KC_V));
          }
      }
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_A) {
      // Send a set of Angle brackets
      SEND_STRING("<>"); tap_code(KC_LEFT);
    }
    SEQ_ONE_KEY(KC_C) {
      // Send a set of curly brackets
      SEND_STRING("{}"); tap_code(KC_LEFT);
    }
    SEQ_ONE_KEY(KC_P) {
      // Send a set of parenthesis
      SEND_STRING("()"); tap_code(KC_LEFT);
    }
    SEQ_ONE_KEY(KC_Q) {
      // Send a set of Double quotes
      SEND_STRING("\"\""); tap_code(KC_LEFT);
    }
    SEQ_ONE_KEY(KC_S) {
      // Send a set of square brackets
      SEND_STRING("[]"); tap_code(KC_LEFT);
    }
  }
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    ph_caps_led_on();
  } else {
    ph_caps_led_off();
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    ph_sclk_led_on();
  } else {
    ph_sclk_led_off();
  }
}
