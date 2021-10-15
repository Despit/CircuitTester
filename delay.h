/*
 * @Author: Eugene
 * @Date: 2021-05-19 17:41:34
 * @LastEditTime: 2021-05-19 22:26:04
 * @LastEditors: Eugene
 * @Description: 
 * @FilePath: \keil\delay.h
 */
#ifndef __DELAY_H__
#define __DELAY_H__
#define uint unsigned int

#include <AT89X52.H>

#define CRYSTAL_FREQUENCY   11.0592
#define FS                  (1 / (CRYSTAL_FREQUENCY / 12))

void delay_ms(uint t);

#endif