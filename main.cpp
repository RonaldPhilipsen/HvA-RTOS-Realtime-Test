#include "main.hpp"
#include <wiringPi.h>

volatile int eventCounter = 0;
volatile int lastEventCounter = 0;

int main(int argc, char const *argv[])
{
    if (wiringPiSetup() < 0)
    {
        fprintf(stderr, "Unable to setup wiringPi: %s\n", strerror(errno));
        return 1;
    }

    // set Pin 17/0 generate an interrupt on high-to-low transitions
    // and attach myInterrupt() to the interrupt
    if (wiringPiISR(BUTTON_PIN, INT_EDGE_RISING, &IRQHandler) < 0)
    {
        fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
        return 1;
    }

    // display counter value every second.
    while (1)
    {
        if (eventCounter != lastEventCounter)
        {
            lastEventCounter = eventCounter;
            printf("%d\n", eventCounter);
        }

        delay(1000); // wait 1 second
    }
    return 0;
}

void IRQHandler()
{
    eventCounter++;
}