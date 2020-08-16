#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum my_layers {
   _QWERTY,
   _EUCALYN,
   _DVORAK,
   _OVERWATCH,
   _BF,
   _MHW,
   _LOWER,
   _RAISE,
   _MISC,
   _EMACS,
   _ADJUST,
   _MOUSE 
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  DVORAK,
  LOWER,
  RAISE,
  OVERWATCH,
  ADJUST,
  MOUSE,
  //TD_IMON,
  //TD_IMOF,
};

//enum TapDanceDeclearations {
//  IMON,
//  IMOF
//};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MISC  MO(_MISC)

#define LTE_SP LT(_EMACS, KC_SPACE)
#define LC LCTL
#define LW_IMON LT(_LOWER, KC_F23)
#define RS_IMOF LT(_RAISE, KC_F24)
#define TG_OW TG(_OVERWATCH)
#define TG_BF TG(_BF)
#define TG_MHW TG(_MHW)
#define TG_EUCALYN TG(_EUCALYN)
#define ALT_TAB LALT(KC_TAB)


//void dance_imof_finished(qk_tap_dance_state_t *state, void *user_data);
//void dance_imof_reset(qk_tap_dance_state_t *state, void *user_data);
//void dance_imon_finished(qk_tap_dance_state_t *state, void *user_data);
//void dance_imon_reset(qk_tap_dance_state_t *state, void *user_data);
//
//qk_tap_dance_action_t tap_dance_actions[] = {
//    //[IMON] = ACTION_TAP_DANCE_DOUBLE(LOWER, KC_F23),
//    //[IMOF] = ACTION_TAP_DANCE_DOUBLE(RAISE, KC_F24)
//    [IMON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_imon_finished, dance_imon_reset),
//    [IMOF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_imof_finished, dance_imof_reset),
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |RShift|   N  |   M  |   ,  |   .  |   /  |Ctrl  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter|Ema,SP|Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  TG_EUCALYN, TG_OW,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, MISC, \
                  KC_LGUI, KC_LALT,  LOWER,  KC_SPC, KC_SPC,    KC_LCTL, LTE_SP, RAISE,  KC_RALT, KC_RGUI\
),

/* EUCALYN
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   ,  |   .  |   ;  |             |   M  |   R  |   D  |   Y  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   I  |   U  |             |   G  |   T  |   K  |   S  |   N  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   F  |   [  |   ]  |   B  |   H  |   J  |   L  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter |Space |Raise |  Alt | GUI |
 *               `---------------------------------------------------------------------'
 */
[_EUCALYN] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SCLN,                KC_M,    KC_R,    KC_D,    KC_Y,    KC_P,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                   KC_G,    KC_T,    KC_K,    KC_S,    KC_N,    KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_F, _______, _______, KC_B,    KC_H,    KC_J,    KC_L,    KC_SLSH, MISC , \
                  KC_LGUI, KC_LALT,  LOWER,  KC_SPC, KC_SPC,    KC_LCTL, LTE_SP, RAISE,  KC_RALT, KC_RGUI\
),

/* Dvorak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter |Space |Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_LBRC, KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC, KC_LCTL,  KC_ENT, KC_SPC, RAISE,    KC_RALT, KC_RGUI\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |      |      |      |      |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO ~ |ISO | |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV , KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_F6,   _______, _______, _______, _______, KC_PIPE, \
  _______, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,   _______, NOTE_B1,  KC_6 ,   KC_7,    KC_8,    KC_9,    KC_0,    _______, \
                  _______, _______, _______, _______, _______, _______,  KC_F23,  _______, _______, _______\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Del  |   ←  |   ↓  |   →  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 | '    |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_F4,   KC_F5,                             KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, TG_BF,  KC_F12,  KC_QUOT, KC_NUBS, _______, _______, _______, \
                    _______, _______, _______, KC_F24,  _______, _______,         _______, _______, _______, _______\
),

/* Misc
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      | PgUp | PgDn |  ↑   |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ←  |  ↓   |   →  |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_MISC] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, KC_PGDN, KC_PGUP, KC_UP  , _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, TG_MHW ,  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, \
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Emacs
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | C-q  |  C-w | End  |  C-r |  C-t |             | C-y  | C-u  | C-i  | C-o  |   ↑  |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Home | C-s  | Del  |   →  | C-g  |             | Bksp | C-j  | C-k  | C-l  |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      | C-z  | C-x  | C-c  | PgDn |    ← |      |      |    ↓ | C-m  |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_EMACS] = LAYOUT( \
  _______, _______,  _______, _______  , _______ , _______ ,                    _______ , _______ , _______ , _______ , _______, _______, \
  _______, LC(KC_Q), LC(KC_W), KC_END  , LC(KC_R), LC(KC_T),                    LC(KC_Y), LC(KC_U), LC(KC_I), LC(KC_O), KC_UP  , _______, \
  _______, KC_HOME , LC(KC_S), KC_DEL  , KC_RGHT , LC(KC_G),                    KC_BSPC , LC(KC_J), LC(KC_K), LC(KC_L), _______, _______, \
  _______, LC(KC_Z), LC(KC_C), LC(KC_V), KC_PGDN , KC_LEFT , _______, _______,  KC_DOWN , LC(KC_M), _______ , _______ , _______, _______, \
                     _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Overwatch
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |  Esc |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   h  |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      | SPC  |IME ON|      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_OVERWATCH] = LAYOUT( \
  XXXXXXX, _______, _______, _______, _______, KC_ESC,                     _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_H,    _______,  _______, _______, _______, _______, _______, _______, \
                    KC_F23 , XXXXXXX, KC_SPC,  _______, KC_NO, _______,  _______, _______, _______, _______\
),

/* BF
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |XXXXXX|   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |RShift|   N  |   M  |   ,  |   .  |   /  |Ctrl  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter|Ema,SP|Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_BF] = LAYOUT( \
  KC_NO,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_ESC, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC,  TG_BF,  KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, MISC, \
                  KC_LGUI, KC_LALT,  LW_IMON,  KC_SPC, KC_F12,  KC_ENT, LTE_SP, RS_IMOF,   KC_RALT, KC_RGUI\
),

/* MHW
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | ~    |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |RShift|   N  |   M  |   ,  |   .  |   /  |Ctrl  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter|Ema,SP|Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_MHW] = LAYOUT( \
  KC_NO,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_ESC, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_6,                    KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_7,                    KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_8,  KC_LBRC,  TG_MHW,  KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_NO, \
                  KC_LGUI, KC_LALT,  LW_IMON,  KC_SPC, KC_ENT,  KC_ENT, LTE_SP, RS_IMOF,   KC_RALT, KC_RGUI\
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      | DEBUG|Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC, \
  KC_CAPS, _______, DEBUG, RGB_RMOD,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______, \
  QWERTY,  EUCALYN, DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* MOUSE (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      | DEBUG|Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_MOUSE] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)

};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _OVERWATCH:
      rgblight_enable();
      rgblight_mode(1);
      rgblight_sethsv(110, 255, 120);
      break;
    case _BF:
      rgblight_enable();
      rgblight_mode(1);
      rgblight_sethsv(170, 255, 255);
      break;
    case _MHW:
      rgblight_enable();
      rgblight_mode(1);
      rgblight_sethsv(0, 100, 80);
      break;
    default:
      rgblight_disable();
  }

  state = update_tri_layer_state(state, _RAISE, _MISC, _MOUSE);
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case EUCALYN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_EUCALYN);
      }
      return false;
     
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

//enum {
//  SINGLE_TAP = 1,
//  SINGLE_HOLD = 2,
//  DOUBLE_TAP = 3,
//};

// void dance_imof_finished(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     layer_on(_LOWER);
//   } else {
//     //register_code(KC_F23);
//     register_code(KC_F13);
//   }
// }
// 
// void dance_imof_reset(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     layer_off(_LOWER);
//   } else {
//     //unregister_code(KC_F23);
//     unregister_code(KC_F13);
//   }
// }
// 
// void dance_imon_finished(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     layer_on(_RAISE);
//   } else {
//     //register_code(KC_F24);
//     register_code(KC_F14);
//   }
// }
// 
// void dance_imon_reset(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     layer_off(_RAISE);
//   } else {
//     //unregister_code(KC_F24);
//     unregister_code(KC_F14);
//   }
// }
// 
