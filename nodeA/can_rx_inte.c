/*can1rx_intr.c*/
#include <LPC21xx.H>
#include"header.h"
extern u32 flag1;
extern can1 c;
void can1rx_handler(void)__irq
{
        c.id=C2RID;
        c.dlc=(C2RFS>>16)&0XF;
        c.rtr=(C2RFS>>30)&1;
        if(c.rtr==1)
        {
                uart0_tx_string("remote frame\r\n");
        }
        else
        {
                flag1^=1;
                c.byteA=C2RDA;
        }
        C2CMR=(1<<2);
        VICVectAddr=0;
}
void config_vic_for_can1rx(void){
        VICIntSelect=0;
        VICVectAddr4=(u32)can1rx_handler;
        VICVectCntl4=27|(1<<5);
        VICIntEnable=1<<27;
        C2IER=1;
}
