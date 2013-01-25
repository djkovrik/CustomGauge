/*************************************************
 * Name:      customgauge.h
 * Purpose:   CustomGauge class definition
 * Author:    DJ_Kovrik (djkovrik at gmail.com)
 * Created:   2013-01-23
 * Source:    https://github.com/djkovrik
 *************************************************/

#ifndef CUSTOMGAUGE_H_INCLUDED
#define CUSTOMGAUGE_H_INCLUDED

#include <wx/panel.h>
#include <wx/dcclient.h>

class wxBrush;
class wxPen;
class wxSizeEvent;
class wxColour;
class wxFont;

class CustomGauge {
public:
    CustomGauge() :
        m_panel(NULL), m_position(0), m_range(100), m_label(true) { InitialInit(); }

    CustomGauge(wxPanel* parent, int pos = 0, int range = 100, bool f = false) :
        m_panel(parent), m_position(pos), m_range(range), m_label(f) { InitialInit(); }

    ~CustomGauge();

    void RedrawNow();

    // Setters & Getters

    int GetValue() const { return m_position;   }
    int GetRange() const { return m_range;      }

    void SetValue(int pos);
    void SetRange(int range);

    // Settings

    void ShowPercents(bool flag)                    { m_label = flag;               }
    void SetBackgroundBrush (const wxColour& col)   { m_backFill.SetColour(col);    }
    void SetForegroundBrush (const wxColour& col)   { m_foreFill.SetColour(col);    }
    void SetPen (const wxPen& pen)                  { m_pen = pen;                  }
    void SetFont (const wxFont &font)               { m_font = font;                }
    void SetTextForeground (const wxColour &colour) { m_font_col = colour;          }


private:
    wxPanel*    m_panel;    // Panel pointer (canvas)

    int         m_position; // Current position
    int         m_range;    // Overall range

    bool        m_label;    // If true, then add percents value label

    wxBrush     m_backFill; // Gauge background brush
    wxBrush     m_foreFill; // Gauge bar brush
    wxPen       m_pen;      // For gauge border drawing

    wxFont      m_font;     // Text font
    wxColour    m_font_col; // Text colour

    // Brushes and pen init
    void InitialInit();
    // Resize event handler
    void OnPanelResize(wxSizeEvent& event);

};

#endif // CUSTOMGAUGE_H_INCLUDED

/**************************************************************
 * SetBackgroundBrush, SetForegroundBrush,
 * SetPenColour and SetTextForeground methods can get
 * RGB values or colour names.
 *
 * Example:
 *  my_gauge->SetForegroundBrush("RED");
 *  my_gauge->SetBackgroundBrush(wxColour(0,255,0));
 *
 * Available colour names:
 * http://docs.wxwidgets.org/trunk/classwx_colour_database.html
 *
 *************************************************************/
