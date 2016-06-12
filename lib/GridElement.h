#ifndef _GRID_ELEMENT_H_
#define _GRID_ELEMENT_H_

#include <vector>
#include <wx/wx.h>

class GridElement
{
public:
    GridElement(unsigned row, unsigned col);
    GridElement(const wxColour &color, unsigned row, unsigned col);
    wxColour getColor() const;
    void setColor(const wxColour &color);
    void unsetColor();
    void unsetColor(const wxColour &color);
private:
    std::vector<wxColour> m_vColorStack;
    wxColour m_defaultColor;
    unsigned m_row;
    unsigned m_col;
};

#endif // _GRID_ELEMENT_H_

