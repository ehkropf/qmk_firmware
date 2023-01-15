/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum local_keycodes
{
    M_RMD_1 = SAFE_RANGE,
    M_RMD_2,
    M_RMD_3,
    M_RMD_4,
    M_RMD_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC        F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      `          1        2        3        4        5        6        7        8        9        0         -       (=)      BackSpc       Del
//      Tab        Q        W        E        R        T        Y        U        I        O        P        [        ]                      PgUp
//      Ct_l/ESC   A        S        D        F        G        H        J        K        L        ;        '        #        Enter         PgDn
//      Sh_L       \        Z        X        C        V        B        N        M        ,        .        /        Sh_R     Up            End
//      FN         Alt_L    GUI_L                      SPACE                               GUI_R    Alt_R    Ct_R     Left     Down          Right

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+#. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [0] = LAYOUT(
            // Mac base layer
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TG(1),    KC_MUTE,
        KC_NUBS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_PGUP,
        MT(MOD_LCTL, KC_ESC),
                  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_GRV,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        MO(2),    KC_LALT,  KC_LGUI,                                KC_SPC,                       KC_RGUI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [1] = LAYOUT(
            // Windows overlay
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_NUBS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______
    ),

    [2] = LAYOUT(
            // Function overlay
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  M_RMD_1,  M_RMD_2,  M_RMD_3,  M_RMD_4,  _______,  _______,  _______,  _______,  _______,  M_RMD_0,  _______,  _______,  _______,  RGB_TOG,
        _______,  KC_MRWD,  KC_MPLY,  KC_MFFD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BRID,  KC_BRIU,            RGB_MOD,
        _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,  QK_BOOT,  _______,  RGB_RMOD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_VAI,  _______,
        _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  RGB_VAD,  _______
    )
};


bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode)
    {
        case M_RMD_2:
            rgb_matrix_sethsv_noeeprom(0, 0xff, 0xff);
            rgb_matrix_mode(RGB_MATRIX_BREATHING);
            break;
        case M_RMD_3:
            rgb_matrix_sethsv_noeeprom(0, 0xff, 0xff);
            rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_SAT);
            break;
        case M_RMD_4:
            rgb_matrix_sethsv_noeeprom(0, 0xff, 0xff);
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
        case M_RMD_1:
            rgb_matrix_sethsv_noeeprom(0, 0xff, 0xff);
            rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
            break;
        case M_RMD_0:
            rgb_matrix_mode(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(0, 0, 0);
    }
    return true;
}

bool rgb_matrix_indicators_kb(void)
{
    if (!rgb_matrix_indicators_user()) return false;

    if (layer_state_is(1)) rgb_matrix_set_color(70, 0xff, 0x45, 0x00);

    return true;
}
