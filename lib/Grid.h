#ifndef _GRID_H_
#define _GRID_H_

#include <vector>
#include <wx/wx.h>
#include "GridElement.h"

#define MOUSE_EVENT_HANDLER(P)                              \
    if ((!m_rows) || (!m_cols))                             \
        return;                                             \
                                                            \
    wxPoint mouse = event.GetPosition();                    \
    wxSize  size  = GetSize();                              \
                                                            \
    if ((!size.GetWidth()) || (!size.GetHeight()))          \
        return;                                             \
                                                            \
    unsigned row = mouse.y / (size.GetWidth() / m_cols);    \
    unsigned col = mouse.x / (size.GetHeight() / m_rows);   \
                                                            \
    m_pCore->P(event, row, col);

#define DECLARE_MOUSE_EVENT_HANDLER(F,P)                    \
    void Grid::F(wxMouseEvent &event)                       \
    {                                                       \
        MOUSE_EVENT_HANDLER(P);                             \
    }

class GameCore;

class Grid : public wxPanel
{
public:
    Grid(wxFrame *parent, GameCore *core);
    void addRow();
    void addCol();
    void setColor(const wxColour &color, const unsigned row, const unsigned col);
    void unsetColor(const unsigned row, const unsigned col);
    void unsetColor(const wxColour &color, const unsigned row, const unsigned col);

    GridElement *getElement(const unsigned row, const unsigned col) const;
protected:
    void onEnterWindow(wxMouseEvent &event);
    void onLeaveWindow(wxMouseEvent &event);
    void onLeftDown(wxMouseEvent &event);
    void onMiddleDown(wxMouseEvent &event);
    void onRightDown(wxMouseEvent &event);
    void onLeftUp(wxMouseEvent &event);
    void onMiddleUp(wxMouseEvent &event);
    void onRightUp(wxMouseEvent &event);
    void onLeftDoubleClick(wxMouseEvent &event);
    void onMiddleDoubleClick(wxMouseEvent &event);
    void onRightDoubleClick(wxMouseEvent &event);
    void onMouseWheel(wxMouseEvent &event);
    void onMouseMove(wxMouseEvent &event);

    void onKeyDown(wxKeyEvent &event);
    void onKeyUp(wxKeyEvent &event);

    virtual void onPaint(wxPaintEvent &event);
    virtual void paint(const unsigned row, const unsigned col);

    GameCore *m_pCore;
    unsigned m_rows;
    unsigned m_cols;
    std::vector<std::vector<GridElement *>> m_vGridElements;
};

#include "GameCore.h"

#endif // _GRID_H_

