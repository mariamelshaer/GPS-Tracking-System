#ifndef UART_INTERAFCE_H
#define UART_INTERAFCE_H


#define UART_0   0
#define UART_1   1
#define UART_2   2
#define UART_5   5

void MUART0_voidInit(void);
void MUART1_voidInit(void);
void MUART2_voidInit(void);
void MUART5_voidInit(void);

uint8 MUART0_voidReceiveByte(void);
uint8 MUART1_voidReceiveByte(void);
uint8 MUART2_voidReceiveByte(void);
uint8 MUART5_voidReceiveByte(void);

void MUART0_u8SendByte(uint8 Copy_u8Data);
void MUART1_u8SendByte(uint8 Copy_u8Data);
void MUART2_u8SendByte(uint8 Copy_u8Data);
void MUART5_u8SendByte(uint8 Copy_u8Data);

void MUART0_voidSetCallBack(void (*ptr)(void));
void MUART1_voidSetCallBack(void (*ptr)(void));
void MUART2_voidSetCallBack(void (*ptr)(void));
void MUART5_voidSetCallBack(void (*ptr)(void));

uint8 MUART0_voidSendString(volatile char * Ptr_u8String);
uint8 MUART1_voidSendString(volatile char * Ptr_u8String);
uint8 MUART2_voidSendString(volatile char * Ptr_u8String);
uint8 MUART5_voidSendString(volatile char * Ptr_u8String);

uint8 MUART0_voidReceiveString(char * Ptr_u8String);

void MUART_voidActivatInterrupt(uint8 Copy_u8UARTNum);
void MUART_voidDeactivatInterrupt(uint8 Copy_u8UARTNum);

#endif
