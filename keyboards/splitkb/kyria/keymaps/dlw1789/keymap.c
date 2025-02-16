// Kyria

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
#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
    QWERTY = 0,
    WORKMAN,
    Titanium,
    NAV,
    NUM,
    CFG
};

Aliases: Home Row Mods
LGUI_T(KC_S),
LALT_T(KC_N),
LCTL_T(KC_T),
RCTL_T(KC_A),
RALT_T(KC_E),
RGUI_T(KC_I),

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Grv Esc |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ; :  |  , "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LCTL  |   Z  |   X  |   C  |   V  |   B  | CCCV | Home |  | End  |Leader|   N  |   M  |  , < |  . > | /  ? |  RCTL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  |  Alt | LOWER| Shift| NAV  |  |ADJUST| Shift| RAISE| Alt  | MPLY |
 *                        |      |      | Bspc |  Del |      |  |      | Enter| Space|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      QK_GESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                     KC_Y,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_PIPE,
      KC_TAB,   KC_A,   KC_S,   KC_H,   KC_T,   KC_G,                                                     KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,       KC_QUOT,
      KC_LCTL,  KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,     KC_CCCV,   KC_HOME,    KC_END,  KC_LEAD,        KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RCTL,
           KC_LGUI, KC_LALT, LT(LOWER,KC_BSPC), MT(MOD_LSFT,KC_DEL), MO(NAV),    MO(ADJUST), MT(MOD_RSFT,KC_ENT), LT(RAISE,KC_SPC), KC_RALT, KC_MPLY
    ),
/*
 * Alternate Base Layer: WORKMAN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   D  |   R  |   W  |   B  |                              |   J  |   F  |   U  |   P  | ;  : |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  | gui S| alt H| ctl T|   G  |                              |   Y  | ctl N| alt E| gui O|   I  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   M  |   C  |   V  | CCCV |      |  |      |      |   K  |   L  |  , < |  . > | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Space|      |      |  |      |      |1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      |      |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [WORKMAN] = LAYOUT(
      KC_ESC,   KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,                                                     KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_PIPE,
      KC_TAB,   KC_A,   KC_S,   KC_H,   KC_T,   KC_G,                                                     KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,       KC_QUOT,
      KC_LCTL,  KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,     KC_CCCV,   KC_HOME,    KC_END,  KC_LEAD,        KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RCTL,
           KC_LGUI, KC_LALT, LT(NAV,KC_SPC), MT(MOD_LSFT,KC_DEL), MO(NAV),    _______, _______, OSM(KC_RSFT), TG(NUM), QK_LEAD
    ),
/*
 * Alternate Base Layer: Upside Down TITANIUM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   X  |   F  |   L  |   D  |   W  |                              |  ~ | |   U  |   O  |   Y  |   B: |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   C  | gui S| alt N| ctl T|   K  |                              |  , ; | ctl A| alt E| gui I|   H  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   J  |   G  |   M  |   P  |   V  | CCCV |      |  |      |      |  - + |  . : |  ' ! |  " ? |  / * |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |   R  | Space|Repeat|      |  |      |AltRep|1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      |      |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [TITANIUM] = LAYOUT(
      _______,   KC_X,   KC_F,   KC_L,   KC_D,   KC_W,                                                     KC_TILD, KC_U,    KC_O,    KC_Y,    KC_B,     _______,
      _______,   KC_C,   KC_S,   KC_N,   KC_T,   KC_K,                                                     KC_COMM, KC_A,    KC_E,    KC_I,    KC_H,     _______,
      _______,   KC_J,   KC_G,   KC_M,   KC_P,   KC_V,     KC_CCCV,    KC_HOME,    KC_END,  _______,       KC_MINS, KC_DOT,  KC_QUOT, KC_DQUO, KC_SLSH,  _______,
                              _______, KC_R, LT(_NAV,KC_SPC), QK_REP,  _______,    _______, QK_AREP, OSM(KC_RSFT), TG(NUM), QK_LEAD
    ),
/*
 * Navigation Layer: NAV
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | TabBk| WinBk|CpyPst| CCCV |Bright|                              | Vol+ | PgUp |  Up  | Home |  App |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  GUI |  ALT |  CTL |  Dim |                              | Vol- | Left | Down | Right| Menu |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Sleep|      | CapLk| PrtSc| Break|      |      |  |      |      |PlaPau| PgDn |      |  End |Insert|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |1-Shft|      |      |
 *                        |      |      | _NAV |      |      |  |      |      |      | _CFG |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NAV] = LAYOUT(
      _______, _______, _______, _______, _______, KC_BRIU,                                         KC_VOLU, KC_PGUP, KC_UP,   KC_HOME, KC_APP,  _______,
      _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_BRID,                                         KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_MENU, _______,
      _______, KC_SLEP, _______, _______, KC_PSCR, _______, _______, _______,     _______, _______, KC_MPLY, KC_PGDN, _______, KC_END,  _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
/*
 * Numpad Layer: NUM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   #  |   $  |   %  |   ^  |   =  |                              |  / * | 7 F7 | 8 F8 | 9 F9 |  F10 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  GUI |  ALT |  CTL |  . : |                              |   0  | 1 F1 | 2 F2 | 3 F3 |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |   <  |   >  |      |      |      |  |      |      |  - + | 4 F4 | 5 F5 | 6 F6 |  F12 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | Space|      |      |  |      | _CFG |1-Shft| _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUM] = LAYOUT(
      _______,  KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_EQL,                                              KC_SLSH,  KC_7,  KC_8,  KC_9,  KC_F10,  _______,
      _______,  _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  _______,                                             KC_0,     KC_1,  KC_2,  KC_3,  KC_F11,  _______,
      _______,  _______,  KC_LABK,  KC_RABK,  _______,  _______,  _______,  _______,     _______,  _______,  KC_MINS,  KC_4,  KC_5,  KC_6,  KC_F12,  _______,
                                    _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______
    ),
   ),
/*
 * Configuration Layer: CFG
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |On/Off| Sat+ | Hue+ | Brt+ |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      | Modes|  Sat- | Hue- | Brt-|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Reset |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      | _CFG |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [CFG] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                         _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, _______,
      _______, _______, _______, _______, _______, _______,                                         _______, RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD, _______,
      RESET,   _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
};

# layer_state_t layer_state_set_user(layer_state_t state) {
#     return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    switch (keycode) {
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

void housekeeping_task_user(void) {
  achordion_task();
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_N) { // Undo closed browser window
            SEND_STRING(SS_LCTL(SS_LALT("n")));
        }
        SEQ_ONE_KEY(KC_P) { // New private browser window
            SEND_STRING(SS_LCTL(SS_LSFT("p")));
        }
        SEQ_ONE_KEY(KC_R) { // Toggle browser reader mode
            SEND_STRING(SS_LCTL(SS_LSFT("r")));
        }
        SEQ_ONE_KEY(KC_T) { // Undo closed browser tab
            SEND_STRING(SS_LCTL(SS_LSFT("t")));
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case WORKMAN:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 1) {
        switch (biton32(layer_state)) {
            case WORKMAN:
                // Scrolling with PageUp and PgDn.
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                // Volume control.
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
//}
#endif

