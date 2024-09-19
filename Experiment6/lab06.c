#include <16F887.h>
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT,NOWRT, NODEBUG, NOCPD
#use delay(clock=4M)
void main()
{
 unsigned int8 i=1;
 int16 num = 0;
 set_tris_c(0x00); 
 setup_ccp2(CCP_PWM);
 set_pwm2_duty(0);
 
 while(1){
 if(num %2 == 0){
 output_high(pin_c2);
 output_low(pin_c3);
 }
 
 if(num %2 == 1){
 output_high(pin_c3);
 output_low(pin_c2);
 }
 
 if(input(pin_a0))
 {
 i+=1;
 if(i >51){
 i=51;
 }
 set_pwm2_duty(i*5);
 delay_ms(50);
 }
 if(input(pin_a1))
 {
 i-=1;
 if(i <1){
 i=1;
 }
 set_pwm2_duty(i*5);
 delay_ms(50);
 }
 if(input(pin_a2))
 {
 num++;
 delay_ms(500);
 }
 }
}
