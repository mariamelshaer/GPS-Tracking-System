#include <stdio.h>
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "GPIO_private.h"
#include "UART_config.h"

void (*UART0_CallBack) (void);
void (*UART1_CallBack) (void);
void (*UART2_CallBack) (void);
void (*UART5_CallBack) (void);

/************************************************************************************************/

void MUART0_voidInit(void)
{
    // Activate Clock on the Required UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART0_MASK;
    // Activate Clock on the Required GPIO
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIOA_UART0_MASK;
    // Wait for Clock
    TwoCyclesWait();
    // Unlock GPIO Port
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    // Allow Commit Changes to the required pin
    GPIO_PORTA_CR_R |= UART0_GPIOA_TXRX_MASK;
    // Enable Alternative Function for the required Pin
    GPIO_PORTA_AFSEL_R |= UART0_GPIOA_TXRX_MASK;
    // Enable Digital Mode for the required Pin
    GPIO_PORTA_DEN_R |= UART0_GPIOA_TXRX_MASK;
    // Disable Analog Mode for the required Pin
    GPIO_PORTA_AMSEL_R &=~ UART0_GPIOA_TXRX_MASK;
    // Choose UART Alternative Function for PINS B0 & B1
    GPIO_PORTA_PCTL_R &=~ 0x000000FF;
    GPIO_PORTA_PCTL_R |= 0x00000011;
    // Disable UART 0 to make Edits
    UART0_CTL_R &=~ 0x00000001;
    // Enable TX & RX
    UART0_CTL_R |= 0x00000300;
    // Set Baud Rate Whole Number
    UART0_IBRD_R = UART_IBRD_9600;
    // Set Baud Rate Decimal
    UART0_FBRD_R = UART_FBRD_9600;
    // Choose word length 8 bits & Disable FIFO
    UART0_LCRH_R =  UART_LCRH_8_FIFO;
    #if UART0_INT == UART_INT_ACTIVE
        // Clear Interrupt flag
        UART0_ICR_R &= ~(0x0780);
        // Enable Receive Interrupt for UART0
        UART0_IM_R |= 0x10;
        // Enable UART0 Interrupt from NVIC (Interrupt 5 / VECTOR 21)
        SET_BIT(NVIC_EN0_R, (INT_UART0-16));
    #endif
    // Enable UART0
    UART0_CTL_R |= 0x00000001;
}

void MUART1_voidInit(void)
{
    // Activate Clock on the Required UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART1_MASK;
    // Activate Clock on the Required GPIO
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIOB_UART1_MASK;
    // Wait for Clock
    TwoCyclesWait();
    // Unlock GPIO Port
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    // Allow Commit Changes to the required pin
    GPIO_PORTB_CR_R |= UART1_GPIOB_TXRX_MASK;
    // Enable Alternative Function for the required Pin
    GPIO_PORTB_AFSEL_R |= UART1_GPIOB_TXRX_MASK;
    // Enable Digital Mode for the required Pin
    GPIO_PORTB_DEN_R |= UART1_GPIOB_TXRX_MASK;
    // Disable Analog Mode for the required Pin
    GPIO_PORTB_AMSEL_R &=~ UART1_GPIOB_TXRX_MASK;
    // Choose UART Alternative Function for PINS B0 & B1
    GPIO_PORTB_PCTL_R &=~ 0x000000FF;
    GPIO_PORTB_PCTL_R |= 0x00000011;
    // Disable UART 1 to make Edits
    UART1_CTL_R &=~ 0x00000001;
    // Enable TX & RX
    UART1_CTL_R |= 0x00000300;
    // Set Baud Rate Whole Number
    UART1_IBRD_R = UART_IBRD_9600;
    // Set Baud Rate Decimal
    UART1_FBRD_R = UART_FBRD_9600;
    // Choose word length 8 bits & Disable FIFO
    UART1_LCRH_R =  UART_LCRH_8_FIFO;
    #if UART1_INT == UART_INT_ACTIVE
        // Clear Interrupt flag
        UART1_ICR_R &= ~(0x0780);
        // Enable Receive Interrupt for UART1
        UART1_IM_R |= 0x10;
        // Enable UART1 Interrupt from NVIC (Interrupt 6 / VECTOR 22)
        SET_BIT(NVIC_EN0_R, (INT_UART1-16));
    #endif
    // Enable UART1
    UART1_CTL_R |= 0x00000001;

}

void MUART2_voidInit(void)
{
    // Activate Clock on the Required UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART2_MASK;
    // Activate Clock on the Required GPIO
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIOD_UART2_MASK;
    // Wait for Clock
    TwoCyclesWait();
    // Unlock GPIO Port
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    // Allow Commit Changes to the required pin
    GPIO_PORTD_CR_R |= UART2_GPIOD_TXRX_MASK;
    // Enable Alternative Function for the required Pin
    GPIO_PORTD_AFSEL_R |= UART2_GPIOD_TXRX_MASK;
    // Enable Digital Mode for the required Pin
    GPIO_PORTD_DEN_R |= UART2_GPIOD_TXRX_MASK;
    // Disable Analog Mode for the required Pin
    GPIO_PORTD_AMSEL_R &=~ UART2_GPIOD_TXRX_MASK;
    // Choose UART Alternative Function for PINS D6 & D7
    GPIO_PORTD_PCTL_R &=~ 0xFF000000;
    GPIO_PORTD_PCTL_R |= 0x11000000;
    // Disable UART 5 to make Edits
    UART2_CTL_R &=~ 0x00000001;
    // Enable TX & RX
    UART2_CTL_R |= 0x00000300;
    // Set Baud Rate Whole Number
    UART2_IBRD_R = UART_IBRD_9600;
    // Set Baud Rate Decimal
    UART2_FBRD_R = UART_FBRD_9600;
    // Choose word length 8 bits & Disable FIFO
    UART2_LCRH_R =  UART_LCRH_8_FIFO;
    #if UART2_INT == UART_INT_ACTIVE
        // Clear Interrupt flag
        UART2_ICR_R &= ~(0x0780);
        // Enable Receive Interrupt for UART2
        UART2_IM_R |= 0x10;
        // Enable UART2 Interrupt from NVIC (Interrupt 33 / VECTOR 49)
        SET_BIT(NVIC_EN1_R, (INT_UART2-16-32));
    #endif
    // Enable UART6
    UART2_CTL_R |= 0x00000001;
}

void MUART5_voidInit(void)
{
    // Activate Clock on the Required UART
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART5_MASK;
    // Activate Clock on the Required GPIO
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIOE_UART5_MASK;
    // Wait for Clock
    TwoCyclesWait();
    // Unlock GPIO Port
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    // Allow Commit Changes to the required pin
    GPIO_PORTE_CR_R |= UART5_GPIOE_TXRX_MASK;
    // Enable Alternative Function for the required Pin
    GPIO_PORTE_AFSEL_R |= UART5_GPIOE_TXRX_MASK;
    // Enable Digital Mode for the required Pin
    GPIO_PORTE_DEN_R |= UART5_GPIOE_TXRX_MASK;
    // Disable Analog Mode for the required Pin
    GPIO_PORTE_AMSEL_R &=~ UART5_GPIOE_TXRX_MASK;
    // Choose UART Alternative Function for PINS E4 & E5
    GPIO_PORTE_PCTL_R &=~ 0x00FF0000;
    GPIO_PORTE_PCTL_R |= 0x00110000;
    // Disable UART 5 to make Edits
    UART5_CTL_R &=~ 0x00000001;
    // Enable TX & RX
    UART5_CTL_R |= 0x00000300;
    // Set Baud Rate Whole Number
    UART5_IBRD_R = UART_IBRD_9600;
    // Set Baud Rate Decimal
    UART5_FBRD_R = UART_FBRD_9600;
    // Choose word length 8 bits & Disable FIFO
    UART5_LCRH_R =  UART_LCRH_8_FIFO;
    #if UART5_INT == UART_INT_ACTIVE
        // Clear Interrupt flag
        UART5_ICR_R &= ~(0x0780);
        // Enable Receive Interrupt for UART5
        UART5_IM_R |= 0x10;
        // Enable UART5 Interrupt from NVIC (Interrupt 61 / VECTOR 77)
        SET_BIT(NVIC_EN1_R, (INT_UART5 - 16 - 32));
    #endif
    // Enable UART5
    UART5_CTL_R |= 0x00000001;

}

/************************************************************************************************/

uint8 MUART0_voidReceiveByte(void)
{
    while(UART0_FR_R & 0x10 == 1);
    return UART0_DR_R;
}

uint8 MUART1_voidReceiveByte(void)
{
    while(UART1_FR_R & 0x10 == 1);
    return UART1_DR_R;
}

uint8 MUART2_voidReceiveByte(void)
{
    while(UART2_FR_R & 0x10 == 1);
    return UART2_DR_R;
}

uint8 MUART5_voidReceiveByte(void)
{
    while(UART5_FR_R & 0x10 == 1);
    return UART5_DR_R;
}

/************************************************************************************************/

void MUART0_u8SendByte(uint8 Copy_u8Data)
{
    while (UART0_FR_R & 0x20 == 1);
    UART0_DR_R  = Copy_u8Data;
}

void MUART1_u8SendByte(uint8 Copy_u8Data)
{
    while (UART1_FR_R & 0x20 == 1);
    UART1_DR_R  = Copy_u8Data;
}

void MUART2_u8SendByte(uint8 Copy_u8Data)
{
    while (UART2_FR_R & 0x20 == 1);
    UART2_DR_R  = Copy_u8Data;
}

void MUART5_u8SendByte(uint8 Copy_u8Data)
{
    while (UART5_FR_R & 0x20 == 1);
    UART5_DR_R  = Copy_u8Data;
}

/************************************************************************************************/

uint8 MUART0_voidSendString(char * Ptr_u8String)
{
    uint16 Local_u16Timeout=0;
    uint8 Local_u8Counter=0;
    while (Ptr_u8String[Local_u8Counter] != '\0')
    {
        while (UART0_FR_R & 0x20 == 1)
        {
            Local_u16Timeout++;
            if (Local_u16Timeout == 100000)
            {
                return 1;
            }
        }
        UART0_DR_R = Ptr_u8String[Local_u8Counter];
        Local_u8Counter++;
    }
    return 0;
}

uint8 MUART1_voidSendString(char * Ptr_u8String)
{
    uint16 Local_u16Timeout=0;
    uint8 Local_u8Counter=0;
    while (Ptr_u8String[Local_u8Counter] != '\0')
    {
        while (UART1_FR_R & 0x20 == 1)
        {
            Local_u16Timeout++;
            if (Local_u16Timeout == 100000)
            {
                return 1;
            }
        }
        UART1_DR_R = Ptr_u8String[Local_u8Counter];
        Local_u8Counter++;
    }
    return 0;
}

uint8 MUART2_voidSendString(char * Ptr_u8String)
{
    uint16 Local_u16Timeout=0;
    uint8 Local_u8Counter=0;
    while (Ptr_u8String[Local_u8Counter] != '\0')
    {
        while (UART2_FR_R & 0x20 == 1)
        {
            Local_u16Timeout++;
            if (Local_u16Timeout == 100000)
            {
                return 1;
            }
        }
        UART2_DR_R = Ptr_u8String[Local_u8Counter];
        Local_u8Counter++;
    }
    return 0;
}

uint8 MUART5_voidSendString(char * Ptr_u8String)
{
    uint16 Local_u16Timeout=0;
    uint8 Local_u8Counter=0;
    while (Ptr_u8String[Local_u8Counter] != '\0')
    {
        while (UART5_FR_R & 0x20 == 1)
        {
            Local_u16Timeout++;
            if (Local_u16Timeout == 5000)
            {
                return 1;
            }
        }
        UART5_DR_R = Ptr_u8String[Local_u8Counter];
        Local_u8Counter++;
    }
    return 0;
}

/************************************************************************************************/

static uint8 TwoCyclesWait(void)
{
    uint8 i;
    i=2;
    return i;
}



