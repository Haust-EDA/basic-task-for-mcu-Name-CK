#include "REGX52.h"

void delay_ms(unsigned int x) // 延时函数
{
    unsigned int i, j;
    if (x == 1000)
    {
        for (i = 0; i < 19601; i++) // 延时1s
        {
            for (j = 5; j > 0; j--);
        }
    }
    else while (x--)for (j = 115; j > 0; j--);
}

// tips: 原理图当中led为低电平点亮，比如点亮LED2,代码为： P0 = 0xFE (1111 1110)

int main(void)
{
    """
        在下方编写你的代码
    """
	/*	杨晨凯	*/
	
    // 配置74HC138，使IO6为低电平
    P1^4 = 0;
    P1^3 = 1;
    P1^0 = 0;
    P1^1 = 1;
    P1^2 = 1;

// 流水灯
#define Use_Mode1//不定义Use_Mode1则使用方式2

/*方式1*/
#ifdef Use_Mode1
    P0 = 0x7F; // 0111 1111
    while (1)
    {
        delay_ms(500);
        P0 = P0 >> 1;
        P0 += 0x80;     // 1000 0000
        if (P0 == 0xFF) // 1111 1111
        {
            P0 = 0x7F; // 0111 1111
        }
    }

/*方式2*/
#else
    while (1)
    {
        P0 = 0x7F; // 0111 1111
        delay_ms(500);
        P0 = 0xBF; // 1011 1111
        delay_ms(500);
        P0 = 0xDF; // 1101 1111
        delay_ms(500);
        P0 = 0xEF; // 1110 1111
        delay_ms(500);
        P0 = 0xF7;
        delay_ms(500);
        P0 = 0xFB;
        delay_ms(500);
        P0 = 0xFD;
        delay_ms(500);
        P0 = 0xFE;
        delay_ms(500);
    }
#endif
    return 0;
}
