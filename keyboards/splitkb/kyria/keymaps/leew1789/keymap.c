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
#define TTY1     LCA(KC_F1)
#define TTY2     LCA(KC_F2)
#define TTY3     LCA(KC_F3)
#define TTY4     LCA(KC_F4)
#define TTY5     LCA(KC_F5)
#define TTY6     LCA(KC_F6)
#define TTY7     LCA(KC_F7)


// Tap / Hold - via the Mod Tap function:
#define TH_1     LT(0, KC_1)     // TH_ = (Tap / Hold) keys
#define TH_2     LT(0, KC_2)     // Tapped, they produce the numbers 1 through 9
#define TH_3     LT(0, KC_3)     // Held, they produce the equivalent number F-Key
#define TH_4     LT(0, KC_4)     // Shifted (1 through 7), they produce the equivalent number Linux TTY terminal.
#define TH_5     LT(0, KC_5)     // F-keys should repeat. Others should not.
#define TH_6     LT(0, KC_6)
#define TH_7     LT(0, KC_7)
#define TH_8     LT(0, KC_8)
#define TH_9     LT(0, KC_9)
#define TH_B     LT(0, KC_B)     // B _
#define TH_C     LT(0, KC_C)     // C "\"
#define TH_F     LT(0, KC_F)     // F Qu
#define TH_G     LT(0, KC_G)     // G #
#define TH_H     LT(0, KC_H)     // H He
#define TH_K     LT(0, KC_K)     // K Th
#define TH_V     LT(0, KC_V)     // V @
#define TH_W     LT(0, KC_W)     // W ^
#define TH_X     LT(0, KC_X)     // X Z
#define TH_Y     LT(0, KC_Y)     // Y @
#define TH_COMM  LT(0, KC_COMM)  // , ;
#define TH_DOT   LT(0, KC_DOT)   // . :
#define TH_DQUO  LT(0, KC_DQUO)  // " ?
#define TH_MINS  LT(0, KC_MINS)  // - +
#define TH_QUOT  LT(0, KC_QUOT)  // ' !
#define TH_SLSH  LT(0, KC_SLSH)  // / *
#define TH_TILD  LT(0, KC_PIPE)  // ~ |
#define TH_MPLY  LT(0, KC_MPLY)  // Play-Pause / Next
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
    CC_WKMN   // Workman alternate base layer
    THORN,    // th / Th
};


// Getreuer's Custom Shift Keys
const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMM, KC_SCLN},  // Shift , is ;
    {KC_DOT,  KC_COLN},  // Shift . is :
    {KC_DQUO, KC_EXLM},  // Shift " is !
    {KC_HOME, KC_END},   // Shift Home is End
    {KC_MINS, KC_PLUS},  // Shift - is +
    {KC_MPLY, KC_MNXT},  // Shift MPLY is Next
    {KC_QUOT, KC_QUES},  // Shift ' is ?
    {KC_SLSH, KC_ASTR},  // Shift / is *
    {KC_TILD, KC_PIPE},  // Shift ~ is |
    {TH_1,    TTY1},  // Shift 1 is TTY1
    {TH_2,    TTY2},  // Shift 2 is TTY2
    {TH_3,    TTY3},  // Shift 3 is TTY3
    {TH_4,    TTY4},  // Shift 4 is TTY4
    {TH_5,    TTY5},  // Shift 5 is TTY5
    {TH_6,    TTY6},  // Shift 6 is TTY6
    {TH_7,    TTY7}   // Shift 7 is TTY7
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |  F9  |  F10 |  |  F11 |  F12 |   N  |   M  |  , < |  . > | /  ? |  Shift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  GUI |  Alt | Space| BkSpc|      |  |      |      |1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      | _CFG |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_PIPE,
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_M,    SFT_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F9,   KC_F10,     KC_F11,  KC_F12,   KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                 KC_LGUI, KC_LALT, SPC_NAV, KC_BSPC, XXXXXXX,    XXXXXXX, TG(_CFG), SFT_1ST, TG(_NUM), QK_LEAD
    ),
/*
 * Alternate Base Layer: Workman
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  Q   |  D   |  R   |  W   |  B   |                              |  J   |  F   |  U   |  P   | ;  : |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  A   |gui S |alt H |ctl T |  G   |                              |  Y   |ctl N |alt E |gui O |  I   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  Z   |  X   |  M   |  C   |  V   |  F9  | F10  |  | F11  | F12  |  K   |  L   |  , < |  . > | /  ? |  - +   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | BKSpc| Space|Repeat|      |  |      |AltRep|1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      |      |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_WORKMAN] = LAYOUT(
      KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                           KC_J,    KC_F,     KC_U,    KC_P,    KC_SCLN, KC_PIPE,
      CTL_ESC, KC_A,    S_GUI,   H_ALT,   T_CTL,   KC_G,                                           KC_Y,    N_CTL,    E_ALT,   O_GUI,   KC_I,    KC_QUOT,
      KC_LCTL, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_F9,   KC_F10,     KC_F11,  KC_F12,  KC_K,    KC_L,     KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 XXXXXXX, KC_BSPC, SPC_NAV, QK_REP,  XXXXXXX,    XXXXXXX, QK_AREP, SFT_1ST, TG(_NUM), QK_LEAD
    ),
/*
 * Alternate Base Layer: Titanium
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  X Z | F Qu |  L   |  D   | W ^  |                              | ~ |  |  U   |  O   | Y @  |  B _ |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  C   |gui S |alt N |ctl T | K Th |                              | . :  |ctl A |alt E |gui I | H He |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  J   |  G   |  M   |  P   | V #  |  F9  |  F10 |  |  F11 |  F12 | - +  | . :  | / *  | " !  | ' ?  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  R   |Space |Repeat|      |  |      |AltRep|1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      |      |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_TITANIUM] = LAYOUT(
      XXXXXXX, TH_X,    TH_F,    KC_L,    KC_D,    TH_W,                                           TH_TILD, KC_U,     KC_O,    TH_Y,    TH_B,    XXXXXXX,
      XXXXXXX, KC_A,    S_GUI,   H_ALT,   T_CTL,   TH_K,                                           KC_DOT,  A_CTL,    E_ALT,   I_GUI,   TH_H,    XXXXXXX,
      XXXXXXX, KC_J,    KC_G,    KC_M,    KC_P,    TH_V,    KC_F9,   KC_F10,     KC_F11,  KC_F12,  TH_MINS, TH_COMM,  TH_SLSH, TH_DQUO, TH_QUOT, XXXXXXX,
                                 XXXXXXX, KC_R,    SPC_NAV, QK_REP,  XXXXXXX,    XXXXXXX, QK_AREP, SFT_1ST, TG(_NUM), QK_LEAD
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |Tab_Bk|Win_Bk|  \   |  &   |      |                              | App  | PgUp |  UP  | Home | Vol+ |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | GUI  | Alt  | Ctrl | CCCV |                              | Menu | Left | Down |Right | MPLY |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |CapLk |PrtScn|      |      |      |  |      |      |      | PgDn |Insert|  End | Vol- |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |Space |Repeat|      |  |      |AltRep|1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, Tab_BK,  Win_BK,  KC_BSLS, KC_AMPR, XXXXXXX,                                        KC_APP,  KC_PGUP, KC_UP,   KC_HOME, KC_VOLU, XXXXXXX,
      XXXXXXX, _______, KC_LGUI, KC_LALT, KC_LCTL, CC_CCCV,                                        KC_MENU, KC_LEFT, KC_DOWN, KC_RGHT, TH_MPLY, XXXXXXX,
      XXXXXXX, _______, _______, KC_CAPS, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_INS,  KC_END,  KC_VOLD, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, QK_REP,  XXXXXXX,    XXXXXXX, QK_AREP, _______, _______, _______
    ),
/*
 * Numbpad / F-Key Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  #   |  $   |  %   |  ^   |  =   |                              | / *  | 7 F7 | 8 F8 | 9 F9 | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | GUI  | Alt  | Ctrl | . :  |                              |  0   | 1 F1 | 2 F2 | 3 F3 | F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  <   |  >   |      |      |      |  |      |      | - +  | 4 F4 | 5 F5 | 6 F6 | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |Space |Repeat|      |  |      |      |1-Shft|      |Leader|
 *                        |      |      | _NAV |      |      |  |      | _CFG |      | _NUM |      |
 *                        `----------------------------------'  `----------------------------------'KC_LABK
 */
    [_NUM] = LAYOUT(
      XXXXXXX, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,                                           KC_SLSH, TH_7,    TH_8,    TH_9,    KC_F10,  XXXXXXX,
      XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_DOT,                                           KC_0,    TH_1,    TH_2,    TH_3,    KC_F11,  XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  KC_MINS, TH_4,    TH_5,    TH_6,    KC_F12,  XXXXXXX,
                                 XXXXXXX, XXXXXXX, KC_SPACE, QK_REP,  XXXXXXX,    XXXXXXX, TG(_CFG), _______, _______, QK_LEAD
    ),
/*
 * Configuration Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Boot  |      |      |      |QWERTY|      |                              |      |On/Off| Hue+ | Sat+ | Spd+ | Brt+   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |DT_UP |DT_DN |Print |Wrkman|      |                              |      | Modes| Hue- | Sat- | Spd- | Brt-   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |HD-Ti |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      | _CFG |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CFG] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, CC_QRTY, XXXXXXX,                                        UG_TOGG, UG_HUEU, UG_SATU, UG_SPDU, UG_VALU, XXXXXXX,
      XXXXXXX, DT_UP,   DT_DOWN, DT_PRNT, CC_WKMN, XXXXXXX,                                        UG_NEXT, UG_HUED, UG_SATD, UG_SPDD, UG_VALD, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CC_TITN, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
/*
 * Combinations
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |Leader| Esc  | Esc  | Bksp |                              | Bksp | Tab  | Tab  |Leader|      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |Caps W| Enter|                              | Enter|Caps W|      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Ctrl Q|Ctrl Q| Del  |      |      |  |      |      | Del  |Ctrl Z|Ctrl Z|      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
};


// Order of processing: process_record_user (Achordion, or SM_TD), followed by Repeat / Alt Repeat, followed by other handlers.

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
        case THORN:  // Dedicated th / Th key implementation
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
                    SEND_STRING("Qu");
                    register_mods(mods); // Re-enable the Shift mod status
                } else {
                    SEND_STRING("qu");
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
        case TH_MPLY:  // KC_B on tap, KC_PIPE on long press
            return process_tap_or_long_press_key(record, (KC_MNXT));
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
        case TH_Y:  // KC_Y on tap, KC_TILD on long press
            return process_tap_or_long_press_key(record, (KC_TILD));
        case TH_COMM:  // KC_COMM on tap, KC_SCLN on long press
            return process_tap_or_long_press_key(record, (KC_SCLN));
        case TH_DOT:  // KC_DOT on tap, KC_COLN on long press
            return process_tap_or_long_press_key(record, (KC_COLN));
        case TH_DQUO:  // KC_DQUO on tap, KC_EXLM on long press
            return process_tap_or_long_press_key(record, (KC_EXLM));
        case TH_MINS:  // KC_MINS on tap, KC_PLUS on long press
            return process_tap_or_long_press_key(record, (KC_PLUS));
        case TH_QUOT:  // KC_QUOT on tap, KC_QUES on long press
            return process_tap_or_long_press_key(record, (KC_QUES));
        case TH_SLSH:  // KC_SLSH on tap, KC_ASTR on long press
            return process_tap_or_long_press_key(record, (KC_ASTR));
        case TH_TILD:  // KC_TILD on tap, KC_PIPE on long press
            return process_tap_or_long_press_key(record, (KC_PIPE));
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
            case KC_G:    return C(KC_Q);  // Ctrl + G reverses to Ctrl + Q
            case KC_J:    return C(KC_Z);  // Ctrl + J reverses to Ctrl + Z
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
        case KC_EXLM;
        case KC_QUES:
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

/*
// Rotery Encoder - Note:  * The index parameter tells you which encoder was turned. If you only have one encoder, the index will always be zero
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _WORKMAN:  // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _TITANIUM  // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code (KC_VOLD);
                }
                break
            default:        // Scrolling with Page Up and Page Down
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
        }
    }
}
*/

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][1] = {  // https://docs.keeb.io/reprogramming-encoders
          // Mappings for 1st Encoder           // Mappings for 2nd Encoder
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   //ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, // Mapping for Base layer
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLD),   //ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  }, // Mapping for Layer 1
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   //ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  }, // Mapping for Layer 2
    [3] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),   //ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }, // Mapping for Layer 3
    [4] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  //ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }, // Mapping for Layer 4
    [5] = { ENCODER_CCW_CW(UG_TOGG, UG_NEXT),   //ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }, // Mapping for Layer 5
};


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

#ifdef OLED_DRIVER_ENABLE
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
        case _WORKMAN:
            oled_write_P(PSTR("Workman\n"), false);
            break;
    switch (get_highest_layer(layer_state)) {
        case _TITANIUM:
            oled_write_P(PSTR("HD-Titanium\n"), false);
            break;
    switch (get_highest_layer(layer_state)) {
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num Pad\n"), false);
            break;
        case _CFG:
            oled_write_P(PSTR("Configure\n"), false);
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
#endif  // OLED_DRIVER_ENABLE


/*
 * Raise Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   +/-  | Deg C| Warn | Delta|  {   |  }   |                              |   `  |  !   |  @   |  #   |  $   |   %    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   TM   | Deg F| Hzrd | Omega|  [   |  ]   |                              |   ^  |  &   |  *   |  _   |  =   |   |    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   No   | Cents|  Pi  | Infin|  (   |  )   |      |      |  |      |      |   ~  |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | LOWER|      | NAV  |  |ADJUST|      | Raise|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'

    [RAISE] = LAYOUT(
      UC(0x00B1), UC(0x2103), UC(0x26A0), UC(0x0394), KC_LCBR, KC_RCBR,                                         KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,
      UC(0x2122), UC(0x2109), UC(0x2623), UC(0x03A9), KC_LBRC, KC_RBRC,                                         KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,   KC_PIPE,
      UC(0x2116), UC(0x00A2), UC(0x03C0), UC(0x221E), KC_LPRN, KC_RPRN, _______, _______,     _______, _______, KC_TILD, _______, _______, _______, _______,  _______,
                                          _______,    _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
*/
