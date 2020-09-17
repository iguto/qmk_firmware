
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "claw44.h"

#define L_BASE 0
#define L_QWERTY (1<<_QWERTY)
#define L_EUCALYN (1<<_EUCALYN)
#define L_EUCALYN2 (1<<_EUCALYN2)
#define L_LOWER (1<<_LOWER)
#define L_LOWER_E (L_LOWER|L_EUCALYN)
#define L_RAISE (1<<_RAISE)
#define L_RAISE_E (L_RAISE|L_EUCALYN)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)
#define L_ADJUST_TRI_E (L_ADJUST|L_RAISE|L_LOWER|L_EUCALYN)
#define L_MISC (1<<_MISC)
#define L_MISC_E (L_MISC|L_EUCALYN)
#define L_EMACS (1<<_EMACS)
#define L_EMACS_E (L_EMACS|L_EUCALYN)
#define L_DOC (1<<_DOC)

char layer_state_str[24];

char text[3] = { 0x18, 0x1e, 0 };
const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    //snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default -- %s", text);
    break;
  case L_QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;
  case L_EUCALYN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Eucalyn");
    break;
  case L_EUCALYN2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Eucalyn2");
    break;
  case L_RAISE:
  case L_RAISE_E:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
  case L_LOWER_E:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
  case L_ADJUST_TRI_E:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  case L_MISC:
  case L_MISC_E:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Misc");
    break;
  case L_EMACS:
  case L_EMACS_E:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Emacs");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
