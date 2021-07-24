/*
Copyright 2018 Jack Humbert <jack.humb@gmail.com>

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

#pragma once

#define MCP23018_DEFAULT_ADDRESS 0b0100000

#define ML_LED_1(status) writePin(B5, (bool)status)
#define ML_LED_2(status) writePin(B4, (bool)status)
#define ML_LED_3(status) writePin(B3, (bool)status)

#define ML_LED_4(status) mcp23018_leds[0] = (bool)status
#define ML_LED_5(status) mcp23018_leds[1] = (bool)status
#define ML_LED_6(status) mcp23018_leds[2] = (bool)status

#include "quantum.h"

// clang-format off
#define LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k10, k11, k12, k13, k14, k15, k16 }, \
    { k20, k21, k22, k23, k24, k25, k26 }, \
    { k30, k31, k32, k33, k34, k35, KC_NO }, \
    { k40, k41, k42, k43, k44, KC_NO, KC_NO }, \
    { k50, k51, k52, k53, KC_NO, KC_NO, KC_NO }, \
\
    { k60, k61, k62, k63, k64, k65, k66 }, \
    { k70, k71, k72, k73, k74, k75, k76 }, \
    { k80, k81, k82, k83, k84, k85, k86 }, \
    { KC_NO,k91, k92, k93, k94, k95, k96 }, \
    { KC_NO, KC_NO, ka2, ka3, ka4, ka5, ka6 }, \
    { KC_NO, KC_NO, KC_NO, kb3, kb4, kb5, kb6  } \
}
// clang-format on

// clang-format off
#define LED_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
) \
{ \
    { k00, k10, k20, k30, k40, k01, k11, k21, k31, k41, k02, k12, k22, k32, k42, k03, k13, k23, k33, k43, k04, k14, k24, k34, k44, k05, k15, k25, k35, k06, k16, k26, k50, k51, k52, k53, \
      k66, k76, k86, k96, ka6, k65, k75, k85, k95, ka5, k64, k74, k84, k94, ka4, k63, k73, k83, k93, ka3, k62, k72, k82, k92, ka2, k61, k71, k81, k91, k60, k70, k80, kb6, kb5, kb4, kb3} \
}
// clang-format on


enum planck_ez_keycodes {
    TOGGLE_LAYER_COLOR = SAFE_RANGE,
    LED_LEVEL,
    ML_SAFE_RANGE,
};

typedef union {
    uint32_t raw;
    struct {
        bool    disable_layer_led : 1;
        bool    rgb_matrix_enable : 1;
        bool    led_level : 1;
        uint8_t led_level_res : 2;  // DO NOT REMOVE
    };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;
