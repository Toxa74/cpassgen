/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#include <htc.h>            /* HiTech General Includes */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"


/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

void interrupt isr(void)
{
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

#if 1
    
    /* TODO Add High Priority interrupt routine code here. */

    /* Determine which flag generated the interrupts */
    if(INTCONbits.RBIF) // If RB port changed ...
    {
//        int_counter++;
        INTCONbits.RBIF = 0; /* Clear RB port changed interrupt flag. */
    }
    else if (PIR1bits.TMR1IF)   // TMR 1 interrupt ?
    {
        int_counter++;
        Timer1OFF();        // Stop TMR1 timer
        LoadTMR1(TMR1_LOAD_DATA);        //reload tmr1
        Timer1ON();         /* Then start TMR1 again. */
        PIR1bits.TMR1IF = 0;    
    }
    else
    {
        PORTBbits.RB3 = 0;  // Signal the unhandled interrupt.
        /* Unhandled interrupts */
    }

#endif

}
