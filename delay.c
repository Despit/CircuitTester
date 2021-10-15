/*
 * @Author: Eugene
 * @Date: 2021-05-19 17:41:55
 * @LastEditTime: 2021-05-20 17:58:04
 * @LastEditors: Eugene
 * @Description: 
 * @FilePath: \keil\delay.c
 */
#include "delay.h"
#define uint unsigned int
void delay_ms(uint t)
{
  unsigned char a, b;
  for (a = 1; a < t; a++)
    for (b = 1; b; b++);
}