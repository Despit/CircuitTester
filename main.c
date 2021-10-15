/*
 * @Author: Eugene
 * @Date: 2021-05-18 19:31:39
 * @LastEditTime: 2021-05-22 12:27:27
 * @LastEditors: Eugene
 * @Description:
 * @FilePath: \keil\main.c
 */
#include <AT89X52.H>
#include "delay.h"
#include "oled.h"
#include "ad0808.h"
#include "ad9850.h"
uint timer2_count = 0;
unsigned long int V1 = 0, V2 = 0,Au=0;
char display[16] = {0};
char display2[16] = {0};
char display3[16] = {0};
const char *dis = display;
const char *dis2 = display2;
const char *dis3 = display3;

void main()
{
  void numchange(unsigned long int);
  void numchange2(unsigned long int Vt);
  void numchangefhe(unsigned long int Vt);
  void oled_put_chars_8x16(uint x, uint y, const char *characters);
  oled_init();
  oled_put_chars_8x16(0, 2, "Init finish");
  oled_clear();
  ADC_init();
  while (1)
  {
    ADD_A = 0;
    V1 = ADC_sample()*1.0/11;
    delay_ms(75);
    ADD_A = 1;
    V2 = ADC_sample();
    Au=V2*1000.0/V1;
    numchange2(V2);
    numchange(V1);
    numchangefhe(Au);
  }
}

void numchangefhe(unsigned long int Vt)
{
  display3[6] = (Vt % 10) + '0';
  display3[5] = ((Vt - Vt % 10) % 100 / 10) + '0';
  display3[4] = ((Vt - Vt % 100) % 1000 / 100) + '0';
  display3[2] = ((Vt - Vt % 1000) % 10000 / 1000) + '0';
  display3[1] = ((Vt - Vt % 10000) % 100000 / 10000) + '0';
  display3[3] = '.';
  if (Vt / 100000)
    display3[0] = (Vt / 100000) + '0';
  else
    display3[0] = '0';
  oled_put_chars_8x16(0, 3, "Au=");
  oled_put_chars_8x16(6, 3, dis3);
}

void numchange(unsigned long int Vt)
{
  display[6] = (Vt % 10) + '0';
  display[5] = ((Vt - Vt % 10) % 100 / 10) + '0';
  display[4] = ((Vt - Vt % 100) % 1000 / 100) + '0';
  display[3] = ((Vt - Vt % 1000) % 10000 / 1000) + '0';
  display[2] = ((Vt - Vt % 10000) % 100000 / 10000) + '0';
  display[1] = '.';
  if (Vt / 100000)
    display[0] = (Vt / 100000) + '0';
  else
    display[0] = '0';
  oled_put_chars_8x16(1, 0, "V1=");
  oled_put_chars_8x16(6, 0, dis);
}

void numchange2(unsigned long int Vt)
{
  display2[6] = (Vt % 10) + '0';
  display2[5] = ((Vt - Vt % 10) % 100 / 10) + '0';
  display2[4] = ((Vt - Vt % 100) % 1000 / 100) + '0';
  display2[3] = ((Vt - Vt % 1000) % 10000 / 1000) + '0';
  display2[2] = ((Vt - Vt % 10000) % 100000 / 10000) + '0';
  display2[1] = '.';
  if (Vt / 100000)
    display2[0] = (Vt / 100000) + '0';
  else
    display2[0] = '0';
  oled_put_chars_8x16(0, 1, "V2=");
  oled_put_chars_8x16(6, 1, dis2);
}
void timer(void) interrupt 1 using 0
{
  AD_CLK = !AD_CLK;
}