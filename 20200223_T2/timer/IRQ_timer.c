/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../led/led.h"
#include "../RIT/RIT.h"
#include "../../common.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
#define N 4
extern unsigned char VETT[N];
extern int input_disattivo;
int blink=0;
int cnt=0;

void TIMER0_IRQHandler (void)
{
	// Match register 0 interrupt service routine
	/*if (LPC_TIM0->IR & 1){
		LPC_TIM0->IR = 1;			// clear interrupt flag 
	}
	// Match register 1 interrupt service routine 
	else if(LPC_TIM0->IR & 2){
		//ESEMPIO:  setta il match register ad un nuovo valore quando raggiunge una certa soglia
	  
		//if(LPC_TIM0->MR1 == 0x0bebc20)  
			 //LPC_TIM0->MR1 = 0x017D7840;
		//else
			 //LPC_TIM0->MR1 = 0x0bebc20;
		
		//LPC_TIM0->IR =  2 ;			// clear interrupt flag 	
	}
	// Match register 2 interrupt service routine 
	else if(LPC_TIM0->IR & 4){
		LPC_TIM0->IR =  4 ;			// clear interrupt flag 
	}
	// Match register 3 interrupt service routine 
	else if(LPC_TIM0->IR & 8){
		LPC_TIM0->IR =  8 ;			  // clear interrupt flag 
	}*/
	
	
	LPC_TIM0->IR = 1;
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
/*
if(blink%2==0){
		LED_Out(VETT[cnt]);
		cnt++;
		blink++;		
	}
	else{
		LED_Out(0);
			if(cnt==N){
			cnt=0;
			blink=0;
			disable_timer(2);    avevo fatto il lampeggio
			reset_timer(2);
			reset_timer(1);
			enable_timer(1);
			init_vett();
		}
		else{
		blink++;
		}
	}
	*/



void TIMER2_IRQHandler (void)
{
	if (cnt<N){
	LED_Out(VETT[cnt]);
		cnt++;
	}
	else{
		LED_Out(0);
		cnt=0;
		blink=0;
		disable_timer(2);
		reset_timer(2);
		reset_timer(1);
		enable_timer(1);
		init_vett();
	}
	 LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Timer/Counter 3 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER3_IRQHandler (void)
{
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}





/******************************************************************************
**                            End Of File
******************************************************************************/
