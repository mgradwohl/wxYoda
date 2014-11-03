/***************************************************************
 * Name:      wxYodaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Matt Gradwohl (mattgr@msn.com)
 * Created:   2014-10-18
 * Copyright: Matt Gradwohl (uppercutwoodworks.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxYodaApp.h"
#include "wxYodaMain.h"

IMPLEMENT_APP(wxYodaApp);

bool wxYodaApp::OnInit()
{
    wxYodaFrame* frame = new wxYodaFrame(0L);
    
    frame->Show();
    
    return true;
}
