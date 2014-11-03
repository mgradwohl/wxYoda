/***************************************************************
 * Name:      wxYodaMain.cpp
 * Purpose:   Code for Application Frame
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

#include <list>
#include <string>

#include "wxYodaMain.h"

using namespace std;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxYodaFrame::wxYodaFrame(wxFrame *frame)
    : GUIFrame(frame)
{
}

wxYodaFrame::~wxYodaFrame()
{
}

void wxYodaFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxYodaFrame::GoDoIt(wxCommandEvent& evt)
{
    wxString str = m_textCtrl->GetLineText(0);

    string szIn(str.ToAscii());
    string szOut;

    Yoda(szIn, szOut);

    wxString strLabel (szOut.c_str(), wxConvUTF8);
    m_staticText->SetLabel(strLabel);
}

bool wxYodaFrame::Yoda(const string szIn, string& szOut)
{
    if (szIn.length() < 1)
    {
        return false;
    }

    if (szIn.length() == 1)
    {
        szOut = szIn;
        return true;
    }

    // the input is valid and at least two characters
    size_t i = 0;
    size_t w = 0;
    bool fWordFirst = true;

    list<string> words;
    list<string> punct;
    string word;

    if (!isalnum(szIn[i]))
    {
        fWordFirst = false;
    }

    while (i < szIn.length())
    {
        if (isalnum(szIn[i]))
        {
            // it's a word made of letters and numbers find the end of it
            while (isalnum(szIn[w]) && w < szIn.length())
            {
                ++w;
            }
            word = szIn.substr(i, w-i);
            words.push_back(word);
        }
        else
        {
            // it's a word made of punctuation or spaces find the end of it
            while (!isalnum(szIn[w]) && w < szIn.length())
            {
                ++w;
            }
            word = szIn.substr(i, w-i);
            punct.push_back(word);
        }
        i = w;
    }// while parse

    szOut.clear();
    if (!fWordFirst)
    {
        word = punct.front();
        szOut += word;
        punct.pop_front();
    }

    while ( !words.empty() && !punct.empty() )
    {
        word = words.back();
        szOut += word;
        words.pop_back();

        word = punct.front();
        szOut += word;
        punct.pop_front();
    }

    if (!words.empty())
    {
        word = words.back();
        szOut += word;
        words.pop_back();
    }

    return true;
}
