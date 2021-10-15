/*
 * @Author: Eugene
 * @Date: 2021-05-20 11:16:27
 * @LastEditTime: 2021-05-22 09:39:56
 * @LastEditors: Eugene
 * @Description:
 * @FilePath: \keil\ad0808.c
 */
#include "ad0808.h"
#include <AT89X52.h>
#include "config.h"
#include "delay.h"
#include "oled.h"

void ADC_init(void)
{
    TMOD |= 0x02;
    TH0 = 231;
    TL0 = 231;
    IE = 0x82;
    TR0 = 1;
}

unsigned long int ADC_sample()
{
    unsigned long int voltage, temp;
    AD_START = 0;
    AD_START = 1;
    delay_ms(50);
    AD_START = 0;
    while (!AD_EOC)
        ;
    AD_OE = 1;
    temp = AD_SAMPLE;
    AD_OE = 0;
    voltage = (470000.0 * temp / 256);
    return voltage;
}
