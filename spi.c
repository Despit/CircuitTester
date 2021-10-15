/*
 * @Author: Eugene
 * @Date: 2021-05-19 17:39:46
 * @LastEditTime: 2021-05-20 11:15:16
 * @LastEditors: Eugene
 * @Description: 
 * @FilePath: \keil\spi.c
 */
#include "spi.h"
#define uchar unsigned char
void spi_read_write(uchar d)
{
  unsigned char i;
  for(i=0; i<8; i++)
  {
    SPI_MOSI = (d << i) & 0x80;
    SPI_SCK = 0;
    SPI_SCK = 1;
  }
}