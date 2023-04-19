/* Copyright 2021 HellSingCoder choji-crohn
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
#include "keymap_jp.h"
#include "twpair_on_jis.h"

enum custom_keycodes {
    WINID = SAFE_RANGE,
    TGPID,
    HDCPY,
    DERWE,
    WINLD,
};

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define KC_L_SPC LT(_LOWER, KC_SPC)  // lower
#define KC_R_ENT LT(_RAISE, KC_ENT)  // raise
#define KC_ADJ MO(_ADJUST)           // adjust
#define KC_S_HEN SFT_T(KC_HENK)      // shift
#define KC_S_MHN SFT_T(KC_MHEN)      // shift
#define KC_G_L LGUI_T(KC_LEFT)       // win
#define KC_C_BS CTL_T(KC_BSPC)       // ctrl
#define KC_C_DEL CTL_T(KC_DEL)       // ctrl
#define KC_A_DWN ALT_T(KC_DOWN)      // alt
#define KC_A_UP ALT_T(KC_UP)         // alt
#define KC_S_CL S(KC_CAPS)           // caps lock
#define KC_CSA C(S(KC_A))            // ctrl+shift+A
#define KC_CY C(KC_Y)                // ctrl+Y

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.   ,---------+---------+---------+---------+---------+---------.
        KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,     KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_MINS ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        KC_TAB  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,     KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        KC_G_L  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,     KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RIGHT,
    //`---------+---------+---------+---------+---------+---------/   |---------+---------+---------+---------+---------+---------'
                            KC_A_DWN, KC_S_MHN, KC_L_SPC, KC_C_BS ,     KC_C_DEL, KC_R_ENT, KC_S_HEN, KC_A_UP
    //                    `---------+---------+---------+---------'   `---------+---------+---------+---------'
    ),

    [_LOWER] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.   ,---------+---------+---------+---------+---------+---------.
        WINID   ,  TGPID  , XXXXXXX , KC_F8   , KC_CY   , HDCPY   ,     XXXXXXX , XXXXXXX , XXXXXXX , KC_PSCR , KC_INS  , XXXXXXX ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        KC_S_CL , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, KC_LCBR , KC_RCBR ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        KC_CSA  , KC_CIRC , KC_AMPR , KC_LPRN , KC_RPRN , KC_TILD ,     KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_PIPE , KC_APP  ,
    //`---------+---------+---------+---------+---------+---------/   |---------+---------+---------+---------+---------+---------'
                            KC_R_ENT, KC_C_DEL, _______ , _______ ,     _______ , KC_ADJ  , _______ , _______
    //                    `---------+---------+---------+---------'   `---------+---------+---------+---------'
    ) ,   
    
    [_RAISE] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.   ,---------+---------+---------+---------+---------+---------.
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,     KC_GRV  , KC_EQL  , KC_PPLS , KC_PAST , KC_PSLS , KC_MINS ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,     KC_LBRC , KC_RBRC , _______ , _______ , WINLD   , DERWE   ,
    //`---------+---------+---------+---------+---------+---------/   |---------+---------+---------+---------+---------+---------'
                            _______ , _______ , KC_ADJ  , _______ ,     _______ , _______ , _______ , _______
    //                    `---------+---------+---------+---------'   `---------+---------+---------+---------'
    ),

    [_ADJUST] = LAYOUT(
    //,---------+---------+---------+---------+---------+---------.   ,---------+---------+---------+---------+---------+---------.
        _______ , KC_WH_U , KC_BTN2 , KC_MS_U , KC_BTN1 , XXXXXXX ,     XXXXXXX , KC_7    , KC_8    , KC_9    , RGB_TOG , RGB_HUI ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        _______ , KC_WH_D , KC_MS_L , KC_MS_D , KC_MS_R , XXXXXXX ,     XXXXXXX , KC_4    , KC_5    , KC_6    , RGB_SAI , RGB_VAI ,
    //|---------+---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------+---------|
        _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     KC_0    , KC_1    , KC_2    , KC_3    , RGB_MOD , _______ ,
    //`---------+---------+---------+---------+---------+---------/   |---------+---------+---------+---------+---------+---------'
                            _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
    //                    `---------+---------+---------+---------'   `---------+---------+---------+---------'
    ),
};

#ifdef OLED_ENABLE

void render_logo(void) {
    static const char PROGMEM logo[] = {0x81, 0x82, 0x83, 0x84, 0x85, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5,
                                        0x86, 0x87, 0x88, 0x89, 0x8a, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa,
                                        0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0};
    oled_write_P(logo, false);
}

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int  current_wpm = 0;
led_t led_state;

bool should_process_keypress(void) { return true; }  // OLED DATA SYNC OPTION

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

/* KEYBOARD PET END */


void render_layer_state(void) {
    oled_write("Layer", false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

void render_lock_state(void) {
    // Host Keyboard LED Status
    oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP  ") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR  ") : PSTR("     "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
}

void render_mod_status2(uint8_t modifiers) {
    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

char keylog_str[24]  = {};
char keylogs_str[15] = {};
int  keylogs_str_idx = 0;

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', ' ', '-', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d:%c", record->event.key.row, record->event.key.col, keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

const char *read_keylog(void) { return keylog_str; }
const char *read_keylogs(void) { return keylogs_str; }

static void print_logo_narrow(void) {
    render_logo();
    oled_set_cursor(0, 7);
    render_mod_status2(get_mods()|get_oneshot_mods());
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
}

static void print_status_narrow(void) {
    oled_set_cursor(0, 0);
    render_lock_state();
    oled_set_cursor(0, 4);
    render_layer_state();
    oled_set_cursor(0, 7);
    render_mod_status(get_mods()|get_oneshot_mods());

    /* KEYBOARD PET RENDER START */

    render_luna(0, 10);

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(2, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);
    oled_set_cursor(2, 15);
    oled_write("wpm", false);

    /* KEYBOARD PET RENDER END */

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void oled_task_user(void) {

    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

   if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    if (!twpair_on_jis(keycode, record))
        return false;

    switch (keycode) {
        case WINID:
            if (record->event.pressed) {
                // when keycode WINID is pressed
                SEND_STRING( SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_TAP(X_DELETE) SS_UP(X_LALT) SS_UP(X_LCTRL) SS_DELAY(1500) "hornet23" SS_DELAY(500) SS_TAP(X_ENTER) );
            } else {
                // when keycode WINID is released
            }
            break;

        case TGPID:
            if (record->event.pressed) {
                // when keycode TGPID is pressed
                SEND_STRING("198012" SS_DELAY(500) SS_TAP(X_TAB) SS_DELAY(300) "hornet" SS_TAP(X_TAB) SS_DELAY(300) SS_TAP(X_ENTER));
            } else {
                // when keycode TGPID is released
            }
            break;

        case HDCPY:
            if (record->event.pressed) {
                // when keycode HDCPY is pressed
                SEND_STRING( SS_DOWN(X_LGUI) SS_LSFT("s") SS_UP(X_LGUI) );
            } else {
                // when keycode HDCPY is released
            }
            break;

        case DERWE:
            if (record->event.pressed) {
                // when keycode DERWE is pressed
                SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_DELAY(300) SS_TAP(X_RIGHT) SS_DELAY(100) SS_DOWN(X_LALT) SS_TAP(X_TAB) SS_UP(X_LALT) );
            } else {
                // when keycode DERWE is released
            }
            break;

        case WINLD:
            if (record->event.pressed) {
                // when keycode WINLD is pressed
                SEND_STRING( SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_TAP(X_DOWN) SS_UP(X_LGUI) );
            } else {
                // when keycode WINLD is released
            }
            break;

        /* KEYBOARD PET STATUS START */

        case KC_C_BS:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_C_DEL:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */

    }

    return true;
}
