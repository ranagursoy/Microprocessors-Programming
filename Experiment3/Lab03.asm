	    LIST	p = 16F887
	    #INCLUDE	<p16F887.inc>
	    
__config _CONFIG1,b'1110000011100001'
__config _CONFIG2,b'1111100011111111'
	    
	    ORG		0x00
SAYAC	    EQU		H'20'
SAYAC1	    EQU		H'21'
SAYAC2	    EQU		H'22'
	    GOTO	MAIN
	    
	    ORG		0x04
	    CALL	DELAY_1_SEC
	    GOTO	TMR0_INT
	    
MAIN
	    BANKSEL	ANSEL
	    CLRF	ANSEL
	    CLRF	ANSELH
	    
	    BCF		STATUS,6
	    BSF		STATUS,5
	    
	    MOVLW	B'11010000'
	    MOVWF	OPTION_REG
	    MOVLW	B'10100000'
	    MOVWF	INTCON
	    CLRF	TRISB

	    BCF		STATUS,5
	    CLRF	PORTB
	    
LOOP
	    GOTO	LOOP
	    
TMR0_INT
	    BCF		INTCON,2
	    MOVLW	H'01'
	    XORWF	PORTB,F
	    CLRF	TMR0
	    RETFIE
	    
	    

DELAY_ONE_MS
	    MOVLW	D'250'
	    MOVWF	SAYAC	    
LOOP_ONE_MS
	    NOP
	    DECFSZ	SAYAC,F
	    GOTO	LOOP_ONE_MS
	    RETURN
	    
DELAY_250_MS
	    MOVLW	D'250'
	    MOVWF	SAYAC1
LOOP_250_MS
	    CALL	DELAY_ONE_MS
	    DECFSZ	SAYAC1,F
	    GOTO	LOOP_250_MS
	    RETURN
	    
DELAY_1_SEC
	    MOVLW	D'4'
	    MOVWF	SAYAC2
LOOP_1_SEC
	    CALL	DELAY_250_MS
	    DECFSZ	SAYAC2,F
	    GOTO	LOOP_1_SEC
	    RETURN
	    
	    END