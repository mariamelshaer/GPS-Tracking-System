#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"LCD_interface.h"

int main(void)
{
    HLCD_Init();
    HLCD_SendChar('A');
    while(1)
    {
        HLCD_SendChar('A');
    }
}

