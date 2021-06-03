#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"

int main(void)
{
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN0, GPIO_DIGITAL_INPUT);

    MGPIO_voidEnablePullUpDown (GPIO_PORTF, PIN0, GPIO_PULL_UP);

    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN1, GPIO_DIGITAL_OUTPUT);
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN2, GPIO_DIGITAL_OUTPUT);
    MGPIO_voidSetPinDigitalDirection(GPIO_PORTF, PIN3, GPIO_DIGITAL_OUTPUT);

    while(1)
    {
        /* Check the switch state */
        if(MGPIO_u8GetPinDigitalValue(GPIO_PORTF, PIN0) == 0)
        {
            MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN1, GPIO_HIGH);
        }
        else
        {
            MGPIO_voidSetPinDigitalValue(GPIO_PORTF, PIN1, GPIO_LOW);
        }
    }
}

