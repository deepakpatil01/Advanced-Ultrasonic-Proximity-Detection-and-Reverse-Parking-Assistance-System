/*can1_deiver.c*/
#include <LPC21xx.H>
#include"header.h"
u32 *ptr = (u32*)0xE0038000;
void can1_init(void)
{
        PINSEL1=0x14000;
        VPBDIV=1;
        C2MOD=1;
        C2BTR=0X001C001D;
        //af for embeddee c
        ptr[0]=0x20002050;
        SFF_sa=0;
        SFF_GRP_sa=0x4;
        EFF_sa=0X4;
        EFF_GRP_sa=0X4;
        ENDofTable=0X4;
        AFMR=0;
        C2MOD=0;// reset mode off
}
#define TCS ((C2GSR>>3)&1)
void can1_tx(can1 v)
{
        C2TID1=v.id;
        C2TFI1=(v.dlc<<16);
        if(v.rtr==0)
        {
                C2TDA1=v.byteA;
                C2TDB1=v.byteB;
        }
        else
        {
                C2TFI1|=(1<<30);
        }
        C2CMR=1|(1<<5);
        while(TCS==0);
}
#define RBS (C2GSR&1)
void can1_rx(can1 *ptr)
{
        while(RBS==0);
        ptr->id=C2RID;
        ptr->dlc=(C2RFS>>16)&0XF;
        ptr->rtr=((C2RFS>>30)&1);
        if(ptr->rtr==0)
        {
                ptr->byteA=C2RDA;
                ptr->byteB=C2RDB;
        }
        C2CMR=(1<<2);
}
