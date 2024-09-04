				AREA asm_functions, CODE, READONLY	
	
;definizione di costanti e register renaming
;MY_CONST EQU 36
;my_register RN 0
; Per leggere 8 bit  ldrb r1, [array, r4]  // Load byte from array + offset (r4) da incrementare di 1
; Per scrivere su 8 bit strb valore_da_scrivere, [array, offset]   
; Per leggere 16 bit  ldrh r1, [array, r0, lsl #1]   // Load byte from array + offset (r4) da incrementare di 1
; Per scrivere su 16 bit strb valore_da_scrivere, [array, contatore, #lsl #1] 
; Per leggere 32 bit  ldr r1, [array, r0, lsl #2]   // Load byte from array + offset (r4) da incrementare di 1
; Per scrivere su 32 bit STR valore_da_scrivere, [array, contatore, lsl #2]
get_and_sort	PROC
				EXPORT get_and_sort
						
				PUSH {r4-r12,lr}
				;r0 = vett
				;r1= val
				;r2= n
				mov r3,r2  ;contatore
				cmp r2,#0
				BLE skip
				mov r4,r2
				sub r4,r4,#1 ; puntatore elemento i-1
loop			
				ldrb r6, [r0, r3] ;elemento i esimo
				ldrb r7, [r0, r4]; elementi i-1 esimo
				CMP r6,r7
				BLE skip_swap
				MOV r8,r6
				MOV r9,r7
				strb r8,[r0,r4]
				strb r9,[r0,r3]				
skip_swap
				sub R3, R3, #1
				sub r4,r4,#1
				CMP R3,#0
				BNE loop
skip
				mov r0,r1
				POP {r4-r12,pc} ;restore di tutti i registri utilizzati nel mio codice
				ENDP				
				END
					
			