#include"string.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"UART_interface.h"

#include"LCD_interface.h"
#include"GPS_interface.h"

# define REQUIRED_DISTANCE  100

int main(void)
{
    // Initialize RED & BLUE & GREEN LEDs
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN1, GPIO_DIGITAL_OUTPUT);
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN2, GPIO_DIGITAL_OUTPUT);
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN3, GPIO_DIGITAL_OUTPUT);

    // Initialize Switch 1
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN0, GPIO_DIGITAL_INPUT);
    MGPIO_voidEnablePullUpDown(GPIO_PORTF, PIN0, GPIO_PULL_UP);

    // Initialize LCD
    HLCD_voidInit();

    // Initialize GPS Module
    HGPS_voidInit();

    // Turn ON RED LED
    MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN1, GPIO_HIGH);

    while(MGPIO_u8GetPinDigitalValue(GPIO_PORTF, PIN0) == 1);
    // Turn OFF RED LED
    MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN1, GPIO_LOW);

    // Turn ON BLUE LED
    MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN2, GPIO_HIGH);

    HGPS_voidStart();
    while(1)
    {
        extern volatile float Distance;
        if (Distance >= REQUIRED_DISTANCE)
        {
            // Turn OFF BLUE LED
            MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN2, GPIO_LOW);

            // Turn ON GREEN LED
            MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN3, GPIO_HIGH);
        }
    }
}
