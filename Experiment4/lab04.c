#include <16F887.h>

#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay(clock=4000000)

#define use_portb_lcd TRUE // LCD in B Port

#include <lcd.c> //usage of LCD is defined, do not define this before the upper lines

 

 

int16 sayi1=0;

int16 sayi=0;

int x=0;

int islem=0;

int32 sonuc=0;

 

 

 

void sonuc_bul()

{

  if(sayi1 > 9 && sayi1<100){if(sayi > 9 && sayi < 100){

delay_ms(100);

printf(lcd_putc,"#");

  

   

   switch (islem)

   {

  

   case 1 :

   sonuc=(sayi1)+(sayi);

   printf(lcd_putc,"%ld",sonuc);

   sayi1=0;

   sayi=0;

   x=0;

   islem=0;

   sonuc=0;

  

   break;

   }

  

   islem=0;

 

  delay_ms(3000);lcd_putc("\f");}else{delay_ms(100);lcd_putc("\f");printf(lcd_putc,"#");printf(lcd_putc,"Please enter a 2-digit number");delay_ms(1000);lcd_putc("\f"); sayi1=0;sayi=0;x=0;islem=0;sonuc=0; }

  }//if parantezi

else{delay_ms(100);lcd_putc("\f"); printf(lcd_putc,"#");printf(lcd_putc,"Please enter a 2-digit number");delay_ms(1000);lcd_putc("\f"); sayi1=0;sayi=0;x=0;islem=0;sonuc=0; }

 

}

 

 

   char tus()

   {

       output_high(pin_c4);

    if(input(pin_c0)){ while(input(pin_c0));printf(lcd_putc,"7"); x=7; sayi=sayi*10 +x; }

    if(input(pin_c1)){ while(input(pin_c1));printf(lcd_putc,"8"); x=8; sayi=sayi*10 +x; }

    if(input(pin_c2)){ while(input(pin_c2));printf(lcd_putc,"9"); x=9; sayi=sayi*10 +x; }

    if(input(pin_c3)){ while(input(pin_c3));printf(lcd_putc,"\f A");printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0;}

     output_low(pin_c4);

   

    

    output_high(pin_c5);

    if(input(pin_c0)){ while(input(pin_c0));printf(lcd_putc,"4"); x=4; sayi=sayi*10 +x; }

    if(input(pin_c1)){ while(input(pin_c1));printf(lcd_putc,"5"); x=5; sayi=sayi*10 +x; }

    if(input(pin_c2)){ while(input(pin_c2));printf(lcd_putc,"6"); x=6; sayi=sayi*10 +x; }

    if(input(pin_c3)){ while(input(pin_c3));printf(lcd_putc,"\f B"); printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0; }

     output_low(pin_c5);

   

    

    output_high(pin_c6);

    if(input(pin_c0)){ while(input(pin_c0));printf(lcd_putc,"1"); x=1; sayi=sayi*10 +x; }

    if(input(pin_c1)){ while(input(pin_c1));printf(lcd_putc,"2"); x=2; sayi=sayi*10 +x; }

    if(input(pin_c2)){ while(input(pin_c2));printf(lcd_putc,"3"); x=3; sayi=sayi*10 +x; }

    if(input(pin_c3)){ while(input(pin_c3));printf(lcd_putc,"\f C");printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0;}

     output_low(pin_c6);

   

    

    

    output_high(pin_c7);

    if(input(pin_c0)){ while(input(pin_c0));printf(lcd_putc,"*");sayi1=sayi; islem=1; sayi=0; }

    if(input(pin_c1)){ while(input(pin_c1));printf(lcd_putc,"0"); x=0; sayi=sayi*10 +x; }

    if(input(pin_c2)){while(input(pin_c2));sonuc_bul() ; }   //sonuç buradan resetleniyor

    if(input(pin_c3)){ while(input(pin_c3));printf(lcd_putc,"\f D");printf(lcd_putc,"\f");sayi1=0;sayi=0;x=0;islem=0;sonuc=0; }

    output_low(pin_c7);

 

      return sayi,sayi1,islem;

  

}

 

 

 

 

 

 

void main()

 

{

    set_tris_b(0x00);

    set_tris_c(0b11110000);

   

    lcd_init();

 

    while(true)

    {

  

    tus();

   

    }

}

