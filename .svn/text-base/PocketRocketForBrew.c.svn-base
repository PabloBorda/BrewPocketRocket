/*===========================================================================

FILE: PocketRocketForBrew.c
===========================================================================*/


/*===============================================================================
INCLUDES AND VARIABLE DEFINITIONS
=============================================================================== */
#include "AEEModGen.h"          // Module interface definitions
#include "AEEAppGen.h"          // Applet interface definitions
#include "AEEShell.h"           // Shell interface definitions

#include "AEEFile.h"			// File interface definitions
#include "AEEDB.h"				// Database interface definitions
#include "AEENet.h"				// Socket interface definitions
#include "AEESound.h"			// Sound Interface definitions
#include "AEETapi.h"			// TAPI Interface definitions
#include "config.h"
#include "AEEStdLib.h"
#include <stdio.h>







//#include "XOsApplication.h"

#include "PocketRocketForBrew.bid"

/*-------------------------------------------------------------------
Applet structure. All variables in here are reference via "pMe->"
-------------------------------------------------------------------*/
// create an applet structure that's passed around. All variables in
// here will be able to be referenced as static.
typedef struct _PocketRocketForBrew {
	AEEApplet      a ;	       // First element of this structure must be AEEApplet
    AEEDeviceInfo  DeviceInfo; // always have access to the hardware device information

    // add your own variables here...



} PocketRocketForBrew;

/*-------------------------------------------------------------------
Function Prototypes
-------------------------------------------------------------------*/
static  boolean PocketRocketForBrew_HandleEvent(PocketRocketForBrew* pMe, 
                                                   AEEEvent eCode, uint16 wParam, 
                                                   uint32 dwParam);
boolean PocketRocketForBrew_InitAppData(PocketRocketForBrew* pMe);
void    PocketRocketForBrew_FreeAppData(PocketRocketForBrew* pMe);

/*===============================================================================
FUNCTION DEFINITIONS
=============================================================================== */

/*===========================================================================
FUNCTION: AEEClsCreateInstance

DESCRIPTION
	This function is invoked while the app is being loaded. All Modules must provide this 
	function. Ensure to retain the same name and parameters for this function.
	In here, the module must verify the ClassID and then invoke the AEEApplet_New() function
	that has been provided in AEEAppGen.c. 

   After invoking AEEApplet_New(), this function can do app specific initialization. In this
   example, a generic structure is provided so that app developers need not change app specific
   initialization section every time except for a call to IDisplay_InitAppData(). 
   This is done as follows: InitAppData() is called to initialize AppletData 
   instance. It is app developers responsibility to fill-in app data initialization 
   code of InitAppData(). App developer is also responsible to release memory 
   allocated for data contained in AppletData -- this can be done in 
   IDisplay_FreeAppData().

PROTOTYPE:
   int AEEClsCreateInstance(AEECLSID ClsId,IShell * pIShell,IModule * po,void ** ppObj)

PARAMETERS:
	clsID: [in]: Specifies the ClassID of the applet which is being loaded

	pIShell: [in]: Contains pointer to the IShell object. 

	pIModule: pin]: Contains pointer to the IModule object to the current module to which
	this app belongs

	ppObj: [out]: On return, *ppObj must point to a valid IApplet structure. Allocation
	of memory for this structure and initializing the base data members is done by AEEApplet_New().

DEPENDENCIES
  none

RETURN VALUE
  AEE_SUCCESS: If the app needs to be loaded and if AEEApplet_New() invocation was
     successful
  EFAILED: If the app does not need to be loaded or if errors occurred in 
     AEEApplet_New(). If this function returns FALSE, the app will not be loaded.

SIDE EFFECTS
  none
===========================================================================*/
int AEEClsCreateInstance(AEECLSID ClsId, IShell *pIShell, IModule *po, void **ppObj)
{
	*ppObj = NULL;

	if( ClsId == AEECLSID_POCKETROCKETFORBREW )
	{
		// Create the applet and make room for the applet structure
		if( AEEApplet_New(sizeof(PocketRocketForBrew),
                          ClsId,
                          pIShell,
                          po,
                          (IApplet**)ppObj,
                          (AEEHANDLER)PocketRocketForBrew_HandleEvent,
                          (PFNFREEAPPDATA)PocketRocketForBrew_FreeAppData) ) // the FreeAppData function is called after sending EVT_APP_STOP to the HandleEvent function
                          
		{
			//Initialize applet data, this is called before sending EVT_APP_START
            // to the HandleEvent function
			if(PocketRocketForBrew_InitAppData((PocketRocketForBrew*)*ppObj))
			{
				//Data initialized successfully
				return(AEE_SUCCESS);
			}
			else
			{
				//Release the applet. This will free the memory allocated for the applet when
				// AEEApplet_New was called.
				IAPPLET_Release((IApplet*)*ppObj);
				return EFAILED;
			}

        } // end AEEApplet_New

    }

	return(EFAILED);
}


/*===========================================================================
FUNCTION SampleAppWizard_HandleEvent

DESCRIPTION
	This is the EventHandler for this app. All events to this app are handled in this
	function. All APPs must supply an Event Handler.

PROTOTYPE:
	boolean SampleAppWizard_HandleEvent(IApplet * pi, AEEEvent eCode, uint16 wParam, uint32 dwParam)

PARAMETERS:
	pi: Pointer to the AEEApplet structure. This structure contains information specific
	to this applet. It was initialized during the AEEClsCreateInstance() function.

	ecode: Specifies the Event sent to this applet

   wParam, dwParam: Event specific data.

DEPENDENCIES
  none

RETURN VALUE
  TRUE: If the app has processed the event
  FALSE: If the app did not process the event

SIDE EFFECTS
  none
===========================================================================*/
static boolean PocketRocketForBrew_HandleEvent(PocketRocketForBrew* pMe, AEEEvent eCode, uint16 wParam, uint32 dwParam)
{  
      AECHAR szBuf[] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
	  AECHAR down[] = {'Y','o','u',' ','P','u','s','h','e','d',' ','d','o','w','n','\0'};
	  AECHAR error[] = {'I','m','a','g','e',' ','l','o','a','d',' ','f','a','i','l','e','d','\0'};
      boolean handled = FALSE;
	  AEEApplet * display = (AEEApplet *)pMe;
	  IImage *samplePic = NULL;
	  

    switch (eCode) 
	{
        // App is told it is starting up
        case EVT_APP_START:
			// Clear the display.
			IDISPLAY_ClearScreen( display->m_pIDisplay);

			//IDISPLAY_DrawRect(display->m_pIDisplay,
            // Display string on the screen
            IDISPLAY_DrawText( display->m_pIDisplay, // What
                     AEE_FONT_BOLD,                  // What font
                     szBuf,                          // How many chars
                     -1, 0, 0, 0,                    // Where & clip
                     IDF_ALIGN_CENTER | IDF_ALIGN_MIDDLE );
            // Redraw the display to show the drawn text
            IDISPLAY_Update (display->m_pIDisplay);
			//IDISPLAY_DrawFrame


		    // Add your code here...

            return(TRUE);

	
        // App is told it is exiting
        case EVT_APP_STOP:
            // Add your code here...

      		return(TRUE);


        // App is being suspended 
        case EVT_APP_SUSPEND:
		    // Add your code here...

      		return(TRUE);


        // App is being resumed
        case EVT_APP_RESUME:
		    // Add your code here...

      		return(TRUE);


        // An SMS message has arrived for this app. Message is in the dwParam above as (char *)
        // sender simply uses this format "//BREW:ClassId:Message", example //BREW:0x00000001:Hello World
        case EVT_APP_MESSAGE:
		    // Add your code here...

      		return(TRUE);

        // A key was pressed. Look at the wParam above to see which key was pressed. The key
        // codes are in AEEVCodes.h. Example "AVK_1" means that the "1" key was pressed.
        case EVT_KEY:

			switch (wParam){
   	          case AVK_DOWN:
                /*
			    IDISPLAY_ClearScreen( display->m_pIDisplay );
			    IDISPLAY_DrawText (display->m_pIDisplay, AEE_FONT_BOLD, down, -1,0,0,0, IDF_ALIGN_CENTER | IDF_ALIGN_MIDDLE);
			    IDISPLAY_Update(display->m_pIDisplay);
			    handled = TRUE;
				*/
				//IImage *samplePic =  ISHELL_LoadResImage(display->m_pIShell,".\\pics\\xosphere.JPG",5001);				  
				  samplePic = ISHELL_LoadImage(display->m_pIShell,".\\pics\\xosphere.bmp");
				  while (!samplePic);
				
				if (!samplePic) {
				   IDISPLAY_ClearScreen(display->m_pIDisplay);

			       //IDISPLAY_DrawRect(display->m_pIDisplay,
                   // Display string on the screen
                   IDISPLAY_DrawText( display->m_pIDisplay, // What
                     AEE_FONT_BOLD,                  // What font
                     error,                          // How many chars
                     -1, 0, 0, 0,                    // Where & clip
                     IDF_ALIGN_CENTER | IDF_ALIGN_MIDDLE );
                   // Redraw the display to show the drawn text
                   IDISPLAY_Update (display->m_pIDisplay);
				} else {
				  IIMAGE_Draw(samplePic, 0,0);
				  IDISPLAY_Update(display->m_pIDisplay);
				}

			    return(TRUE);
             
			 

			}

		    // Add your code here...

      		return(TRUE);


        // If nothing fits up to this poNumber then we'll just break out
        default:
            break;
   }

   return FALSE;
}








// this function is called when your application is starting up
boolean PocketRocketForBrew_InitAppData(PocketRocketForBrew* pMe)
{
    AECHAR os[] = {'B','r','e','w','\0'};
	char resx[5];
	char resy[5];
	AECHAR wresx[5];
	AECHAR wresy[5];
	AECHAR url[512];
	char curl[512];
	AECHAR fchunk[] = {'?','O','S','=','B','r','e','w','&','H','E','I','G','H','T','=','\0'};
	AECHAR schunk[] = {'&','W','I','D','T','H','=','\0'};
	AECHAR tchunk[] = {'&','I','D','=','1','\0'};
	// Get the device information for this handset.
    // Reference all the data by looking at the pMe->DeviceInfo structure
    // Check the API reference guide for all the handy device info you can get
    pMe->DeviceInfo.wStructSize = sizeof(pMe->DeviceInfo);
	ISHELL_GetDeviceInfo(pMe->a.m_pIShell,&pMe->DeviceInfo);
//	std::string a;
	
	STRCPY(url,XID_URL);
   // str
	
	itoa((int)pMe->DeviceInfo.cyScreen,resx,10);
	itoa((int)pMe->DeviceInfo.cxScreen,resy,10);
	STRTOWSTR(wresx,resx,strlen(resx));
	STRTOWSTR(wresy,resy,strlen(resy));
	//strcp
	STRCAT(url,fchunk);
	STRCAT(url,wresy);
	STRCAT(url,schunk);
	STRCAT(url,wresx);
	STRCAT(url,tchunk);

	WSTRTOSTR(curl,url,strlen(curl));
	printf(url);
	
	//strcat(


	

    // Insert your code here for initializing or allocating resources...

	//XOsApplication *xosApplication = new XOsApplication("Testing");
	
	
	





    // if there have been no failures up to this point then return success
    return TRUE;
}

// this function is called when your application is exiting
void PocketRocketForBrew_FreeAppData(PocketRocketForBrew* pMe)
{
    // insert your code here for freeing any resources you have allocated...

    // example to use for releasing each interface:
    // if ( pMe->pIMenuCtl != NULL )         // check for NULL first
    // {
    //    IMENUCTL_Release(pMe->pIMenuCtl)   // release the interface
    //    pMe->pIMenuCtl = NULL;             // set to NULL so no problems trying to free later
    // }
    //

}
