#include <stdio.h>
#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "GPIO_private.h"
#include "UART_config.h"



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
    // Enable UART5
    UART5_CTL_R |= 0x00000001;

}

static uint8 TwoCyclesWait(void)
{
    uint8 i;
    i=2;
    return i;
}



