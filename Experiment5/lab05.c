#include <16F887.h>
#device adc=10
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD
#use delay(clock = 4M)
#define use_portb_lcd TRUE       // LCD in B Port
#include <lcd.c>

unsigned int16 result_1;            //variable for A0 value
unsigned int16 result_2;            //variable for A1 value
int counter=0;

#int_timer0

void timer0(void)
{
   set_timer1(60);
   counter++;
   
   if(counter==40)
   {
      set_adc_channel(0); // next analog reading will be from channel 0
      delay_us(10); //allow time after channel selection and reading
      result_1 = read_adc(); //start and read A/D
      set_adc_channel(1); // next analog reading will be from channel 1
      delay_us(10); //allow time after cha`nnel selection and reading
      result_2 = read_adc(); //start and read A/D
      counter=0;
   }
}


void main()
{
   lcd_init();
   delay_ms(10);
   //setup_adc_ports(ALL_ANALOG); //A0 A1 A2 A3 A5 E0 E1 E2 analog pins
   setup_adc_ports(sAN0|sAN1|sAN3); //A0 A1 A3 are configured for analog input pin
   setup_adc(ADC_CLOCK_DIV_32); //enable ADC and set clock for ADC
   
   set_adc_channel(0); // next analog reading will be from channel 0
   delay_us(10); //allow time after channel selection and reading
   result_1 = read_adc(); //start and read A/D
   
   set_adc_channel(1); // next analog reading will be from channel 1
   delay_us(10); //allow time after channel selection and reading
   result_2 = read_adc(); //start and read A/D
   
   while(1)
   {
      printf(LCD_PUTC,"\fValue1=%lu",result_1); //print ADC value for A0
      printf(LCD_PUTC,"\nValue2=%lu",result_2); //print ADC value for A1
      delay_ms(200);
      setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
      set_timer0(60);
      enable_interrupts(INT_timer0);
      enable_interrupts(GLOBAL);
   }
}

