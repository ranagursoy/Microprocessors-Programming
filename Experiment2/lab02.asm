
	list 	p=16F887     	
	#include <p16F887.inc>	
	
__config    _CONFIG1,b'1110000011100001'
__config    _CONFIG2,b'1111100011111111'

	org	0x00
	    
sayac	    EQU	    H'20'
sayac1	    EQU	    H'21'
sayac2	    EQU	    H'22'
	

	bsf	STATUS,5
	movlw	B'00000001'
	movwf	TRISD
	bcf	STATUS,5
	clrf	PORTD
	
main
	btfss	PORTD,0
	goto	main
	goto	buzzer1
	
					
buzzer1
	bsf	PORTD,1
	call	delay_3_sec
	bcf	PORTD,1
	call	delay_3_sec

	
	bsf	PORTD,1
	call	delay_3_sec
	bcf	PORTD,1
	call	delay_3_sec
	
	btfsc	PORTD,0
	goto	buzzer1
	goto	main
		
delay_one_ms
	movlw	D'250'
	movwf	sayac
			
loop_one_ms
	nop
	decfsz	sayac,F
	goto	loop_one_ms
	return

delay_250_ms
	movlw	D'250'
	movwf	sayac1

loop_250_ms
	call	delay_one_ms
	decfsz	sayac1,F
	goto	loop_250_ms
	return

delay_3_sec
	movlw	D'12'
	movwf	sayac2

loop_3_sec
	call	delay_250_ms
	decfsz	sayac2,F
	goto	loop_3_sec
	return
	
	end


