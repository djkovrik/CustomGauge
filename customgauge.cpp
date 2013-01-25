/*************************************************
 * Name:      customgauge.cpp
 * Purpose:   CustomGauge class implementation
 * Author:    DJ_Kovrik (djkovrik at gmail.com)
 * Created:   2013-01-23
 * Source:    https://github.com/djkovrik
 *************************************************/

#include "customgauge.h"

void CustomGauge::SetValue(int pos) {

    if (GetValue() != pos)
        m_position = pos;
}

void CustomGauge::SetRange(int range) {

    if (GetRange() != range)
        m_range = range;
}

void CustomGauge::InitialInit() {

    // White backfround by default
    m_backFill.SetColour("WHITE");

    // Light grey gauge bar by default
    m_foreFill.SetColour("LIGHT GREY");

    // Solid brushes by default
    m_backFill.SetStyle(wxBRUSHSTYLE_SOLID);
    m_foreFill.SetStyle(wxBRUSHSTYLE_SOLID);

    // Default gauge border: black 1px solid
    m_pen.SetColour("BLACK");
    m_pen.SetWidth(1);
    m_pen.SetStyle(wxPENSTYLE_SOLID);

    // Set default font
    m_font = *wxNORMAL_FONT;
    m_font_col = *wxBLACK;

    // Binds redraw on resize event
    m_panel->Bind(wxEVT_SIZE, &CustomGauge::OnPanelResize, this);
}

void CustomGauge::RedrawNow() {

    wxClientDC m_canvas(m_panel);

    m_canvas.Clear();

    // Set default font
    m_canvas.SetFont(m_font);
    m_canvas.SetTextForeground(m_font_col);


    // Draw gauge background

    m_canvas.SetBrush(m_backFill);
    m_canvas.SetPen(m_pen);

    wxRect FillRect(0, 0, m_canvas.GetSize().GetWidth(), m_canvas.GetSize().GetHeight());
    m_canvas.DrawRectangle(FillRect);

    // Draw gauge bar

    m_canvas.SetBrush(m_foreFill);

    wxCoord w = m_canvas.GetSize().GetWidth() * GetValue() / GetRange();
    wxCoord h = m_canvas.GetSize().GetHeight();

    wxRect rectToDraw(0, 0, w, h);
    m_canvas.DrawRectangle(rectToDraw);

    if (m_label) {

        const wxFont currentFont = m_canvas.GetFont();
        int fw = currentFont.GetPointSize();

        m_canvas.DrawText(wxString::Format("%u%", GetValue() * 100 / GetRange() ),
                          m_canvas.GetSize().GetWidth()  / 2 - fw / 0.75,
                          m_canvas.GetSize().GetHeight() / 2 - fw / 1.25 );
    }

}

void CustomGauge::OnPanelResize(wxSizeEvent& event) {
    // Redraw custom gauge (panel) on resize
    RedrawNow();
    event.Skip();
}

CustomGauge::~CustomGauge() {
    // UnBinds redraw method
    m_panel->Unbind(wxEVT_SIZE, &CustomGauge::OnPanelResize, this);
}
