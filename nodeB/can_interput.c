/*can_intr.c*/
#include <LPC21xx.H>
#include"header.h"
extern u32 flag;
extern can1 m;
void can1rx_handler(void)__irq
{
        m.id=C2RID;
        m.dlc=(C2RFS>>16)&0XF;
        m.rtr=(C2RFS>>30)&1;
        if(m.rtr==1)
        {
                flag^=1;
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
