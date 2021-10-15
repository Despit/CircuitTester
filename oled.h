/*
 * @Author: Eugene
 * @Date: 2021-05-19 17:37:46
 * @LastEditTime: 2021-05-19 23:39:46
 * @LastEditors: Eugene
 * @Description: 
 * @FilePath: \keil\oled.h
 */
#ifndef __OLED_H__
#define __OLED_H__
#define uint unsigned int
#include "spi.h"
#include "delay.h"
#define OLED_WIDTH  128
#define OLED_HEIGHT 64

// typedef struct __OLED {
//   unsigned char x;
// } OLED;

void oled_reset(void);
void oled_send_data(uint d);
void oled_send_command(uint command);
void oled_set_position(uint x, uint y);
void oled_init(void);
void oled_clear(void);
void oled_full(void);
void oled_put_char_8x16(uint x, uint y, char character);
void oled_put_chars_8x16(uint x, uint y, const char *characters);


#endif // __OLED_H__