#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "GPIO_interface.h"

#include "LCD_interface.h"

#include "GPS_interface.h"
#include "GPS_private.h"
#include "GPS_config.h"


volatile char Data[100];
volatile char lon1[11];
volatile char lat1[10];
volatile char lon2[11];
volatile char lat2[10];

volatile float Distance = 0;
volatile float Floatlon1;
volatile float Floatlat1;
volatile float Floatlon2;
volatile float Floatlat2;

volatile uint8 Counter = 0;
volatile uint8 FirstFlag = 0;
volatile uint8 AVFlag = 0;


void HGPS_voidInit(void)
{
#if GPS_UART == UART_1
    MUART1_voidInit();
    MUART1_voidSetCallBack(GPS_voidReceive);
#elif GPS_UART == UART_2
    MUART2_voidInit();
    MUART2_voidSetCallBack(GPS_voidReceive);
#elif GPS_UART == UART_5
    MUART5_voidInit();
    MUART5_voidSetCallBack(GPS_voidReceive);
#endif
}

void HGPS_voidStart(void)
{
#if GPS_UART == UART_1
    MUART_voidActivatInterrupt(UART_1);
#elif GPS_UART == UART_2
    MUART_voidActivatInterrupt(UART_2);
#elif GPS_UART == UART_5
    MUART_voidActivatInterrupt(UART_5);
#endif
}

static void GPS_voidReceive(void)
{
    uint8 Local_u8Data = MUART2_voidReceiveByte();
    uint8 ValidFlag = 0;
    char S_Distance[5]={'\0','\0','\0','\0','\0'};
    if((Local_u8Data == 'A')||(Local_u8Data == 'V'))
    {
        AVFlag = 1;
    }
    if (Local_u8Data == '$')
    {
        Counter = 0;
        if ((Data[0]=='$') && (Data[1]=='G') && (Data[2]=='P') && (Data[3]=='R') && (Data[4]=='M') && (Data[5]=='C') && (AVFlag == 1))
        {
            ValidFlag = GPS_Parse();
            AVFlag = 0;
            if (ValidFlag == 0)
            {
                if (FirstFlag == 0)
                {
                    FirstFlag = 1;
                    Floatlat1 = LatitudeGetFloat(lat1);
                    Floatlon1 = LongitudeGetFloat(lon1);
                }
                else
                {
                    Floatlat2 = LatitudeGetFloat(lat2);
                    Floatlon2 = LongitudeGetFloat(lon2);
                    Distance += GetDistance();
                    Floatlat1 = Floatlat2;
                    Floatlon1 = Floatlon2;
                }
            }
            return;
        }
    }
    Data[Counter] = Local_u8Data;
    Counter++;
}

static uint8 GPS_Parse(void)
{

}

static float LatitudeGetFloat(volatile char * lat)
{

}
static float LongitudeGetFloat(volatile char * lon)
{

}

static float GetDistance(void)
{

}





