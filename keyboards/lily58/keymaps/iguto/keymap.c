#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#define USB_POLLING_INTERVAL_MS 2

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#include "naginata.h"
NGKEYS naginata_keys;

#define _QWERTY 0
#define _NAGINATA 4
#define _LOWER 5
#define _RAISE 10
#define _TEN_KEY 11
#define _EMACS 12
#define _MISC 15 
#define _ADJUST 20

enum custom_keycodes {
  QWERTY = NG_SAFE_RANGE,
  MAC,
  LOWER,
  RAISE,
  TEN_KEY,
  EMACS,
  MISC,
  ADJUST,
  NAGINATA,
  EISU,
  KANA2,
  IMEON,
  IMEOFF,
  EMACS,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MISC MO(_MISC)
#define TEN_KEY TG(_TEN_KEY)
#define EMACS MO(_EMACS)
#define MACCMD CMD_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  TEN_KEY,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MISC, \
                             KC_LGUI, KC_LALT, LOWER, KC_SPC,   EMACS ,   RAISE,   KC_BSPC, KC_RGUI \
),
 [_NAGINATA] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,\
  _______, NG_Q,   NG_W,    NG_E,    NG_R,    NG_T,                         NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,    _______,\
  _______, NG_A,   NG_S,    NG_D,    NG_F,    NG_G,                         NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN, _______,\
  _______, NG_Z,   NG_X,    NG_C,    NG_V,    NG_B,     _______,  _______,  NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH, _______,\
                             _______, _______, _______, NG_SHFT,  NG_SHFT, _______, _______, _______ \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_ESC , _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  _______, KC_1   , KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,   KC_9   , KC_0   , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______, _______,\
                             _______, _______, _______, _______, IMEOFF,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, _______, _______, _______, _______, _______,                     KC_GRV , KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LSFT, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  _______, KC_QUOT, KC_NUBS, _______, _______, _______,\
                             _______, _______, _______,  IMEON,  _______,  _______, _______, _______ \
),


/* TEN_KEY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_TEN_KEY] = LAYOUT( \
  _______, KC_BSPC, XXXXXXX, KC_SLSH, S(KC_8), XXXXXXX,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_MINS,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, XXXXXXX,  KC_4,    KC_5,    KC_6,   S(KC_EQL),                   _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS, \
  _______, XXXXXXX,  KC_1,    KC_2,    KC_3,    KC_0,     _______, _______, KC_MINS, KC_QUOT, KC_NUBS, _______, _______, _______,\
                    KC_DOT, _______, _______,  KC_PENT,   _______, _______, _______, _______ \
),

[_EMACS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, KC_UP  , _______, \
  _______, _______, _______, KC_END , _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_HOME, _______, KC_DEL , KC_RGHT, KC_ESC ,                     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_LEFT,   _______, _______, KC_DOWN, _______, _______, _______, _______, _______,\
                    _______, _______, _______, _______,   _______, _______, _______, _______ \
),

/* MISC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MISC] = LAYOUT( \
  _______, _______, _______, _______, _______,  _______,                    _______, _______, _______, _______, _______, _______,\
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,  KC_F6  ,                    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,\
  _______, _______, _______, _______, NAGINATA, _______,                    _______, KC_PGDN, KC_PGUP, KC_UP,   _______, _______,\
  _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,\
                             _______, _______,  _______, _______, _______,  _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAC    , RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    uint16_t ngonkeys[] = {};
    uint16_t ngoffkeys[] = {};
    set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

//const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);


/****** old oled setting 
void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
******/

void oled_task_user(void) {
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("Lower\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("Raise\n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("Adjust\n"), false);
      break;
    case _MISC:
      oled_write_P(PSTR("Misc\n"), false);
      break;
    case _NAGINATA:
      oled_write_P(PSTR("NAGINATA\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("undefined"), false);
  }
}

#endif//SSD1306OLED

bool is_mac = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case NAGINATA:
      if (record->event.pressed) {
        if (naginata_state()) {
          naginata_off();
        } else {
          naginata_on();
        }
      }
      return false;
      break;
    case MAC:
      if (record->event.pressed) {
        is_mac = !is_mac;
      }
      return false;
      break;
    case IMEON:
      if (record->event.pressed) {
        if (is_mac) {
          register_code(KC_LANG1);
        } else {
          register_code(KC_F14);
        }
      } else {
        if (is_mac) {
          unregister_code(KC_LANG1);
        } else {
          unregister_code(KC_F14);
        }
      }
      return false;
      break;
    case IMEOFF:
      if (record->event.pressed) {
        if (is_mac) {
          register_code(KC_LANG2);
        } else {
          register_code(KC_F13);
        }
      } else {
        if (is_mac) {
          unregister_code(KC_LANG2);
        } else {
          unregister_code(KC_F13);
        }
      }
      return false;
      break;
  }
  if (!process_naginata(keycode, record)) {
    return false;
  }
  return true;
}

