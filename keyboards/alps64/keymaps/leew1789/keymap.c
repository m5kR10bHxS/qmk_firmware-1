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

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _QWERTY  0  // Quwerty
#define _WORKMAN 1  // Workman
#define _NAV     2  // Navigation
#define _FN      3  // Function
#define _ADJ     4  // Adjustments

#define NAV QK_TRI_LAYER_LOWER
#define SYM QK_TRI_LAYER_UPPER

#define KC_SFTT LSFT_T(KC_T)        // Tap for T, hold for Left Shift
#define KC_SFTN RSFT_T(KC_N)        // Tap for N, hold for Right Shift

enum custom_keycodes {
  KC_QRTY = SAFE_RANGE,
  KC_WKMN,
  KC_CCCV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer: _QWERTY
     * ,-----------------------------------------------------------------------------------------.
     * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
     * |-----------------------------------------------------------------------------------------+
     * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Bk Spc |
     * |-----------------------------------------------------------------------------------------+
     * | Cap Lk  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Shift   |Pg Dn |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl  |  GUI  |  Alt  |           Space                 | _NAV  |Leader |  _Fn  | Ctrl  |
     * `-----------------------------------------------------------------------------------------'
     */

  [_QWERTY] = LAYOUT_infinity( \
      KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,          \
      KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_ENT,                    \
      KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_PGDN,                   \
      KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPACE,                                 MO(_NAV), KC_LEAD, MO(_FN),  KC_RCTL
  ),

    /* Alternate Base Layer: _WORKMAN
     * ,-----------------------------------------------------------------------------------------.
     * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
     * |-----------------------------------------------------------------------------------------+
     * |  Tab   |  Q  |  D  |  R  |  W  |  B  |  J  |  F  |  U  |  P  |  ;  |   [ |  ]  | Bk Spc |
     * |-----------------------------------------------------------------------------------------+
     * | Bk Spc  |  A  |  S  |  H  | T ^ |  G  |  Y  | ^ N |  E  |  O  |  I  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * |   Shift   |  Z  |  X  |  M  |  C  |  V  |  K  |  L  |  ,  |  .  |  /  |  Shift   |Pg Dn |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl  |  GUI  |  Alt  |           Space Fn _NAV         |  Alt  |Leader |  _Fn  | Ctrl  |
     * `-----------------------------------------------------------------------------------------'
     */

   [_WORKMAN] = LAYOUT_infinity( \
      KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV, \
      KC_TAB,  KC_Q,    KC_D,    KC_R,   KC_W,    KC_B,   KC_J,   KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,          \
      KC_BSPC, KC_A,    KC_S,    KC_H,   KC_SFTT, KC_G,   KC_Y,   KC_SFTN, KC_E,    KC_O,    KC_I,    KC_QUOT, KC_ENT,                    \
      KC_LSFT, KC_Z,    KC_X,    KC_M,   KC_C,    KC_V,   KC_K,   KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN,                   \
      KC_LCTL, KC_LGUI, KC_LALT,                  LT(_NAV, KC_SPACE),                                 KC_RALT, QK_LEAD, MO(_FN),  KC_RCTL
  ),

    /* Navigation Layer: _NAV
     * ,-----------------------------------------------------------------------------------------.
     * |  ~  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |Vol- |Vol+ |
     * |-----------------------------------------------------------------------------------------+
     * |        |     |     |     |     |     |     |PG Up| UP  |PtScn|     |     |     | Delete |
     * |-----------------------------------------------------------------------------------------+
     * | Caps Lk |CpsWd|     |     |     |     |     |LEFT | DN  |RIGHT| Ins |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |CCCV |     |Pg Dn|     |     |     |     |          |Pg Up |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |                                 |       |       |       |       |
     * `-----------------------------------------------------------------------------------------'
     */

  [_NAV] = LAYOUT_infinity( \
      KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, \
      _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PSCR, _______, _______, _______, KC_DEL,           \
      KC_CAPS, CW_TOGG, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, _______,                   \
      _______, _______, _______, _______, KC_CCCV, _______, KC_PGDN, _______, _______, _______, _______, _______, KC_PGUP,                   \
      _______, _______, _______,                   _______,                                              _______, _______, _______, _______
  ),

    /* Function Layer: _FN
     * ,-----------------------------------------------------------------------------------------.
     * |  ⚠  |     |     |     |     |     |     |     |     |     |     |     |  ±  |     |  ☠  |
     * |-----------------------------------------------------------------------------------------+
     * |       |     |  Δ  |     |  ω  |  ☣  |     |  ℉  |  µ  |  π  |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |  ☺  |  ☹  |  ♥  |  ®  |     |     |  №  |     |  Ω  |  ∞  |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |  ✔  | ℃   |     |     |  λ  |     |     |     |         |      |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |                                 |       |       |       |       |
     * `-----------------------------------------------------------------------------------------'
     */

  [_FN] = LAYOUT_infinity( \
      UC(0x26a0), _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    UC(0x00b1), _______,    UC(0x2620), \
      _______,    _______,    UC(0x0394), _______,    UC(0x03C9), UC(0x2623), _______,    UC(0x2109), UC(0x00b5), UC(0x03c0), _______,    _______,    _______,    _______,                \
      _______,    UC(0x263a), UC(0x2639), UC(0x2665), UC(0x00ae), _______,    _______,    UC(0x2116), _______,    UC(0x03A9), UC(0x221e), _______,    _______,                            \
      _______,    _______,    _______,    UC(0x2714), UC(0x2103), _______,    _______,    UC(0x03bb), _______,    _______,    _______,    _______,    _______,                            \
      _______,    _______,    _______,                            _______,                                                                _______,    _______,    _______,    _______
  ),

    /* Adjustment Layer: _ADJ (_NAV + _FN)
     * ,-----------------------------------------------------------------------------------------.
     * |Flash|     |     |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----------------------------------------------------------------------------------------+
     * |       |qwerty|workman|     |Flash|     |     |     |     |     |     |     |     |      |
     * |-----------------------------------------------------------------------------------------+
     * |         |     |     |     |     |     |     |     |     |     |     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * | DT Print  |DT U |DT D |     |     |     |     |     |     |     |     |          |      |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |                                 |       |       |       |       |
     * `-----------------------------------------------------------------------------------------'
     */

  [_ADJ] = LAYOUT_infinity( \
      QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_QRTY, KC_WKMN, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   \
      DT_PRNT, DT_UP,   DT_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   \
      _______, _______, _______,                   _______,                                              _______, _______, _______, _______

      // DT keycodes adjust the dynamic tapping term by 5ms - this offset is not persistent
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _FN, _ADJ);
}

bool caps_word_press_user(uint16_t keycode) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ( !process_caps_word(keycode, record)) { return false; }  // Detect call to caps word function (both shift keys simultaneously)

/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFTT:                  // List keys that require an offset from global tappingerm
        case KC_SFTN:
            return TAPPING_TERM + 50;    // Amount of offset
        default:
            return TAPPING_TERM;
    }
}
*/

/*
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SFTT:        // List keys that should not repeat (home row mods)
        case KC_SFTN:
            return true;
        default:               // Keys are permitted to repeat (default action)
            return false;
    }
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ( !process_caps_word(keycode, record)) { return false; }

  switch (keycode) {
    case KC_QRTY:  // Toggle to the QWERTY alternate base layer
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case KC_WKMN:  // Toggle to the WORKMAN alternate base layer
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;

    case KC_CCCV:  // One key copy/paste
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
