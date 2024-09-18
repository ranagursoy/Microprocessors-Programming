
	list 	p=16F887     	
	#include <p16F887.inc>	
	
__config    _CONFIG1,b'1110000011100100'
__config    _CONFIG2,b'1111100011111111'

    
	org	0x00
	bsf	STATUS,5
	movlw	B'00000001'
	movwf	TRISD
	bcf	STATUS,5
	
Main
	btfsc	PORTD,0
	goto	Next
	bsf	PORTD,1
	goto	Check
					
Next
	bcf	PORTD,1
	
		
Check
	btfsc	PORTD,2
	goto	Next1
	bsf	PORTD,3
	goto	Main
		
Next1
	bcf	PORTD,3
	goto	Main
	end