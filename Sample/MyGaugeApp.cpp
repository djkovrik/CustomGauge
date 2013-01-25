/***************************************************************
 * Name:      MyGaugeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DJ_Kovrk (djkovrik at gmail com)
 * Created:   2013-01-24
 * Copyright: DJ_Kovrk ()
 * License:
 **************************************************************/

#include "MyGaugeApp.h"

//(*AppHeaders
#include "MyGaugeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MyGaugeApp)

bool MyGaugeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MyGaugeFrame* Frame = new MyGaugeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
