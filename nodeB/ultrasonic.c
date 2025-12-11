#include <LPC21xx.H>//rx
#include"header.h"
#define TRIG (1<<8)
#define ECHO (1<<9)
void send_pulse(void)
{
     IODIR0|=TRIG;
    IOSET0=TRIG;
    delay_us(10);
    IOCLR0=TRIG;
}
int distance(void)
{
    u32 distance;
    send_pulse();
    T0PC=0;
    T0TC=0;
    while(((IOPIN0)>>9&1)==0);
    T0TCR=1;
    while(((IOPIN0>>9)&1)==1);
    T0TCR=0;
    distance=T0TC;
    if(distance<38000)
        distance=distance/59;
    else
        distance=0;
    return distance;

}

