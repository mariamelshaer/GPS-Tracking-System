#include <stdio.h>
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDigitalDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction)
{
    uint8 Local_u8Mask = 0;
    // Set Mask
    Local_u8Mask = (1<<Copy_u8Pin);
    // Activate Clock on the Required Port
    SYSCTL_RCGCGPIO_R |= (1<<Copy_u8Port);
    switch(Copy_u8Port)
    {
    case GPIO_PORTA:
        // Unlock GPIO Port
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTA_CR_R |= Local_u8Mask;
        // Disable Alternative Function for the required Pin
        GPIO_PORTA_AFSEL_R &=~ Local_u8Mask;
        // Enable Digital Mode for the required Pin
        GPIO_PORTA_DEN_R |= Local_u8Mask;
        // Disable Analog Mode for the required Pin
        GPIO_PORTA_AMSEL_R &=~ Local_u8Mask;
        // Set Pin Direction for the required Pin
        if(Copy_u8Direction == GPIO_DIGITAL_OUTPUT)
        {
            GPIO_PORTA_DIR_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTA_DIR_R &=~ Local_u8Mask;
        }
        // Disable Pull-Down Resistors for the required Pin
        GPIO_PORTA_PDR_R &=~ Local_u8Mask;
        // Disable Pull-Up Resistors for the required Pin
        GPIO_PORTA_PUR_R &=~ Local_u8Mask;
        break;

    case GPIO_PORTB:
        // Unlock GPIO Port
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTB_CR_R |= Local_u8Mask;
        // Disable Alternative Function for the required Pin
        GPIO_PORTB_AFSEL_R &=~ Local_u8Mask;
        // Enable Digital Mode for the required Pin
        GPIO_PORTB_DEN_R |= Local_u8Mask;
        // Disable Analog Mode for the required Pin
        GPIO_PORTB_AMSEL_R &=~ Local_u8Mask;
        // Set Pin Direction for the required Pin
        if(Copy_u8Direction == GPIO_DIGITAL_OUTPUT)
        {
            GPIO_PORTB_DIR_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTB_DIR_R &=~ Local_u8Mask;
        }
        // Disable Pull-Down Resistors for the required Pin
        GPIO_PORTB_PDR_R &=~ Local_u8Mask;
        // Disable Pull-Up Resistors for the required Pin
        GPIO_PORTB_PUR_R &=~ Local_u8Mask;
        break;

    case GPIO_PORTC:
        // It's Preferable to Avoid PORTC All together
        break;

    case GPIO_PORTD:
        // Unlock GPIO Port
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTD_CR_R |= Local_u8Mask;
        // Disable Alternative Function for the required Pin
        GPIO_PORTD_AFSEL_R &=~ Local_u8Mask;
        // Enable Digital Mode for the required Pin
        GPIO_PORTD_DEN_R |= Local_u8Mask;
        // Disable Analog Mode for the required Pin
        GPIO_PORTD_AMSEL_R &=~ Local_u8Mask;
        // Set Pin Direction for the required Pin
        if(Copy_u8Direction == GPIO_DIGITAL_OUTPUT)
        {
            GPIO_PORTD_DIR_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTD_DIR_R &=~ Local_u8Mask;
        }
        // Disable Pull-Down Resistors for the required Pin
        GPIO_PORTD_PDR_R &=~ Local_u8Mask;
        // Disable Pull-Up Resistors for the required Pin
        GPIO_PORTD_PUR_R &=~ Local_u8Mask;
        break;

    case GPIO_PORTE:
        // Unlock GPIO Port
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTE_CR_R |= Local_u8Mask;
        // Disable Alternative Function for the required Pin
        GPIO_PORTE_AFSEL_R &=~ Local_u8Mask;
        // Enable Digital Mode for the required Pin
        GPIO_PORTE_DEN_R |= Local_u8Mask;
        // Disable Analog Mode for the required Pin
        GPIO_PORTE_AMSEL_R &=~ Local_u8Mask;
        // Set Pin Direction for the required Pin
        if(Copy_u8Direction == GPIO_DIGITAL_OUTPUT)
        {
            GPIO_PORTE_DIR_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTE_DIR_R &=~ Local_u8Mask;
        }
        // Disable Pull-Down Resistors for the required Pin
        GPIO_PORTE_PDR_R &=~ Local_u8Mask;
        // Disable Pull-Up Resistors for the required Pin
        GPIO_PORTE_PUR_R &=~ Local_u8Mask;
        break;

    case GPIO_PORTF:
        // Unlock GPIO Port
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTF_CR_R |= Local_u8Mask;
        // Disable Alternative Function for the required Pin
        GPIO_PORTF_AFSEL_R &=~ Local_u8Mask;
        // Enable Digital Mode for the required Pin
        GPIO_PORTF_DEN_R |= Local_u8Mask;
        // Disable Analog Mode for the required Pin
        GPIO_PORTF_AMSEL_R &=~ Local_u8Mask;
        // Set Pin Direction for the required Pin
        if(Copy_u8Direction == GPIO_DIGITAL_OUTPUT)
        {
            GPIO_PORTF_DIR_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTF_DIR_R &=~ Local_u8Mask;
        }

        break;
    }
}

void MGPIO_voidEnablePullUpDown(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_Pull_UP_DOWN)
{
    uint8 Local_u8Mask = 0;
    // Set Mask
    Local_u8Mask = (1<<Copy_u8Pin);
    switch(Copy_u8Port)
    {
    case GPIO_PORTA:
        // Unlock GPIO Port
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTA_CR_R |= Local_u8Mask;
        if (Copy_Pull_UP_DOWN == GPIO_PULL_UP)
        {
            // Disable Pull-Down Resistors for the required Pin
            GPIO_PORTA_PDR_R &=~ Local_u8Mask;
            // Enable Pull-Up Resistors for the required Pin
            GPIO_PORTA_PUR_R |= Local_u8Mask;
        }
        else if (Copy_Pull_UP_DOWN == GPIO_PULL_DOWN)
        {
            // Disable Pull-Up Resistors for the required Pin
            GPIO_PORTA_PUR_R &=~ Local_u8Mask;
            // Enable Pull-Down Resistors for the required Pin
            GPIO_PORTA_PDR_R |= Local_u8Mask;
        }
        break;

    case GPIO_PORTB:
        // Unlock GPIO Port
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTB_CR_R |= Local_u8Mask;
        if (Copy_Pull_UP_DOWN == GPIO_PULL_UP)
        {
            // Disable Pull-Down Resistors for the required Pin
            GPIO_PORTB_PDR_R &=~ Local_u8Mask;
            // Enable Pull-Up Resistors for the required Pin
            GPIO_PORTB_PUR_R |= Local_u8Mask;
        }
        else if (Copy_Pull_UP_DOWN == GPIO_PULL_DOWN)
        {
            // Disable Pull-Up Resistors for the required Pin
            GPIO_PORTB_PUR_R &=~ Local_u8Mask;
            // Enable Pull-Down Resistors for the required Pin
            GPIO_PORTB_PDR_R |= Local_u8Mask;
        }
        break;

    case GPIO_PORTC:
        // It's Preferable to Avoid PORTC All together
        break;

    case GPIO_PORTD:
        // Unlock GPIO Port
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTD_CR_R |= Local_u8Mask;
        if (Copy_Pull_UP_DOWN == GPIO_PULL_UP)
        {
            // Disable Pull-Down Resistors for the required Pin
            GPIO_PORTD_PDR_R &=~ Local_u8Mask;
            // Enable Pull-Up Resistors for the required Pin
            GPIO_PORTD_PUR_R |= Local_u8Mask;
        }
        else if (Copy_Pull_UP_DOWN == GPIO_PULL_DOWN)
        {
            // Disable Pull-Up Resistors for the required Pin
            GPIO_PORTD_PUR_R &=~ Local_u8Mask;
            // Enable Pull-Down Resistors for the required Pin
            GPIO_PORTD_PDR_R |= Local_u8Mask;
        }
        break;

    case GPIO_PORTE:
        // Unlock GPIO Port
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTE_CR_R |= Local_u8Mask;
        if (Copy_Pull_UP_DOWN == GPIO_PULL_UP)
        {
            // Disable Pull-Down Resistors for the required Pin
            GPIO_PORTE_PDR_R &=~ Local_u8Mask;
            // Enable Pull-Up Resistors for the required Pin
            GPIO_PORTE_PUR_R |= Local_u8Mask;
        }
        else if (Copy_Pull_UP_DOWN == GPIO_PULL_DOWN)
        {
            // Disable Pull-Up Resistors for the required Pin
            GPIO_PORTE_PUR_R &=~ Local_u8Mask;
            // Enable Pull-Down Resistors for the required Pin
            GPIO_PORTE_PDR_R |= Local_u8Mask;
        }
        break;

    case GPIO_PORTF:
        // Unlock GPIO Port
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        // Allow Commit Changes to the required pin
        GPIO_PORTF_CR_R |= Local_u8Mask;
        if (Copy_Pull_UP_DOWN == GPIO_PULL_UP)
        {
            // Disable Pull-Down Resistors for the required Pin
            GPIO_PORTF_PDR_R &=~ Local_u8Mask;
            // Enable Pull-Up Resistors for the required Pin
            GPIO_PORTF_PUR_R |= Local_u8Mask;
        }
        else if (Copy_Pull_UP_DOWN == GPIO_PULL_DOWN)
        {
            // Disable Pull-Up Resistors for the required Pin
            GPIO_PORTF_PUR_R &=~ Local_u8Mask;
            // Enable Pull-Down Resistors for the required Pin
            GPIO_PORTF_PDR_R |= Local_u8Mask;
        }
        break;
    }
}

void MGPIO_voidSetPinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value)
{
    uint8 Local_u8Mask = 0;
    // Set Mask
    Local_u8Mask = (1<<Copy_u8Pin);
    switch(Copy_u8Port)
    {
    case GPIO_PORTA:
        if (Copy_u8Value == GPIO_HIGH)
        {
            GPIO_PORTA_DATA_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTA_DATA_R &=~ Local_u8Mask;
        }
        break;

    case GPIO_PORTB:
        if (Copy_u8Value == GPIO_HIGH)
        {
            GPIO_PORTB_DATA_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTB_DATA_R &=~ Local_u8Mask;
        }
        break;

    case GPIO_PORTC:
        // It's Preferable to Avoid PORTC All together
        break;

    case GPIO_PORTD:
        if (Copy_u8Value == GPIO_HIGH)
        {
            GPIO_PORTD_DATA_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTD_DATA_R &=~ Local_u8Mask;
        }
        break;

    case GPIO_PORTE:
        if (Copy_u8Value == GPIO_HIGH)
        {
            GPIO_PORTE_DATA_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTE_DATA_R &=~ Local_u8Mask;
        }
        break;

    case GPIO_PORTF:
        if (Copy_u8Value == GPIO_HIGH)
        {
            GPIO_PORTF_DATA_R |= Local_u8Mask;
        }
        else
        {
            GPIO_PORTF_DATA_R &=~ Local_u8Mask;
        }
        break;
    }
}

uint8 MGPIO_u8GetPinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
    uint8 Local_u8Data = 0;
    switch(Copy_u8Port)
    {
    case GPIO_PORTA:
        Local_u8Data = GET_BIT(GPIO_PORTA_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTB:
        Local_u8Data = GET_BIT(GPIO_PORTB_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTC:
        // It's Preferable to Avoid PORTC All together
        break;

    case GPIO_PORTD:
        Local_u8Data = GET_BIT(GPIO_PORTD_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTE:
        Local_u8Data = GET_BIT(GPIO_PORTE_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTF:
        Local_u8Data = GET_BIT(GPIO_PORTF_DATA_R, Copy_u8Pin);
        break;
    }
    return Local_u8Data;
}

void MGPIO_voidTogglePinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
    switch(Copy_u8Port)
    {
    case GPIO_PORTA:
        TOG_BIT(GPIO_PORTA_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTB:
        TOG_BIT(GPIO_PORTB_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTC:
        // It's Preferable to Avoid PORTC All together
        break;

    case GPIO_PORTD:
        TOG_BIT(GPIO_PORTD_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTE:
        TOG_BIT(GPIO_PORTE_DATA_R, Copy_u8Pin);
        break;

    case GPIO_PORTF:
        TOG_BIT(GPIO_PORTF_DATA_R, Copy_u8Pin);
        break;
    }
}

