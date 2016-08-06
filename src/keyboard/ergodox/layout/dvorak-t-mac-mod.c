/* ----------------------------------------------------------------------------
 * ergoDOX layout : Dvorak (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	_esc,	_1,	_2,	_3,	_4,	_5,	_home,	
	_tab,	_quote,	_comma,	_period,	_P,	_Y,	_slash,	
	_capsLock,	_A,	_O,	_E,	_U,	_I,	
	_shiftL,	_semicolon,	_Q,	_J,	_K,	_X,	_bracketL,	
	_ctrlL,	_grave,	_X,	_C,	_V,	
	1,	2,	
	0,	0,	_altL,	
	_space,	_enter,	_guiL,	
	// right hand
	_end,	_6,	_7,	_8,	_9,	_0,	_bs,	
	_backslash,	_F,	_G,	_C,	_R,	_L,	_equal,	
	_D,	_H,	_T,	_N,	_S,	_dash,	
	_bracketR,	_B,	_M,	_W,	_V,	_Z,	_shiftL,	
	_arrowL,	_arrowU,	_arrowD,	_arrowR,	_ctrlL,	
	0,	1,	
	_altR,	0,	0,	
	_guiL,	_del,	_bs	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	_F1,	_F2,	_F3,	_F4,	_F5,	_F11,	
	0,	0,	_stop_mk,	_up_mk,	_play_mk,	0,	0,	
	0,	0,	_prev_mk,	_down_mk,	_next_mk,	0,	
	0,	0,	0,	_mute_mk,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	1,	0,	
	0,	0,	0,	
	_bs,	_del,	0,	
	// right hand
	_F12,	_F6,	_F7,	_F8,	_F9,	_F10,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	1,	
	0,	0,	0,	
	0,	_enter,	_space	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	_1,	_2,	_3,	_4,	_5,	_home,	
	0,	_Q,	_W,	_E,	_R,	_T,	0,	
	0,	_A,	_S,	_D,	_F,	_G,	
	0,	_Z,	_X,	_C,	_V,	_B,	0,	
	0,	0,	0,	0,	0,	
	1,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	_end,	_6,	_7,	_8,	_9,	_0,	0,	
	0,	_Y,	_U,	_I,	_O,	_P,	0,	
	_H,	_J,	_K,	_L,	_semicolon,	0,	
	0,	_N,	_M,	_comma,	_period,	_quote,	0,	
	0,	0,	0,	0,	0,	
	0,	1,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// aliases

// basic
#define  kprrel   &kbfun_press_release
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  sctprre  &kbfun_ctrl_press_release
#define  sguprre  &kbfun_gui_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad
#define  smkprre  &kbfun_mediakey_press_release

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	sguprre,	sguprre,	sguprre,	
	lpush1,	lpush2,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpop,	lpush1,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	ktrans,	smkprre,	smkprre,	smkprre,	ktrans,	ktrans,	
	ktrans,	ktrans,	smkprre,	smkprre,	smkprre,	ktrans,	
	ktrans,	ktrans,	ktrans,	smkprre,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	lpush1,	NULL,	
	NULL,	NULL,	ktrans,	
	kprrel,	kprrel,	ktrans,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	NULL,	lpush1,	
	ktrans,	NULL,	NULL,	
	ktrans,	kprrel,	kprrel	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	lpush1,	lpop,	
	NULL,	NULL,	ktrans,	
	ktrans,	ktrans,	ktrans,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	lpop,	lpush1,	
	ktrans,	NULL,	NULL,	
	ktrans,	ktrans,	ktrans	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	sguprre,	sguprre,	sguprre,	
	lpop1,	NULL,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	kprrel,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	NULL,	lpop1,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	ktrans,	smkprre,	smkprre,	smkprre,	ktrans,	ktrans,	
	ktrans,	ktrans,	smkprre,	smkprre,	smkprre,	ktrans,	
	ktrans,	ktrans,	ktrans,	smkprre,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	lpop1,	NULL,	
	NULL,	NULL,	ktrans,	
	kprrel,	kprrel,	ktrans,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	NULL,	lpop1,	
	ktrans,	NULL,	NULL,	
	ktrans,	kprrel,	kprrel	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	lpop1,	NULL,	
	NULL,	NULL,	ktrans,	
	ktrans,	ktrans,	ktrans,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	
	NULL,	lpop1,	
	ktrans,	NULL,	NULL,	
	ktrans,	ktrans,	ktrans	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	lpush8,	lpop8,	NULL,	NULL,	NULL,	NULL,	
	ktog,	lpush9,	lpop9,	NULL,	NULL,	NULL,	NULL,	
	lpush1,	lpush10,	lpop10,	NULL,	NULL,	NULL,	
	lpush1,	lpop1,	NULL,	NULL,	NULL,	NULL,	NULL,	
	lpush2,	lpop2,	dbtldr,	NULL,	NULL,	
	lpush3,	lpop3,	
	lpush4,	lpop4,	s2kcap,	
	lpush5,	lpop5,	slpunum,	
	// right hand
	lpush6,	lpop6,	slponum,	NULL,	NULL,	NULL,	NULL,	
	lpush7,	lpop7,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
};
// ----------------------------------------------------------------------------
