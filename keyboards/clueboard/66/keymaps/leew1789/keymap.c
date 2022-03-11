// Clueboard 66 rev2

#include QMK_KEYBOARD_H
#include "features/caps_word.h"

uint16_t copy_paste_timer;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _QWERTY  0  // QWERTY
#define _WORKMAN 1  // Workman
#define _NAV     2  // Navigation
#define _FN      3  // Function
#define _ADJ     4  // Adjustments

enum custom_keycodes {
  qwerty = SAFE_RANGE,
  workman,
  CCCV
};

#define KC_SFTT LSFT_T(KC_T)  // Tap for T, hold for Left Shift
#define KC_SFNN RSFT_T(KC_N)  // Tap for N, hold for Right Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer: _QWERTY (Default Base Layer)
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+        
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |   Backspace   |       | PgUp  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [ {  |  ] }  |     \ |       |       | PgDn  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |    Caps Lk    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; :  |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------+-------+
 * |     Shift     |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  /  ? |         Shift         |   Up  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------+-------+-------+
 * |  Ctrl  |  GUI |  Alt |                     Space Fn(_NAV)                    |  Alt  |  _FN  |  Ctrl | Left  |  Down | Right |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

 [_QWERTY] = LAYOUT_66_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,       KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,       KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,    KC_QUOT, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,    KC_RSFT,                   KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT,                   LT(_NAV, KC_SPACE),                 KC_RALT,  MO(_FN),    KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
 ),

/* Base Layer: _WORKMAN: (Alternate Base Layer)
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+        
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  6   |   7  |   8  |   9  |   0  |  - _  |  = +  |   Backspace   |       | PgUp  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |  Tab   |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  | ;  : |  [ {  |  ] }  |     | \       |       | PgDn  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |   Backspace   |   A  |   S  |   H  | Sft T|   G  |   Y  | Sft N|   E  |   O  |   I   |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------+-------+
 * |     Shift     |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |  , < |  . > |  /  ? |         Shift         |   Up  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------+-------+-------+
 * |  Ctrl  |  GUI |  Alt |                     Space FN(_NAV)                    |  Alt  |  _FN  |  Ctrl | Left  |  Down | Right |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

 [_WORKMAN] = LAYOUT_66_ansi(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS, KC_EQL,  KC_BSPC,           KC_PGUP,
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,      KC_SCLN,   KC_LBRC, KC_RBRC, KC_BSLS,           KC_PGDN,
  KC_BSPC, KC_A,    KC_S,    KC_H,    KC_SFTT, KC_G,    KC_Y,    KC_SFNN, KC_E,    KC_O,      KC_I,      KC_QUOT, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,                   KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT,                   LT(_NAV, KC_SPACE),                 KC_RALT,   MO(_FN),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* Navigation Layer: _NAV
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+        
 * |  ` ~   |   F1 |   F2 |   F3 |   F4 |   F5 |  F6  |   F7 |   F8 |   F9 |  F10 |  F11  |  F12  |    Delete     |       |Vol Up |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |        |      |      |      |      |      |      |Pg Up |  Up  |PtScn |      |       |       |               |       |Vol Dn |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |    Caps Lk    |      |      |      |      |      |      | Left | Down |Right |Insert |       |               |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------+-------+
 * |               |      |      |      | CCCV |      |Pg Dn |      |      |      |       |                       | Pg Up |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------+-------+-------+
 * |        |      |      |                                                       |       |       |       |       | Pg Dn |       |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */
 
 [_NAV] = LAYOUT_66_ansi(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,           KC_PGUP,
  _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PSCR, _______,  _______, _______, _______,          KC_PGDN,
  KC_CAPS, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  _______, _______,
  _______, _______, _______, _______, CCCV,    _______, KC_PGDN, _______, _______, _______, _______,  _______,                   KC_UP,
  _______, _______, _______,                            _______,                   _______, _______,  _______,          KC_LEFT, KC_DOWN, KC_RIGHT
 ),

/* Function Layer: _FN
 *  --------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+  
 * |   ⚠    |       |       |       |       |       |       |       |       |       |       |       |   ±   |      ☠       |       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+
 * |        |       |   Δ   |       |   ω   |   ☣   |       |  ℉   |   µ   |   π   |       |       |       |               |       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+
 * |                |  ☺   |   ☹   |  ♥    |   ®   |       |       |   №   |       |   Ω   |   ∞   |       |               |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------------+-------+
 * |                |       |       |   ✔   |   ℃  |       |       |   λ   |       |       |       |                       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |        |       |       |                                                               |       |       |       |       |       |       |
 *  --------+-------+-------+---------------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

 [_FN] = LAYOUT_66_ansi(
  UC(0x26a0), _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, UC(0x00b1), UC(0x00b1),        _______,
  _______,    _______,    UC(0x0394), _______,    UC(0x03C9), UC(0x2623), _______,    UC(0x2109), UC(0x00b5), UC(0x03c0), _______,    _______, _______,    _______,           _______,
  _______,    UC(0x263a), UC(0x2639), UC(0x2665), UC(0x00ae), _______,    _______,    UC(0x2116), _______,    UC(0x03a9), UC(0x221e), _______, _______, 
  _______,    _______,    _______,    UC(0x2714), UC(0x2103), _______,    _______,    UC(0x03bb), _______,    _______,    _______,    _______,                    _______,
  _______,    _______,    _______,                                        _______,                            _______,    _______,    _______,           _______, _______, _______
 ),

/* Adjustment Layer: _ADJ (_NAV + _FN)
 *  --------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+        
 * | Reset  |       |       |       |       |       |       |       |RGB_TOG|RGB_SAI|RGB_HUI|RGB_VAI|       |               |       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+
 * |        | qwerty|workman|       | Reset |       |       |       |RGB_MOD|RGB_SAD|RGB_HUD|RGB_VAD|       |               |       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+       +-------+
 * |                |       |       |       |       |       |       |       |       |       |       |       |               |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+---------------+-------+
 * |   RGB Static   |Breathe|Rainbow| Swirl | Snake |K Rider| X-Mas |Gradint|RGB Tst|       |       |                       |       |
 * |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |        |Toggle |       |                                                               |       |       |       |       |       |       |
 *  --------+-------+-------+---------------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

 [_ADJ] = LAYOUT_66_ansi(
  RESET,    _______, _______, _______,  _______,  _______,  _______, _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, _______, _______,           _______,
  _______,  qwerty,  workman, _______,  RESET,    _______,  _______, _______, RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______,           _______,
  _______,  _______, _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,
  RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,                    _______,
  _______,  GUI_TOG, _______,                               _______,                   _______, _______, _______,           _______, _______, _______
 ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _FN, _ADJ);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ( !process_caps_word(keycode, record)) { return false; }  // Detect call to caps word function (both shift keys simultaneously)
  
  switch (keycode) {
    case qwerty:  // Toggle to QWERTY key map
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
      
    case workman:  // Toggle to Workman key map
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

/*
The default behavior (when CAPS_WORD_IDLE_TIMEOUT isn't set, or set to 0) is that Caps Word
never times out, and in this case it isn't necessary to call caps_word_task(). Caps Word
remains active indefinitely until a word breaking key is pressed.

The following function checks the caps word timer (configured in config.h) to determine if
it has expired and if so, it will deactivate caps word one the timer expires.

void matrix_scan_user(void) {
  caps_word_task();
  // Other tasks...
}
*/