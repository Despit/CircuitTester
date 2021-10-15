/*
 * @Author: Eugene
 * @Date: 2021-05-19 17:43:17
 * @LastEditTime: 2021-05-22 01:03:46
 * @LastEditors: Eugene
 * @Description: 
 * @FilePath: \keil\config.h
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <AT89X52.h>

// SPI pins
#define SPI_CS     P1_0
#define SPI_SCK    P1_1
#define SPI_MOSI   P1_2

// OLED pins
#define OLED_DC    P1_4
#define OLED_RESET P1_5

// ADC pins
#define AD_START   P0_0
#define AD_EOC     P0_1
#define AD_OE      P0_2
#define AD_CLK     P0_3
#define ADD_A      P0_5
#define AD_SAMPLE  P2

#endif