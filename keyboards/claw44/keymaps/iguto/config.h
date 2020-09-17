/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2
#define TAPPING_TERM 200
#undef DEBOUNCE
#define DEBOUNCE 2
#undef USB_POLLING_INTERVAL_MS
#define USB_POLLING_INTERVAL_MS 2

#define _QWERTY 0
#define _EUCALYN 1
#define _EUCALYN2 2
#define _NAGINATA 3
#define _LOWER 8
#define _RAISE 9
#define _ADJUST 10
#define _MISC 11
#define _EMACS 12
#define _DOC 13


//enum my_keymap {
//  _QWERTY = 0,
//  _LOWER,
//  _RAISE,
//  _ADJUST,
//  _MISC,
//};

/* 薙刀式 */
//#define NAGINATA_YOKOGAKI
#define NAGINATA_TATEGAKI
//#define NAGINATA_EDIT_WIN // JP106
//#define NAGINATA_EDIT_MAC // JP106
//#define MAC_LIVE_CONVERSION // Macでライブ変換をオンにしている場合
//#define COMBO_COUNT 2
