/***************************************************************
 * Name:      MyGaugeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DJ_Kovrk (djkovrik at gmail com)
 * Created:   2013-01-24
 * Copyright: DJ_Kovrk ()
 * License:
 **************************************************************/

#include "MyGaugeMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MyGaugeFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions

//(*IdInit(MyGaugeFrame)
const long MyGaugeFrame::ID_GAUGE1 = wxNewId();
const long MyGaugeFrame::ID_PANEL2 = wxNewId();
const long MyGaugeFrame::ID_PANEL3 = wxNewId();
const long MyGaugeFrame::ID_SLIDER1 = wxNewId();
const long MyGaugeFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MyGaugeFrame,wxFrame)
    //(*EventTable(MyGaugeFrame)
    //*)
END_EVENT_TABLE()

MyGaugeFrame::MyGaugeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MyGaugeFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxBoxSizer* BoxSizerGui;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* TopSizer;

    Create(parent, id, _("Custom gauge sample:"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    TopSizer = new wxBoxSizer(wxHORIZONTAL);
    MainPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizerGui = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, MainPanel, _("Native:"));
    Gauge1 = new wxGauge(MainPanel, ID_GAUGE1, 100, wxDefaultPosition, wxSize(329,28), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    StaticBoxSizer1->Add(Gauge1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerGui->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, MainPanel, _("Custom, sample #1:"));
    PanelForGauge1 = new wxPanel(MainPanel, ID_PANEL2, wxDefaultPosition, wxSize(329,26), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer2->Add(PanelForGauge1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerGui->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, MainPanel, _("Custom, sample #2:"));
    PanelForGauge2 = new wxPanel(MainPanel, ID_PANEL3, wxDefaultPosition, wxSize(329,36), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBoxSizer3->Add(PanelForGauge2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerGui->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Slider1 = new wxSlider(MainPanel, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
    BoxSizer1->Add(Slider1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizerGui->Add(BoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    MainPanel->SetSizer(BoxSizerGui);
    BoxSizerGui->Fit(MainPanel);
    BoxSizerGui->SetSizeHints(MainPanel);
    TopSizer->Add(MainPanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(TopSizer);
    TopSizer->Fit(this);
    TopSizer->SetSizeHints(this);
    Center();

    Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MyGaugeFrame::OnSlider1CmdSliderUpdated);
    //*)

    // CustomGauge1 - default appearance
    CustomGauge1 = new CustomGauge(PanelForGauge1);

    // CustomGauge2

    CustomGauge2 = new CustomGauge(PanelForGauge2);

    // Show percents label
    CustomGauge2->ShowPercents(true);

    // Yellow background, green gauge bar
    CustomGauge2->SetBackgroundBrush("YELLOW");
    CustomGauge2->SetForegroundBrush("GREEN");

    // Red 3px border
    wxPen p("RED", 3);
    CustomGauge2->SetPen(p);

    // Font for label: 15px size, Teletype family, italic bold
    wxFont f(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    CustomGauge2->SetFont(f);

    // Label colour
    CustomGauge2->SetTextForeground("BLUE");

}

MyGaugeFrame::~MyGaugeFrame()
{
    //(*Destroy(MyGaugeFrame)
    //*)

    delete CustomGauge1;
    delete CustomGauge2;
}


void MyGaugeFrame::OnSlider1CmdSliderUpdated(wxScrollEvent& event)
{
    Gauge1->SetValue( Slider1->GetValue() );

    CustomGauge1->SetValue( Slider1->GetValue() );
    CustomGauge2->SetValue( Slider1->GetValue() );

    CustomGauge1->RedrawNow();
    CustomGauge2->RedrawNow();
}
