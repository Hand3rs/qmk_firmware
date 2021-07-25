#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#include "song_list.h"
#include "musical_notes.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL


#define INTERNATIONALE W__NOTE(_REST), HD_NOTE(_E6), Q__NOTE(_D6), B__NOTE(_C6), \
WD_NOTE(_G5), H__NOTE(_A5), S__NOTE(_REST), B__NOTE(_A5), W__NOTE(_F5), HD_NOTE(_D6), Q__NOTE(_C6), B__NOTE(_B5), WD_NOTE(_A5), H__NOTE(_G5), B__NOTE(_E6), W__NOTE(_REST), W__NOTE(_E6), B__NOTE(_G6), \
W__NOTE(_F6), W__NOTE(_E6), H__NOTE(_D6), H__NOTE(_CS6), H__NOTE(_D6), H__NOTE(_E6), WD_NOTE(_F6), S__NOTE(_REST), H__NOTE(_F6), WD_NOTE(_E6), S__NOTE(_REST), H__NOTE(_E6), WD_NOTE(_D6), S__NOTE(_REST), H__NOTE(_D6), B__NOTE(_C6)

#define SLIENCE B__NOTE(_REST), B__NOTE(_REST), B__NOTE(_REST), B__NOTE(_REST), B__NOTE(_REST)

float escape_song[][2] = SONG(INTERNATIONALE);

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  FR_LSPO,
  FR_RSPC,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5
};


enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    WARP,  // warp layer
    GW2,   // GW2 optimized
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_EQUAL,            KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                        TD(DANCE_5),      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TG(SYMB),                       TG(1),            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_TAB,              KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           LT(WARP,KC_NO),                 KC_MEH,           KC_H,           KC_J,           KC_K,           KC_L,           TD(DANCE_3),    LGUI_T(KC_QUOTE),
    KC_LSHIFT,           LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                                                             KC_N,           KC_M,           KC_COMMA,       KC_DOT,         TD(DANCE_4),    KC_RSHIFT,
    LT(SYMB,KC_GRAVE),   _______,        KC_LALT,        TD(DANCE_0),    TD(DANCE_1),                    KC_LCTRL,                       LCTL_T(KC_ESCAPE),                KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(SYMB),
                                                                         KC_SPACE,       KC_BSPACE,      TD(DANCE_2),                    KC_LALT,          KC_TAB,         KC_ENTER
  ),
  [SYMB] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                             _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,                             _______,        KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    _______,        KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       _______,                             _______,        KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     _______,
    _______,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                                             KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      _______,
    _______,        KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,                RGB_MOD,                             RGB_TOG,                        _______,        KC_DOT,         KC_0,           KC_EQUAL,       _______,
                                                                    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                  RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [MDIA] = LAYOUT_moonlander(
    AU_TOG,         _______,        _______,        _______,        _______,        _______,        _______,                             _______,     _______,          _______,              _______,              _______,              _______,   RESET,
    MU_TOG,         _______,        _______,        KC_MS_UP,       _______,        KC_MS_WH_UP,    _______,                             _______,     _______,          KC_END,               _______,              _______,              _______,   _______,
    MU_MOD,         _______,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  _______,                             _______,     KC_HOME,          _______,              _______,              LCTL(KC_PSCREEN),     _______,   KC_MEDIA_PLAY_PAUSE,
    KC_CAPSLOCK,    _______,        _______,        _______,        _______,        _______,                                                          _______,          _______,              KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  _______,   _______,
    WEBUSB_PAIR,    _______,        _______,        KC_MS_BTN1,     KC_MS_BTN2,                     KC_MS_BTN3,                          _______,                       KC_AUDIO_VOL_UP,      KC_AUDIO_VOL_DOWN,    KC_AUDIO_MUTE,        _______,   _______,
                                                                    KC_MS_BTN1,     KC_MS_BTN2,     _______,                             _______,     _______,          KC_WWW_BACK
  ),
  [WARP] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                             _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        KC_E,           _______,        _______,        _______,        _______,                             _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        TO(BASE),       TO(GW2),        _______,                             _______,        _______,        _______,        _______,        _______,        _______,        _______,
    KC_CAPSLOCK,    _______,        _______,        _______,        _______,        _______,                                                             _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,                        _______,                             _______,                        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                             _______,        _______,        _______
  ),
  [GW2] = LAYOUT_moonlander(
    KC_O,           _______,        _______,        _______,        _______,        _______,        _______,                             KC_ESCAPE,      _______,        _______,        _______,        _______,        _______,        TO(BASE),
    KC_H,           KC_GRAVE,       _______,        KC_2,           KC_3,           KC_4,           _______,                             _______,        _______,        _______,        _______,        KC_O,           _______,        _______,
    KC_0,           KC_TAB,         KC_1,           KC_W,           KC_X,           KC_5,           KC_M,                                KC_G,           KC_H,           _______,        _______,        _______,        _______,        _______,
    KC_9,           KC_8,           KC_A,           KC_S,           KC_D,           KC_F,                                                                _______,        _______,        KC_COMMA,       _______,        _______,        _______,
    KC_7,           KC_6,           _______,        _______,        _______,                        _______,                             _______,                        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                             _______,        _______,        _______
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define white__ 255, 255, 255
#define black__ 0, 0, 0
#define red____ 255, 0, 0
#define green__ 0, 255, 0
#define blue___ 0, 0, 255
#define yellow_ 255, 255, 0
#define magenta 255, 0, 255
#define cyan___ 0, 255, 255
#define orange_ 255, 88, 0
#define brown__ 150, 50, 0

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = {
    {white__},     {white__},      {white__},      {white__},      {white__},      {white__},      {white__},                             {white__},      {white__},      {white__},      {white__},      {white__},      {white__},      {white__},
    {white__},     {white__},      {white__},      {white__},      {white__},      {white__},      {white__},                             {white__},      {white__},      {white__},      {white__},      {white__},      {white__},      {white__},
    {white__},     {white__},      {white__},      {white__},      {white__},      {white__},      {white__},                             {white__},      {white__},      {white__},      {white__},      {white__},      {white__},      {white__},
    {white__},     {white__},      {white__},      {white__},      {white__},      {white__},                                                             {white__},      {white__},      {white__},      {white__},      {white__},      {white__},
    {white__},     {white__},      {white__},      {white__},      {white__},                      {white__},                             {white__},                      {white__},      {white__},      {white__},      {white__},      {white__},
                                                                   {white__},      {white__},      {white__},                             {white__},      {white__},      {white__}
    },
    [SYMB] = {
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},                                                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},                      {black__},                             {black__},                      {black__},      {black__},      {black__},      {black__},      {black__},
                                                                   {black__},      {black__},      {black__},                             {black__},      {black__},      {black__}
    },
    [MDIA] = {
    {blue___},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {magenta},
    {blue___},     {black__},      {black__},      {yellow_},      {black__},      {black__},      {black__},                             {black__},      {black__},      {red____},      {black__},      {black__},      {black__},      {black__},
    {blue___},     {black__},      {yellow_},      {yellow_},      {yellow_},      {black__},      {black__},                             {black__},      {red____},      {black__},      {black__},      {red____},      {black__},      {red____},
    {red____},     {black__},      {black__},      {black__},      {black__},      {black__},                                                             {black__},      {black__},      {red____},      {red____},      {black__},      {black__},
    {black__},     {black__},      {black__},      {yellow_},      {yellow_},                      {yellow_},                             {black__},                      {red____},      {red____},      {red____},      {black__},      {black__},
                                                                   {yellow_},      {yellow_},      {black__},                             {black__},      {black__},      {red____}
    },
    [WARP] = {
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {red____},      {red____},      {red____},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},      {black__},                                                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {black__},     {black__},      {black__},      {black__},      {black__},                      {black__},                             {black__},                      {black__},      {black__},      {black__},      {black__},      {black__},
                                                                   {black__},      {black__},      {black__},                             {black__},      {black__},      {black__}
    },
    [GW2] = {
    {brown__},     {black__},      {black__},      {black__},      {black__},      {black__},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {magenta},
    {brown__},     {white__},      {black__},      {red____},      {red____},      {red____},      {black__},                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {yellow_},     {green__},      {red____},      {orange_},      {green__},      {red____},      {white__},                             {brown__},      {brown__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {magenta},     {magenta},      {orange_},      {orange_},      {orange_},      {orange_},                                                             {black__},      {black__},      {black__},      {black__},      {black__},      {black__},
    {magenta},     {red____},      {black__},      {black__},      {black__},                      {black__},                             {black__},                      {black__},      {black__},      {black__},      {black__},      {black__},
                                                                   {black__},      {black__},      {black__},                             {black__},      {black__},      {black__}
    }
};
const int LED_moonlander_map[72] = {0, 5, 10, 15, 20, 25, 29, 65, 61, 56, 51, 46, 41, 36, 1, 6, 11, 16, 21, 26, 30, 66, 62, 57, 52, 47, 42, 37, 2, 7, 12, 17, 22, 27, 31, 67, 63, 58, 53, 48, 43, 38, 3, 8, 13, 18, 23, 28, 64, 59, 54, 49, 44, 39, 4, 9, 14, 19, 24, 35, 71, 60, 55, 50, 45, 40, 32, 33, 34, 70, 69, 68};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(LED_moonlander_map[i],
      f * ledmap[layer][i][0],
      f * ledmap[layer][i][1],
      f * ledmap[layer][i][2]);
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
      break;
    case SYMB:
      set_layer_color(SYMB);
      break;
    case MDIA:
      set_layer_color(MDIA);
      break;
    case WARP:
      set_layer_color(WARP);
      break;
    case GW2:
      set_layer_color(GW2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FR_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_LPRN);
      return false;
    case FR_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_RPRN);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_SCOLON));
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_SCOLON)); break;
        case SINGLE_HOLD: layer_on(MDIA); break;
        case DOUBLE_TAP: register_code16(KC_SCOLON); break;
        case DOUBLE_HOLD: register_code16(KC_SCOLON); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_SCOLON)); register_code16(LSFT(KC_SCOLON));
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
        case SINGLE_HOLD: layer_off(MDIA); break;
        case DOUBLE_TAP: unregister_code16(KC_SCOLON); break;
        case DOUBLE_HOLD: unregister_code16(KC_SCOLON); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_SCOLON)); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_SLASH));
        tap_code16(LSFT(KC_SLASH));
        tap_code16(LSFT(KC_SLASH));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_SLASH));
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_SLASH)); break;
        case SINGLE_HOLD: register_code16(KC_RCTRL); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_SLASH)); register_code16(LSFT(KC_SLASH));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_SLASH)); break;
        case SINGLE_HOLD: unregister_code16(KC_RCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_SLASH)); break;
    }
    dance_state[4].step = 0;
}

// International escape key
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: set_layer_color(2); PLAY_SONG(escape_song); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[5].step = 0;
}
qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};

