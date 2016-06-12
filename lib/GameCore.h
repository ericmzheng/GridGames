#ifndef _GAME_CORE_H_
#define _GAME_CORE_H_

#include <wx/wx.h>

#define DECLARE_MOUSE_EVENT_PROCESSOR(F) \
    void GameCore::F(const wxMouseEvent &event, unsigned row, unsigned col) {}

class Grid;
class GridElement;

class GameCore
{
public:
    GameCore();
    void setGrid(Grid *grid);
    virtual GridElement *createGridElement(const unsigned row, const unsigned col);
    virtual void initialize() = 0;

    virtual void processEnterWindow(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processLeaveWindow(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processLeftDown(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processMiddleDown(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processRightDown(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processLeftUp(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processMiddleUp(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processRightUp(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processLeftDoubleClick(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processMiddleDoubleClick(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processRightDoubleClick(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processMouseWheel(const wxMouseEvent &event, unsigned row, unsigned col);
    virtual void processMouseMove(const wxMouseEvent &event, unsigned row, unsigned col);

    virtual void processKeyDown(const wxKeyEvent &event);
    virtual void processKeyUp(const wxKeyEvent &event);
protected:
    Grid *m_pGrid;
};

#include "Grid.h"

#endif // _GAME_CORE_H_
