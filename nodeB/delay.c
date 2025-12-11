#include<lpc21xx.h>
void delay_sec(unsigned int sec)
{
//   unsigned int result=0,pclk;
//   int a[5]={15,60,30,15,15};
//   pclk= a[VPBDIV]*1000000;
   T0PC=0;
   T0PR=60000000-1;
   T0TC=0;
   T0TCR=1;
   while(T0TC<sec);
   T0TCR=0;
}
void delay_ms(unsigned int ms)
{
//   unsigned int result=0,pclk;
//   int a[5]={15,60,30,15,15};
//   pclk= a[VPBDIV]*1000;
   T0PC=0;
   T0PR=60000-1;
   T0TC=0;
   T0TCR=1;
   while(T0TC<ms);
   T0TCR=0;
}
void delay_us(unsigned int us)
{
//   unsigned int result=0,pclk;
//   int a[5]={15,60,30,15,15};
//   pclk= a[VPBDIV]*1000;
   T0PC=0;
   T0PR=60-1;
   T0TC=0;
   T0TCR=1;
   while(T0TC<us);
   T0TCR=0;
}

