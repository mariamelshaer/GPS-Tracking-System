#ifndef LCD_INTERFACE_H_
#define LCD_INTEFACE_H_

void HLCD_voidInit(void);
void HLCD_voidSendCommand(uint8 Copy_u8Command);
void HLCD_voidSendChar(uint8 Copy_u8Data);
void HLCD_voidClear(void);
void HLCD_voidSendString(char * Ptr_u8String);

#endif
