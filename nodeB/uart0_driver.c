#include<lpc21xx.h>
void uart0_init(unsigned int baud)
{
        unsigned int result=0,pclk;
        int a[5]={15,60,30,15,15};
         pclk= a[VPBDIV]*1000000;
         result=pclk/(16*baud);
         PINSEL0|=5;
         U0LCR=0X83;
         U0DLL=result&0xFF;
         U0DLM=(result>>8)&0XFF;
         U0LCR=3;

}
#define THRE  ((U0LSR>>5)&1)==0
void uart0_tx(unsigned char data)
{
        U0THR=data;
        while(THRE);
}
void uart0_tx_string(unsigned char *p)
{
        while(*p)
        {
                        U0THR=*p;
                while(THRE);
                p++;

        }
}
#define RTHR (U0LSR&1)==0
unsigned char uart0_rx()
{
        while(RTHR);
        return U0RBR;
}
void uart0_tx_hex(int temp)
{
unsigned char n1,n2;
uart0_tx('0');
uart0_tx('x');
n1=((temp>>4)&0x0f)+48;
n2=(temp&0x0f)+48;
if(n1>=58)
{
uart0_tx('A'+n1-58);
}
else
{
uart0_tx(n1);
}
if(n2>=58)
{
uart0_tx('A'+n2-58);
}
else
{
uart0_tx(n2);
}
}
void uart0_integer(int num)
{
    int a[10],i;
    if(num==0)
        uart0_tx('0');
    else if(num<0)
    {
        uart0_tx('-');
        num=-num;
    }
    i=0;
    while(num>0)
    {
        a[i]=num%10+48;
        num=num/10;
        i++;
    }
    for(i=i-1;i>=0;i--)
    {
        uart0_tx(a[i]);
    }
}
void uart0_float(float f)
{
  int num;
    if(f==0)
    {
        uart0_tx_string("0.0");
        return;
    }
    if(f<0)
    {
        uart0_tx('-');
        f=-f;
    }
        num=f;
        uart0_integer(num);
        uart0_tx('.');
        num=(f-num)*1000;
        uart0_integer(num);
}
