#include<lpc21xx.h>
#include"header.h"
#define LED 1<<17
u32 flag=0;
can1 m;
main()
{
        int j;
        can1_init();
        config_vic_for_can1rx();
        uart0_init(9600);
        uart0_tx_string("nodeB");
        while(1)
        {
                if(flag==1)
                {
                        m.id=0x57;
                        m.rtr=0;
                        m.dlc=1;

            j=distance();
                        m.byteA=j;
                        uart0_integer(j);
                        uart0_tx_string("\r\n");
                        can1_tx(m);
                        delay_ms(250);
                }
        }
}

