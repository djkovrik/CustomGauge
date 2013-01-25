/***************************************************************
 * Name:      MyGaugeMain.h
 * Purpose:   Defines Application Frame
 * Author:    DJ_Kovrk (djkovrik at gmail com)
 * Created:   2013-01-24
 * Copyright: DJ_Kovrk ()
 * License:
 **************************************************************/

#ifndef MYGAUGEMAIN_H
#define MYGAUGEMAIN_H

//(*Headers(MyGaugeFrame)
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/gauge.h>
//*)

#include "../customgauge.h"

class MyGaugeFrame: public wxFrame
{
    public:

        MyGaugeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MyGaugeFrame();

    private:

        //(*Handlers(MyGaugeFrame)
        void OnSlider1CmdSliderUpdated(wxScrollEvent& event);
        //*)

        //(*Identifiers(MyGaugeFrame)
        static const long ID_GAUGE1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_SLIDER1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(MyGaugeFrame)
        wxSlider* Slider1;
        wxGauge* Gauge1;
        wxPanel* PanelForGauge1;
        wxPanel* MainPanel;
        wxPanel* PanelForGauge2;
        //*)

        CustomGauge* CustomGauge1;
        CustomGauge* CustomGauge2;

        DECLARE_EVENT_TABLE()
};

#endif // MYGAUGEMAIN_H
