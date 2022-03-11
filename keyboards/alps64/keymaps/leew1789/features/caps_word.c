// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

/*
The code checks the mod bits on each key event, enabling Caps Word when both left
and right shifts are active.
While enabled, Caps Word automatically presses and releases left shift (KC_LSFT) as
needed so that letters are shifted and other keys are not. The word continues while
typing a–z, 0–9, -, _, and backspace. Any other key is considered “word breaking”
and disables Caps Word. You can edit the switch statement at the end of the function to
adjust which keys count as word breaking.
*/

#include "caps_word.h"

bool process_caps_word(uint16_t keycode, keyrecord_t* record) {
  static bool caps_word_enabled = false;
  static bool shifted = false;
  
  if (!caps_word_enabled) {
    // Pressing both shift keys at the same time enables caps word.
    if (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
      == MOD_MASK_SHIFT) {
    clear_mods();
    clear_oneshot_mods();
    shifted = false;
    caps_word_enabled = true;
    return false;
  }
  return true;
}

if (!record->event.pressed) { return true; }

if (!((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT)) {
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      // Earlier return if this has not been considered tapped yet.
      if (record->tap.count == 0) { return true; }
      // Get the base tapping keycode of a mod- or layer-tap key.
      keycode &= 0xff;
    }
         
  switch (keycode) {
    // Letter keys should be shifted.
    case KC_A ... KC_Z:
      if (!shifted) { register_code(KC_LSFT); }
      shifted = true;
      return true;
      
    // Keycodes that continue caps word but shouldn't get shifted.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
      if (shifted) { unregister_code(KC_LSFT); }
      shifted = false;
      return true;
    // Any other keycode disables caps word.
  }
}

  // Disable caps word.
  caps_word_enabled = false;
  if (shifted) { unregister_code(KC_LSFT); }
  shifted = false;
  return true;
}
