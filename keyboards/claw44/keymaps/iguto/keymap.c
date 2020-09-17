#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  LOWER,
  RAISE,
  OLED_OFF,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_ KC_TRNS
#define KC_RST RESET

#define KC_L_SPC LT(_LOWER, KC_SPC) // lower
#define KC_R_ENT LT(_RAISE, KC_ENT) // raise
#define KC_G_JA LGUI_T(KC_LANG1) // cmd or win
#define KC_G_EN LGUI_T(KC_LANG2) // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC) // ctrl
#define KC_A_DEL ALT_T(KC_DEL) // alt

#define MISC MO(_MISC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define EMACS MO(_EMACS)
#define D_Q   DF(_QWERTY)
#define T_E   TG(_EUCALYN)
#define T_E2   TG(_EUCALYN2)
#define T_D   TG(_DOC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_TAB , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_BSPC,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LCTL, KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_ENT,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, MISC, 
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                       KC_LALT,  LOWER  , KC_SPC,   KC_LSFT,     KC_RCTL, EMACS   , RAISE  , KC_LGUI 
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),
  [_EUCALYN] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_TAB , KC_Q,    KC_W   ,  KC_COMM, KC_DOT , KC_SCLN ,     KC_M   , KC_R    , KC_D   , KC_Y    , KC_P   , KC_BSPC,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LCTL, KC_A   , KC_O    , KC_E   , KC_I    , KC_U   ,     KC_G   , KC_T    , KC_K   , KC_S    , KC_N,    KC_ENT,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_F   ,     KC_B   , KC_H    , KC_J   , KC_L    , KC_SLSH, MISC, 
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                       KC_LALT,  LOWER  , KC_SPC,   KC_LSFT,     KC_RCTL, EMACS   , RAISE  , KC_LGUI 
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [_EUCALYN2] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_TAB , KC_SCLN, KC_COMM ,  KC_DOT, KC_P    , KC_Q   ,     KC_Y   , KC_G    , KC_D   , KC_M    , KC_F   , KC_BSPC,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LCTL, KC_A   , KC_O    , KC_E   , KC_I    , KC_U   ,     KC_B   , KC_N    , KC_T   , KC_R    , KC_S,    KC_ENT,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_W   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SLSH, MISC, 
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                       KC_LALT,  LOWER  , KC_SPC,   KC_LSFT,     KC_RCTL, EMACS   , RAISE  , KC_LGUI 
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  [_LOWER] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     KC_ESC,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       RESET  , _______, _______, _______,     _______, KC_F13,  _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  //
  ),

  //   \ ^ ! & |  @ = + * % -
  // ( # $ " ' ~  ← ↓ ↑ → ` )
  //         { [  ] }

  [_RAISE] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     KC_ESC , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_GRV,  KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        _______, KC_QUOT, _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, KC_F14 , _______,     _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
  [_ADJUST] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     XXXXXXX, RESET  , T_E2   , T_E    , QWERTY , XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, T_D,     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [_MISC] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8 ,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_PGDN, KC_PGUP, KC_UP  , KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, _______, _______,     _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
  [_EMACS] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, KC_END , _______, _______,     _______, _______, _______, _______, KC_UP,   _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_HOME, _______, KC_DEL , KC_RGHT, KC_ESC,     _______, _______, _______,  _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, KC_LEFT,     KC_DOWN, _______, _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______,  _______, _______,     _______, _______, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [_DOC] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______ , _______, _______,     _______, _______, _______, _______, _______,   _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     KC_3,    KC_1,   KC_1   ,  KC_2, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, _______, _______,     S(KC_ENT), KC_ENT, _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  )

};

void matrix_init_user(void) {
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
  #endif
}

void keyboard_post_init_user(void) {
  set_single_persistent_default_layer(_QWERTY);
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;

  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // raise + misc could be used
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
