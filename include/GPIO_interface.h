#ifndef GPIO_INTERAFCE_H
#define GPIO_INTERAFCE_H

/*  Pin values  */
#define GPIO_HIGH  1
#define GPIO_LOW   0

/*   PORTS    */
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5

/* PINS  */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8

/* DIRECTIONS */
#define GPIO_DIGITAL_INPUT    0
#define GPIO_DIGITAL_OUTPUT   1

/* PULL_UP_DOWN */
#define GPIO_PULL_UP     0
#define GPIO_PULL_DOWN   1

void MGPIO_voidSetPinDigitalDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);
void MGPIO_voidEnablePullUpDown(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_Pull_UP_DOWN);
void MGPIO_voidSetPinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);
uint8 MGPIO_u8GetPinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin);
void MGPIO_voidTogglePinDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Pin);
void MGPIO_voidSetPortDigitalDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction);
void MGPIO_voidSetPortDigitalValue(uint8 Copy_u8Port, uint8 Copy_u8Value);

#endif
