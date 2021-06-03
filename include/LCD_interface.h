#ifndef LCD_INTERFACE_H_
#define LCD_INTEFACE_H_

void HLCD_Init(void);
void HLCD_SendCommand(uint8 Copy_u8Command);
void HLCD_SendChar(uint8 Copy_u8Data);
void HLCD_Clear(void);
void HLCD_SendString(uint8 *ptr);

#endif
