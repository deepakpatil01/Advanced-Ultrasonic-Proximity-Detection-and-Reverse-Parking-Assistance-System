typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef signed char s8;
typedef float f32;

extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);
extern void delay_us(unsigned int us);

extern void led(void);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_4data(unsigned char data);
extern void lcd_4cmd(unsigned char cmd);
extern void lcd_4init(void);
extern void lcd_4string(char *ptr);
extern void lcd_4integer(int num);
extern void lcd_4float(f32 f);
extern void lcd_4scroll(char *p);
//extern void lcd_cgram();

extern void uart0_init(unsigned int baud);
extern void uart0_tx(char data);
extern void uart0_tx_string(char *p);
extern unsigned char uart0_rx(void);
extern void uart0_tx_hex(s32 temp);
extern void uart0_rx_string(char *ptr,char max_bytes);
extern void uart0_integer(int num);
extern void uart0_bin(char temp);
extern void uart0_float(float f);

extern void config_vic_for_uart0(void);
extern void config_uart0(void);

extern void adc_inti(void);
extern unsigned int adc_read(unsigned char ch_num);

extern void config_VIC_for_EINT0(void);
extern void config_EINT0(void);

extern void config_VIC_for_EINT1(void);
extern void config_EINT1(void);

extern void config_VIC_for_EINT2(void);
extern void config_EINT2(void);

#define CS0 (1<<7)
extern void spi0_init(void);
extern u8 spi0(u8 data);
extern u32 mcp3204_read(u8 ch_num);
extern void mcp25aa010a_write(u8 data,u8 add);

extern void i2c_init(void);
extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);

typedef struct CAN1MSG
{
        u32 id;
        u32 byteA;
        u32 byteB;
        u8 dlc;
        u8 rtr;
}can1;

extern void can1_init(void);
extern void can1_tx(can1 v);
extern void can1_rx(can1 *ptr);
extern void config_vic_for_can1rx(void);
extern void send_pulse(void);
extern int distance(void);

