/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/

#include <plib.h>           /* Include to use PIC32 peripheral libraries      */
#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */

#include "system.h"         /* System funct/params, like osc/periph config    */
#include "user.h"           /* User funct/params, such as InitApp             */
#include "graphics/Gol.h"
#include "graphics/DisplayDriver.h"
#include "graphics/StaticText.h"

/////////////////////////////////////////////////////////////////////////////
//                            FONTS USED
/////////////////////////////////////////////////////////////////////////////
//extern const FONT_FLASH     Gentium_16;

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

//GOL_SCHEME      *demoScheme;                // alternative style scheme
STATICTEXT      *STERM;         // Static text for Start terminal

/////////////////////////////////////////////////////////////////////////////
// Function: WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg)
// Input: objMsg - translated message for the object,
//        pObj - pointer to the object,
//        pMsg - pointer to the non-translated, raw GOL message
// Output: if the function returns non-zero the message will be processed by default
// Overview: it's a user defined function. GOLMsg() function calls it each
//           time the valid message for the object received
/////////////////////////////////////////////////////////////////////////////

WORD            GOLMsgCallback(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
{
    return (1);
};
/////////////////////////////////////////////////////////////////////////////
// Function: WORD GOLDrawCallback()
// Output: if the function returns non-zero the draw control will be passed to GOL
// Overview: it's a user defined function. GOLDraw() function calls it each
//           time when GOL objects drawing is completed. User drawing should be done here.
//           GOL will not change color, line type and clipping region settings while

//           this function returns zero.
/////////////////////////////////////////////////////////////////////////////
WORD GOLDrawCallback(void)
{
    return (1);
}

/* i.e. uint32_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int32_t main(void)
{

    GOL_MSG msg;                    // GOL message structure to interact with GOL

#ifndef PIC32_STARTER_KIT
    /*The JTAG is on by default on POR.  A PIC32 Starter Kit uses the JTAG, but
    for other debug tool use, like ICD 3 and Real ICE, the JTAG should be off
    to free up the JTAG I/O */
    DDPCONbits.JTAGEN = 0;
#endif

    /*Refer to the C32 peripheral library compiled help file for more
    information on the SYTEMConfig function.
    
    This function sets the PB divider, the Flash Wait States, and the DRM
    /wait states to the optimum value.  It also enables the cacheability for
    the K0 segment.  It could has side effects of possibly alter the pre-fetch
    buffer and cache.  It sets the RAM wait states to 0.  Other than
    the SYS_FREQ, this takes these parameters.  The top 3 may be '|'ed
    together:
    
    SYS_CFG_WAIT_STATES (configures flash wait states from system clock)
    SYS_CFG_PB_BUS (configures the PB bus from the system clock)
    SYS_CFG_PCACHE (configures the pCache if used)
    SYS_CFG_ALL (configures the flash wait states, PB bus, and pCache)*/

    /* TODO Add user clock/system configuration code if appropriate.  */
    SYSTEMConfig(SYS_FREQ, SYS_CFG_ALL); 

    /* Initialize I/O and Peripherals for application */
    InitApp();

    DisplayBacklightOn();

    SetColor(BLACK);
    ClearDevice();

    if ((STERM = (void*)InitStartTerminal()) != NULL)
    {
    } else 
    {   /* We marked the start terminau unsuccesfully with blinking the display
         backlight LED. */
        while (1)
        {
            DelayMs(500);
            DisplayBacklightOn();
            DelayMs(500);
            DisplayBacklightOff();
        };
    }

//    SPITest();

//#if defined WANT_GOL_INIT
//#endif

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    while(1)
    {
        if(GOLDraw())
        {                           // Draw GOL object
//            TouchGetMsg(&msg);      // Get message from touch screen
            if (msg.uiEvent == EVENT_INVALID)
            {
//                IOGetMsg(&msg);         // Get IO Port states.
            }
            GOLMsg(&msg);           // Process message
        }
    }
}
