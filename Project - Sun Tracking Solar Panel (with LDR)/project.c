#include <16F887.h>         // introduce 16F887
#device ADC = 8           // 8 bits adc will be used
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT,NOWRT, NODEBUG, NOCPD         // 16F887 configuration settings
#use delay(clock=4M)        // set oscillator frequency 

unsigned long int ldr_1;    // analog value variable to be read from first ldr sensor
unsigned long int ldr_2;    // analog value variable to be read from second ldr sensor
float val_1;
float val_2;

void main()
{
 set_tris_a(0b11111111);    // select Port A
 set_tris_c(0b00000000);    // select Port C
 output_c(0b00000000);      // output of Port C arrange logic 0
 
 setup_adc(adc_clock_div_32);       // adc reading speed
 setup_adc_ports(all_analog);       // sets all pins to analog input 
 setup_timer_2(t2_div_by_4,255,1);  // set timer2 
 setup_ccp2(ccp_pwm);               // CPP2 PMW mode activated

 set_pwm2_duty(33);         //PMW duty cycle time set to 33

 while(1)                   // endless loop
 {
     set_adc_channel(0);    //the next read_adc call will read
     ldr_1 = read_adc();    // ADC is read and assigned to variable ldr_1    
     val_1 = ldr_1;
     delay_us(20);          // delay to 20ms

     set_adc_channel(1);     //the next read_adc call will read
     ldr_2 = read_adc();
     val_2 = ldr_2;         // ADC is read and assigned to variable ldr_2  
     delay_us(20);          // delay to 20ms 
     
     if(val_1 > val_2)      // if the first ldr sensor is getting light, the engine rotation pattern
     {
         output_high(pin_c2);   // first ldr sensor opened to read
         output_low(pin_c3);    // second ldr sensor closed to read
         delay_ms(20);          // delay to reading 
     }
    
     if(val_1 < val_2)      // if the second ldr sensor is getting light, the engine rotation pattern
     {
         output_high(pin_c3);   // second ldr sensor opened to read
         output_low(pin_c2);    // first ldr sensor closed to read
         delay_ms(20);          // delay to reading 
     }
     
     else                  // if both sensor get light, or both do not get light, the engine stop
     {
         output_low(pin_c2);    // first ldr sensor closed to read
         output_low(pin_c3);    // second ldr sensor closed to read
     }
 }
}


