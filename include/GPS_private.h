#ifndef GPS_PRIVATE_H
#define GPS_PRIVATE_H

static void GPS_voidReceive(void);
static uint8 GPS_Parse(void);
static float GetDistance(void);
static float LongitudeGetFloat(volatile char * lon);
static float LatitudeGetFloat(volatile char * lat);
static void GetString(int num, char * str);

#define UART_0  0
#define UART_1  1
#define UART_2  2
#define UART_5  5

#endif

