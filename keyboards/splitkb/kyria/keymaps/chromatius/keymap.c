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
#include <stdio.h>
#include <string.h>
#include "keymap_swedish.h"


#define QWERTY   DF(_QWERTY)
#define WORKMAN  DF(_WORKMAN)
#define WORKMANMAC  DF(_WORKMANMAC)
#define GAMING  DF(_GAMING)

#define ADJUST   MO(_ADJUST)

 // Left-hand home row mods Workman
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_H LCTL_T(KC_H)
#define HOME_T LSFT_T(KC_T)
#define HOME_X ALGR_T(KC_X)

 // Right-hand home row mods Workman
#define HOME_N LSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_O LALT_T(KC_O)
#define HOME_I RGUI_T(KC_I)
#define HOME_DOT ALGR_T(KC_DOT)

 // Left-hand home row mods QWERTY
#define QHOME_A LGUI_T(KC_A)
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LCTL_T(KC_D)
#define QHOME_F LSFT_T(KC_F)
#define QHOME_X ALGR_T(KC_X)

 // Right-hand home row mods QWERTY
#define QHOME_J LSFT_T(KC_H)
#define QHOME_K RCTL_T(KC_J)
#define QHOME_L LALT_T(KC_K)
#define QHOME_ODIA RGUI_T(SE_ODIA)
#define QHOME_DOT ALGR_T(KC_DOT)

 // Custom keys
#define MUTE LCTL(LGUI(LSFT(KC_M)))
#define MUTE_MAC LCTL(KC_D)
#define TERMINAL LCTL(LGUI(LSFT(KC_N)))

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define KC_MAC_DOLLAR LALT(KC_4)

 char wpm_str[10];

 enum layers {
     _WORKMAN = 0,
     _QWERTY,
     _GAMING,
     _WORKMANMAC,
     _SYMBOLSLEFT,
     _SYMBOLSLEFTMAC,
     _SYMBOLSRIGHT,
     _SYMBOLSRIGHTMAC,
     _NUMPAD,
     _FN,
     _NAV,
     _NAVMAC,
     _MEDIA,
     _ADJUST
 };

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_WORKMAN] = LAYOUT(
         KC_NO,           KC_Q,     KC_D,      KC_R,     KC_W,      KC_B,                                                                                                    KC_J,             KC_F,          KC_U,        KC_P,      SE_ARNG,   SE_ADIA,
         KC_BSPACE,       HOME_A,   HOME_S,    HOME_H,   HOME_T,    KC_G,                                                                                                    KC_Y,             HOME_N,        HOME_E,      HOME_O,    HOME_I,    SE_ODIA,
         KC_NO,           KC_Z,     HOME_X,    KC_M,     KC_C,      KC_V,               TERMINAL,            LT(_MEDIA, KC_NO),  MUTE,               KC_NO,                  KC_K,             KC_L,          KC_COMM,     HOME_DOT,  SE_MINS,   SE_APOS,
                                               KC_NO,    KC_ESCAPE, MO(_SYMBOLSRIGHT),  LT(_NAV, KC_SPACE),  KC_DELETE,          LT(_FN, KC_TAB),    LT(_NUMPAD, KC_ENTER),  MO(_SYMBOLSLEFT), OSM(MOD_RSFT), ADJUST
         ),

     [_WORKMANMAC] = LAYOUT(
         KC_NO,          KC_Q,     KC_D,     KC_R,     KC_W,         KC_B,                                                                                           KC_J,                 KC_F,          KC_U,        KC_P,      SE_ARNG,   SE_AT_MAC,
         KC_BSPACE,      HOME_A,   HOME_S,   HOME_H,   HOME_T,       KC_G,                                                                                           KC_Y,                 HOME_N,        HOME_E,      HOME_O,    HOME_I,    SE_ODIA,
         KC_LSFT,        KC_Z,     HOME_X,   KC_M,     KC_C,         KC_V,                  TERMINAL,           KC_TRNS,    KC_NO,            KC_NO,                 KC_K,                 KC_L,          KC_COMM,     HOME_DOT,  SE_MINS,   SE_APOS,
         MUTE_MAC, KC_ESCAPE,    MO(_SYMBOLSRIGHTMAC), LT(_NAV, KC_SPACE), KC_DELETE,  LT(_FN, KC_TAB),  LT(_NUMPAD, KC_ENTER), MO(_SYMBOLSLEFTMAC), OSM(MOD_RSFT), ADJUST
         ),

     [_QWERTY] = LAYOUT(
         KC_NO,           KC_Q,     KC_W,      KC_E,     KC_R,      KC_T,                                                                                                    KC_Y,             KC_U,          KC_I,        KC_O,      KC_P,       SE_ARNG,
         KC_BSPACE,       QHOME_A,  QHOME_S,   QHOME_D,  QHOME_F,   KC_G,                                                                                                    KC_H,             QHOME_J,       QHOME_K,     QHOME_L,   QHOME_ODIA, SE_ADIA,
         KC_NO,           KC_Z,     QHOME_X,   KC_C,     KC_V,      KC_B,               TERMINAL,            LT(_MEDIA, KC_NO),  MUTE,               KC_NO,                  KC_K,             KC_L,          KC_COMM,     HOME_DOT,  SE_MINS,    SE_APOS,
                                               KC_NO,    KC_ESCAPE, MO(_SYMBOLSRIGHT),  LT(_NAV, KC_SPACE),  KC_DELETE,          LT(_FN, KC_TAB),    LT(_NUMPAD, KC_ENTER),  MO(_SYMBOLSLEFT), OSM(MOD_RSFT), ADJUST
         ),

     [_GAMING] = LAYOUT(
         KC_ESCAPE,  KC_Q,     KC_W,     KC_E,     KC_R,         KC_T,                                                                                          KC_J,              KC_F,          KC_U,        KC_P,      SE_ARNG,   SE_ADIA,
         KC_TAB,     KC_A,     KC_S,     KC_D,     KC_F,         KC_G,                                                                                          KC_Y,              HOME_N,        HOME_E,      HOME_O,    HOME_I,    SE_ODIA,
         KC_NO,      KC_Z,     KC_X,     KC_C,     KC_V,         KC_B,                KC_F6,              KC_F7,      MUTE,             KC_NO,                  KC_K,              KC_L,          KC_COMM,     HOME_DOT,  SE_MINS,   SE_APOS,
                                         KC_F2,    KC_F3,        KC_F4,               KC_SPACE,           KC_F5,      LT(_FN, KC_TAB),  LT(_NUMPAD, KC_ENTER),  MO(_SYMBOLSLEFT),  OSM(MOD_RSFT), ADJUST
         ),

     [_SYMBOLSLEFT] = LAYOUT(
         KC_NO,   KC_EXLM, SE_QUES, SE_LCBR, SE_RCBR, SE_DLR,                                        KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
         _______, SE_SCLN, SE_COLN, SE_LPRN, SE_RPRN, KC_HASH,                                       KC_NO,   KC_LSFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_NO,
         KC_NO,   SE_BSLS, SE_SLSH, SE_LBRC, SE_RBRC, SE_AT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,   KC_NO, _______,   _______,   KC_NO,   KC_NO
         ),

     [_SYMBOLSLEFTMAC] = LAYOUT(
         KC_NO,   KC_EXLM,     SE_QUES, SE_LCBR_MAC, SE_RCBR_MAC, KC_MAC_DOLLAR,                                    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
         _______, SE_SCLN,     SE_COLN, SE_LPRN,     SE_RPRN,     KC_HASH,                                          KC_NO,   KC_LSFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_NO,
         KC_NO,   SE_BSLS_MAC, SE_SLSH, SE_LBRC,     SE_RBRC,     SE_AT,         KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                        KC_NO,       KC_NO,       KC_NO,         KC_NO, _______,   KC_NO, _______,  _______, KC_NO,   KC_NO
         ),

     [_SYMBOLSRIGHT] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                                      SE_ACUT, SE_GRV,  SE_TILD, SE_AMPR, KC_PERC, KC_NO,
         _______, KC_LGUI, KC_LALT, KC_LCTRL, KC_LSFT, KC_NO,                                      SE_PLUS, SE_EQL,  SE_CIRC, SE_UNDS, SE_DQUO, SE_APOS,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   SE_ASTR, SE_LESS, SE_GRTR, SE_PIPE, KC_NO,
                                    KC_NO,    KC_NO, _______,   KC_NO, _______,   KC_NO, _______,  KC_NO,   KC_NO,   KC_NO
         ),

     [_SYMBOLSRIGHTMAC] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                                        SE_ACUT_MAC, SE_GRV,     SE_TILD,     SE_AMPR,     KC_PERC,     KC_NO,
         _______, KC_LGUI, KC_LALT, KC_LCTRL, KC_LSFT, KC_NO,                                        SE_PLUS,     SE_EQL,     SE_CIRC,     SE_UNDS,     SE_DQUO,     SE_APOS,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       SE_ASTR,    SE_LESS,     SE_GRTR,     SE_PIPE_MAC, KC_NO,
                                    KC_NO,    KC_NO,   _______,   KC_NO, _______,   KC_NO, _______,  KC_NO,       KC_NO,      KC_NO
         ),

     [_NUMPAD] = LAYOUT(
         KC_NO,   KC_NO,   KC_7,  KC_8,  KC_9,  KC_NO,                                   KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
         _______, SE_PLUS, KC_4,  KC_5,  KC_6,  KC_NO,                                   KC_NO, KC_LSFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_NO,
         KC_NO,   SE_EQL,  KC_1,  KC_2,  KC_3,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,   _______,  _______, _______, KC_NO,
                                  KC_NO, KC_NO, KC_0, _______, _______,  KC_NO, _______, KC_NO, KC_NO,   KC_NO
         ),

     [_FN] = LAYOUT(
         KC_NO,   KC_F12, KC_F7, KC_F8,  KC_F9,  KC_NO,                                       KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
         _______, KC_F11, KC_F4, KC_F5,  KC_F6,  KC_NO,                                       KC_NO,   KC_LSFT, KC_LCTRL, KC_LALT, KC_LGUI, KC_NO,
         KC_NO,   KC_F10, KC_F1, KC_F2,  KC_F3,  KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
                          KC_NO,  KC_NO,  KC_NO, _______, _______,  _______,  _______, KC_NO,   KC_NO,   KC_NO
         ),

     [_NAV] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                                   LSFT(KC_PC_UNDO), KC_PC_PASTE,     KC_PC_COPY,      KC_PC_CUT,       KC_PC_UNDO,   KC_NO,
         _______, KC_LGUI, KC_LALT, KC_LCTRL, KC_LSFT, KC_NO,                                   KC_CAPSLOCK,      KC_LEFT,         KC_DOWN,         KC_UP,           KC_RIGHT,     KC_NO,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_INSERT,        KC_HOME,         KC_PGDOWN,       KC_PGUP,         KC_END,       KC_NO,
                                    KC_NO,    KC_NO,   KC_NO, _______, KC_NO,   KC_NO, _______, KC_NO,            KC_NO,           KC_NO
         ),

     [_NAVMAC] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                                  LSFT(KC_MAC_UNDO), KC_MAC_PASTE, KC_MAC_COPY, KC_MAC_CUT, KC_MAC_UNDO, KC_NO,
         _______, KC_LGUI, KC_LALT, KC_LCTRL, KC_LSFT, KC_NO,                                  KC_CAPSLOCK,       KC_LEFT,      KC_DOWN,     KC_UP,      KC_RIGHT,    KC_NO,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_INSERT,         KC_HOME,      KC_PGDOWN,   KC_PGUP,    KC_END,      KC_NO,
                                    KC_NO,    KC_NO,   KC_NO, _______, KC_NO,  KC_NO, _______, KC_NO,             KC_NO,        KC_NO
         ),

     [_MEDIA] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                                  KC_NO,             KC_NO,        KC_MSTP,     KC_MPLY,    KC_NO,       KC_NO,
         _______, KC_LGUI, KC_LALT, KC_LCTRL, KC_LSFT, KC_NO,                                  KC_NO,             KC_MPRV,      KC_MRWD,     KC_MFFD,    KC_MNXT,     KC_NO,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_NO,             KC_NO,        KC_NO,       KC_NO,      KC_NO,       KC_NO,
                                    KC_NO,    KC_NO,   KC_NO, _______, KC_NO,  KC_NO, _______, KC_NO,             KC_NO,        KC_NO
         ),

     [_ADJUST] = LAYOUT(
         _______, _______, _______, WORKMAN,    _______, _______,                                    _______, _______, _______, _______,  _______, _______,
         _______, _______, _______, WORKMANMAC, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
         _______, _______, _______, GAMING,     QWERTY,  _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                    _______,    _______, _______,_______, _______, _______, _______, _______, _______, _______
         ),

 // /*
 //  * Layer template
 //  *
 //  * ,-------------------------------------------.                              ,-------------------------------------------.
 //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //  *                        |      |      |      |      |      |  |      |      |      |      |      |
 //  *                        |      |      |      |      |      |  |      |      |      |      |      |
 //  *                        `----------------------------------'  `----------------------------------'
 //  */
 };

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
 #ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

            /*
            The case should refer to the second key pressed in the engrams
            */

        case LCTL_T(KC_H):
            /*
            This piece of code nullifies the effect of Left Shift when
            tapping the LCTL_T(KC_H) key.
            This helps rolling over LSFT_T(KC_T) and LCTL_T(KC_H)
            to obtain the intended "th" instead of "H".
            Consequently, capital H can only be obtained by tapping LCTL_T(KC_T)
            and holding RSFT_T(KC_N) (which is the right Shift mod tap).
            */

            if (record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                    /*
                    Only send keys on the press event. Without this
                    I would get 'thth' instead of 'th' on a press-release cycle.
                    */
                    if (record->event.pressed) {
                        tap_code(KC_T);
                        tap_code(KC_H);
                    }
                    add_mods(MOD_BIT(KC_LSHIFT));
                    return false;
                }
            }
            return true;

        case LSFT_T(KC_T):
            /*
            This piece of code nullifies the effect of Left Ctrl when
            tapping the LSFT_T(KC_T) key.
            This helps rolling over LSFT_T(KC_T) and LCTL_T(KC_H)
            to obtain the intended "ht" instead of Ctrl+t which often opens a new tab in a browser.
            */

            if (record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LCTRL)) {
                    unregister_mods(MOD_BIT(KC_LCTRL));
                    if (record->event.pressed) {
                        tap_code(KC_H);
                        tap_code(KC_T);
                    }
                    add_mods(MOD_BIT(KC_LCTRL));
                    return false;
                }
            }
            return true;

        case LSFT_T(KC_N):
            /*
            This piece of code nullifies the effect of Right Ctrl when
            tapping the LSFT_T(KC_N) key.
            This helps rolling over LSFT_T(KC_N) and RCTL_T(KC_E)
            to obtain the intended "en" instead of Ctrl+n which often opens a new window in a browser.
            */

            if (record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_RCTRL)) {
                    unregister_mods(MOD_BIT(KC_RCTRL));
                    if (record->event.pressed) {
                        tap_code(KC_E);
                        tap_code(KC_N);
                    }
                    add_mods(MOD_BIT(KC_RCTRL));
                    return false;
                }
            }
            return true;

    }
    return true;

};


static void render_enso(void) {
    static const char PROGMEM enso[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0x7c,
        0x7c, 0x7c, 0x7c, 0x78, 0x78, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0xf8, 0xfc, 0xff, 0xff, 0x7f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x1c, 0x78, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0xff,
        0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
        0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xcc, 0xf7, 0x78, 0x3c, 0x0f, 0x03,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1e, 0x1c, 0x1c, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(enso, sizeof(enso));
}


static void center_cursor(const char *string_to_print, uint8_t row) {
    uint8_t max_chars = oled_max_chars();
    uint8_t len_to_print = strlen(string_to_print);
    uint8_t padding = ceil((max_chars - len_to_print) / 2);
    oled_set_cursor(padding, row);
}


static void render_status(void) {
    // QMK Logo and version information
    render_enso();
    // Host Keyboard Layer Status
    // Print some blank lines to remove the previous layer string
    oled_set_cursor(0, 6);
    oled_write_P(PSTR("          "), false);
    switch (get_highest_layer(layer_state)) {
            // Note that PSTR is a macro that saves a string to disk memory instead of RAM, and it only takes string literals,
            // so it does not work to refactor the string into a variable and re-use it in two places.
        case _WORKMAN:
            center_cursor("Layer: Base\n", 6);
            oled_write_P(PSTR("Layer: Base\n"), false);
            break;
        case _GAMING:
            center_cursor("Layer: Gaming\n", 6);
            oled_write_P(PSTR("Layer: Gaming\n"), false);
            break;
        case _WORKMANMAC:
            center_cursor("Layer: BaseMac\n", 6);
            oled_write_P(PSTR("Layer: BaseMac\n"), false);
            break;
        case _SYMBOLSLEFT:
            center_cursor("Layer: SymL\n", 6);
            oled_write_P(PSTR("Layer: SymL\n"), false);
            break;
        case _SYMBOLSLEFTMAC:
            center_cursor("Layer: SymL\n", 6);
            oled_write_P(PSTR("Layer: SymL\n"), false);
            break;
        case _SYMBOLSRIGHT:
            center_cursor("Layer: SymR\n", 6);
            oled_write_P(PSTR("Layer: SymR\n"), false);
            break;
        case _SYMBOLSRIGHTMAC:
            center_cursor("Layer: SymR\n", 6);
            oled_write_P(PSTR("Layer: SymR\n"), false);
            break;
        case _NUMPAD:
            center_cursor("Layer: NumPad\n", 6);
            oled_write_P(PSTR("Layer: NumPad\n"), false);
            break;
        case _FN:
            center_cursor("Layer: Fn\n", 6);
            oled_write_P(PSTR("Layer: Fn\n"), false);
            break;
        case _NAV:
            center_cursor("Layer: Nav\n", 6);
            oled_write_P(PSTR("Layer: Nav\n"), false);
            break;
        case _NAVMAC:
            center_cursor("Layer: Nav\n", 6);
            oled_write_P(PSTR("Layer: Nav\n"), false);
            break;
        case _MEDIA:
            center_cursor("Layer: Media\n", 6);
            oled_write_P(PSTR("Layer: Media\n"), false);
            break;
        default:
            center_cursor("Layer: Undef\n", 6);
            oled_write_P(PSTR("Layer: Undef\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    if (IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)) {
        center_cursor("NUMLCK ", 7);
        oled_write_P(PSTR("NUMLCK "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    if (IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)) {
        center_cursor("CAPLCK ", 7);
        oled_write_P(PSTR("CAPLCK "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    if (IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK)) {
        center_cursor("SCRLCK ", 7);
        oled_write_P(PSTR("SCRLCK "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

}


void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_enso();
        oled_set_cursor(0, 6);
        sprintf(wpm_str, "       WPM: %03d", get_current_wpm() / 2);
        oled_write(wpm_str, false);

    }
}
#endif


void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}

