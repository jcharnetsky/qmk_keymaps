#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define TAB_RAS  LT(RAISE, KC_TAB)
#define ENT_LWR  LT(LOWER, KC_ENT)
#define GUI_ESC  MT(MOD_LGUI, KC_ESC)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_SU KC_MS_WH_UP
#define KC_SD KC_MS_WH_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (dvorak)
 * ,----------------------------------,                             ,----------------------------------,
 * |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   o  |   e  |   u  |   i  |                             |   d  |   h  |   t  |   n  |   s  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   ;  |   q  |   j  |   k  |   x  |                             |   b  |   m  |   w  |   v  |   z  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | Home |  End |                                                         |   \  |   /  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | Tab  |  GUI |                             |      |ENTER |
 *                      |  +   |   +  |                             | SPACE|  +   |
 *                      | Raise|  ESC |                             |      |Lower |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | Ctrl | Ins  | | Del  | Alt  |
 *                                    '------+------' '------+------'
 *                                    |      | PgDn | | PgUp | Bscp |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_QUOT, KC_COMM, KC_DOT,  KC_P, KC_Y,                                    KC_F, KC_G, KC_C,    KC_R,   KC_L, \
  KC_A,    KC_O,    KC_E,    KC_U, KC_I,                                     KC_D, KC_H, KC_T,    KC_N,   KC_S, \
  KC_SCLN, KC_Q,    KC_J,    KC_K, KC_X,                                     KC_B, KC_M, KC_W,    KC_V,   KC_Z, \
           KC_HOME, KC_END,                                                              KC_BSLS, KC_SLSH,      \
                                         TAB_RAS, GUI_ESC,  KC_SPC,  ENT_LWR,                                   \
                                         KC_LCTL, KC_PSCR,   KC_BSPC, KC_LALT,                                   \
                                         KC_INS,  KC_PGDN,  KC_PGUP, KC_DEL
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      |      |      |      |      |                             | mleft| mdown|  mup |mright| scrUp|
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | left | down |  up  | right| scrDn|
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |      |      |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |  m1  |  m2  |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |  m3  |
 *                                    '------+------' '------+------'
 *                                    |      | RESET| |      |      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  KC_ASTG, ____, ____, ____, ____,                          ____,    ____,    ____,    ____,     ____,      \
  ____, ____,  ____,  ____,  ____,                          KC_ML,   KC_MD,   KC_MU,   KC_MR,    KC_SU,     \
  ____, ____,  ____,  ____,  ____,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_SD,     \
        ____,  ____,                                                          ____,    ____,                \
                                   ____, ____,  KC_MB1, KC_MB2,                                             \
                                   ____, ____, ____,   KC_MB3,                                             \
                                   RESET,____,  ____,   ____                                                \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |  `   |      |      |  -   |      |                             |      |  =   |      |   [  |   ]  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |   0  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | F1   | F2   | F3   | F4   | F5   |                             | F6   | F7   | F8   | F9   | F10  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |      |      |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_GRV,  ____,   ____,    KC_MINS,____,                             ____,    KC_EQL,   ____,    KC_LBRC, KC_RBRC, \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
           KC_F11, KC_F12,                                                               ____,    ____,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

