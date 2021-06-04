#include"string.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"UART_interface.h"
#include"LCD_interface.h"

volatile char Data[100];
volatile uint8 GPRMC_Flag = 0;
volatile uint8 GPRMC_Counter = 0;
volatile uint8 Counter = 0;

void CallBack_UART2(void);
void Parse(void);

int main(void)
{
    HLCD_Init();
    MUART2_voidInit();
    MUART2_voidSetCallBack(CallBack_UART2);
    while(1);
}

void CallBack_UART2(void)
{
    uint8 Local_u8Data = MUART2_voidReceiveByte();
    if (Local_u8Data == '$')
    {
        Counter = 0;
        if ((Data[0]=='$') && (Data[1]=='G') && (Data[2]=='P') && (Data[3]=='R') && (Data[4]=='M') && (Data[5]=='C'))
        {
            Parse();
        }
    }
    Data[Counter] = Local_u8Data;
    Counter++;
}

void Parse(void)
{

}

