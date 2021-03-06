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
volatile uint8 ReadingCount = 0;


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

            ReadingCount = 0;
            ValidFlag = GPS_Parse();
            AVFlag = 0;
            if (ValidFlag == 0)
            {
                if (FirstFlag == 0)
                {
                    FirstFlag = 1;
                    Floatlat1 = LatitudeGetFloat(lat1);
                    Floatlon1 = LongitudeGetFloat(lon1);
                    // Turn OFF RED LED
                    MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN1, GPIO_LOW);
                    MUART0_voidSendString(lat1);
                    MUART0_voidSendString("\n");
                    MUART0_voidSendString(lon1);
                    MUART0_voidSendString("\n");
                }
                else
                {
                    Floatlat2 = LatitudeGetFloat(lat2);
                    Floatlon2 = LongitudeGetFloat(lon2);
                    MUART0_voidSendString(lat2);
                    MUART0_voidSendString("\n");
                    MUART0_voidSendString(lon2);
                    MUART0_voidSendString("\n");
                    Distance += GetDistance();
                    GetString ( (int) Distance, S_Distance);
                    HLCD_voidClear();
                    HLCD_voidSendString("Distance is ");
                    HLCD_voidSendString(S_Distance);
                    HLCD_voidSendString("m");
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
    uint8 n1 = 0;
    uint8 n2 = 0;
    uint8 j = 0;
    uint8 flaglat = 0;
    uint8 flaglon = 0;


    if (FirstFlag == 0)
    {
        if(Data[5]=='C')
        {
            for(j=5; j<100;j++)
            {
                if(Data[j]=='V')
                {
                    flaglat = 0;
                    flaglon = 0;
                    return 1;
                }
                if(Data[j-1]=='A' && Data[j]==',')
                {
                    flaglat = 1;
                }
                if((Data[j+1] == ',') && (flaglat == 1))
                {
                    flaglat = 0;
                    break;
                }
                if(flaglat)
                {
                    lat1[n1++]=Data[j+1];
                }

            }
            if ((lat1[0]!='3')||(lat1[1]!='0'))
            {
                return 1;
            }

            for(j=5; j<100;j++)
            {

                if(Data[j+1]=='N' && Data[j]==',')
                {
                    flaglon = 1;
                }
                if((Data[j+3] == ',') && (flaglon == 1))
                {
                    flaglon = 0;
                    return 0;
                }
                if(flaglon)
                {
                    lon1[n2++]=Data[j+3];
                }
            }
            if ((lon1[1]!='3')||(lon1[2]!='1'))
            {
                return 1;
            }
            return 0;
        }
    }
    else
    {
        if(Data[5]=='C')
        {
            for(j=5; j<100;j++)
            {
                if(Data[j]=='V')
                {
                    flaglat = 0;
                    flaglon = 0;
                    return 1;
                }
                if(Data[j-1]=='A' && Data[j]==',')
                {
                    flaglat = 1;
                }
                if((Data[j+1] == ',') && (flaglat == 1))
                {
                    flaglat = 0;
                    break;
                }
                if(flaglat)
                {
                    lat2[n1++]=Data[j+1];
                }

            }
            if ((lat2[0]!='3')||(lat2[1]!='0'))
            {
                return 1;
            }

            for(j=5; j<100;j++)
            {

                if(Data[j+1]=='N' && Data[j]==',')
                {
                    flaglon = 1;
                }
                if((Data[j+3] == ',') && (flaglon == 1))
                {
                    flaglon = 0;
                    return 0;
                }
                if(flaglon)
                {
                    lon2[n2++]=Data[j+3];
                }
            }
            if ((lon2[1]!='3')||(lon2[2]!='1'))
            {
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

static float LatitudeGetFloat(volatile char * lat)
{
    uint8 k = 0;
    uint8 s = 0;
    // Get the degrees only for Latitude
    char dlat[5]={'\0','\0','\0','\0','\0'};
    for (k = 0;k < 2;k++)
    {
        dlat[k] = lat[k];
    }
    int f1;
    f1 = (int) atoi (dlat);

    // Get the minutes only for Latitude
    char mlat[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

    for (k=2 ,s=0; k<9; k++, s++)
    {
        mlat[s] = lat[k];
    }
    float ff1;
    ff1 = (float) atof (mlat);

    //convert to degree decimal & Return Float Latitude
    float x = f1 + (ff1 / 60.0);
    return x;

}
static float LongitudeGetFloat(volatile char * lon)
{
    uint8 l = 0;
    uint8 s = 0;
    // Get the degrees only for Longitude
    char dlon[5]={'\0','\0','\0','\0','\0'};
    for (l=0; l < 3; l++)
    {
        dlon[l] = lon[l];
    }
    int f2;
    f2 = (int) atoi (dlon);

    // Get the minutes only for Longitude
    char mlon[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    for (l=3 ,s=0; l<9; l++, s++)
    {
        mlon[s] = lon[l];
    }
    float ff2;
    ff2 = (float) atof (mlon);

    //convert to degree decimal & Return Float Longitude
    float y = f2 + (ff2 / 60.0);
    return y;
}

static float GetDistance(void)
{
    float p = 3.14159 / 180;
    float x = pow(sin((Floatlat2 * p - Floatlat1 * p) / 2), 2);
    float y = (cos(Floatlat2*p))* cos(Floatlat1*p) * sin(pow((Floatlon2*p - Floatlon1 * p) / 2, 2));
    float z = sqrt(x + y);
    float d = 2 * 6371000 * asin(z);
    return d;
}

static void GetString(int num, char * str)
{
    int i = 0;
    uint8 isNegative = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';

    int start = 0;
    int end = i -1;
    while (start < end)
    {
        swap(str+start, str+end);
        start++;
        end--;
    }
}

static void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}



