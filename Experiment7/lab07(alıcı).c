#include <16F887.h>
#include <stdlib.h>
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT,NOWRT, NODEBUG, NOCPD
#use delay(clock=4M)
#define use_portb_lcd TRUE 
#include <lcd.c>

#use rs232 (baud=9600,xmit=PIN_C6, rcv=PIN_C7, parity=N, stop=1) 
int counter = 0; 
char strInput[8];
char id1[2];
char id2[2];
unsigned long inputString; 
unsigned long K_p;
unsigned long K_i;
unsigned long K_d;

void main()
{
   lcd_init();
   delay_ms(10);
   
   while(1)
   {
      if(kbhit()) 
      {
         char i = getc(); 
         
         if (i == 'P')
         {
            counter = 0;
            printf("Incoming Data: %s  ",strInput);
            inputString = atol(strInput); 
            K_p = inputString;
            printf(LCD_PUTC,"\fK_p=%lu",inputString);
            memset(strInput, 0, 8);
         }
         
           if (i == 'I')
         {
            counter = 0;
            id1[0]=strInput[1];
            id1[1]=strInput[2];
            printf("Incoming Data: %s  ",id1);
            inputString = atol(id1); 
            K_i = inputString;
            printf(LCD_PUTC,"\fK_i=%lu",K_i);
            memset(id1, 0, 2);
            memset(strInput, 0, 8);
         }
         
           if (i == 'D')
         {
            counter = 0;
            id2[0]=strInput[1];
            id2[1]=strInput[2];
            printf("Incoming Data: %s  ",id2);
            inputString = atol(id2); 
            K_d = inputString;
            printf(LCD_PUTC,"\fK_d=%lu",K_d);
            memset(id2, 0, 2);
            memset(strInput, 0, 8);
         }
        
         else
         {
            strInput[counter] = i; 
            counter++; 
         }
      }
   }
}
