#include <stdio.h>
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include "GPIO_interface.h"

void HLCD_voidInit(void)
{
	// Wait 50 ms till LCD VDD reaches 4.5v.
    Delay_ms(50);


	// Set PORTB to output direction contains (B0 ~ B7).
    MGPIO_voidSetPortDigitalDirection(GPIO_PORTB, GPIO_DIGITAL_OUTPUT);

    // D6 pin.
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTD, PIN3, GPIO_DIGITAL_OUTPUT);

    // RS pin.
    MGPIO_voidSetPinDigitalDirection(LDC_RS_PIN, GPIO_DIGITAL_OUTPUT);

    // RW pin.
    MGPIO_voidSetPinDigitalDirection(LDC_RW_PIN, GPIO_DIGITAL_OUTPUT);

    // E pin.
    MGPIO_voidSetPinDigitalDirection(LDC_E_PIN, GPIO_DIGITAL_OUTPUT);

    // Function set (8 bit mode , 2 lines , 5x7 format)
	HLCD_voidSendCommand(0x38);
	Delay_ms(1);

	// Display ON/OFF control. (Display ON , cursor ON , blinking off)
	HLCD_voidSendCommand(0x0E);
	Delay_ms(1);


	HLCD_voidSendCommand(0x01);   // Clear display.
	Delay_ms(2);


	HLCD_voidSendCommand(0x06);   // Entry mode. (No display shift , AC increase)
	Delay_ms(1);
}

void HLCD_voidSendCommand(uint8 Copy_u8Command)
{
	// Write 0 on RS pin to select instruction register.
    MGPIO_voidSetPinDigitalValue(LDC_RS_PIN, GPIO_LOW);

	// Write 0 on RW pin to select write command.
    MGPIO_voidSetPinDigitalValue(LDC_RW_PIN, GPIO_LOW);

	// Output
    MGPIO_voidSetPortDigitalValue(GPIO_PORTB, Copy_u8Command);
    MGPIO_voidSetPinDigitalValue (GPIO_PORTD, PIN3, GET_BIT(Copy_u8Command, 6));

	// Write 1 on enable pin
    MGPIO_voidSetPinDigitalValue(LDC_E_PIN, GPIO_HIGH);
	Delay_ms(2);
	// Write 0 on enable pin.
	MGPIO_voidSetPinDigitalValue(LDC_E_PIN, GPIO_LOW);
}

void HLCD_voidSendChar(uint8 Copy_u8Data)
{
	// Write 1 on RS pin to select data register.
    MGPIO_voidSetPinDigitalValue(LDC_RS_PIN, GPIO_HIGH);

	// Write 0 on RW pin to select write command.
    MGPIO_voidSetPinDigitalValue(LDC_RW_PIN, GPIO_LOW);

	// Output
    MGPIO_voidSetPortDigitalValue(GPIO_PORTB, Copy_u8Data);
    MGPIO_voidSetPinDigitalValue (GPIO_PORTD, PIN3, GET_BIT(Copy_u8Data, 6));

    // Write 1 on enable pin
    MGPIO_voidSetPinDigitalValue(LDC_E_PIN, GPIO_HIGH);
    Delay_ms(2);
    // Write 0 on enable pin.
    MGPIO_voidSetPinDigitalValue(LDC_E_PIN, GPIO_LOW);
}

void HLCD_voidClear(void)
{
    HLCD_voidSendCommand(0x01);   // Clear display.
    Delay_ms(2);
}

void HLCD_voidSendString(char * Ptr_u8String)
{
	uint8 Local_u8Counter = 0;
    while(Ptr_u8String[Local_u8Counter] != '\0')
	{
		HLCD_voidSendChar(Ptr_u8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}


static void Delay_ms (uint16 Copy_u16Delay)
{
    uint32 i = 0, j = 0;
    for(i=0;i<Copy_u16Delay;i++)
    {
        for(j=0;j<16000;j++)
        {

        }
    }
}
