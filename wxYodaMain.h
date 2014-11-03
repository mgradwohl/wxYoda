/***************************************************************
 * Name:      wxYodaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Matt Gradwohl (mattgr@msn.com)
 * Created:   2014-10-18
 * Copyright: Matt Gradwohl (uppercutwoodworks.com)
 * License:
 **************************************************************/

#ifndef WXYODAMAIN_H
#define WXYODAMAIN_H

#include <string>
using namespace std;

#include "wxYodaApp.h"

#include "GUIFrame.h"

class wxYodaFrame: public GUIFrame
{
    public:
        wxYodaFrame(wxFrame *frame);
        ~wxYodaFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void GoDoIt(wxCommandEvent& event);
        bool Yoda(const string szIn, string& szOut);

};

#endif // WXYODAMAIN_H
