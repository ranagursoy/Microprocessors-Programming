#include <16F887.h>
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT,NOWRT, NODEBUG, NOCPD
#use delay(clock=4M)

#use rs232 (baud=9600,xmit=PIN_C6, rcv=PIN_C7, parity=N, stop=1) 

void main()
{
   while(1) 
   {
      printf("1");
      delay_ms(500);
      printf("3");
      delay_ms(500);
      printf("P");
      delay_ms(500);
      printf("6");
      delay_ms(500);
      printf("9");
      delay_ms(500);
      printf("I");
      delay_ms(500);
      printf("6");
      delay_ms(500);
      printf("3");
      delay_ms(500);
      printf("D");
      delay_ms(5000);
   }
}
