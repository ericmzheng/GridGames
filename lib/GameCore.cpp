#include "GameCore.h"

GameCore::GameCore()
{
}

void GameCore::setGrid(Grid *grid)
{
    m_pGrid = grid;
}

GridElement *GameCore::createGridElement(const unsigned row, const unsigned col)
{
    return new GridElement(row, col);
}

DECLARE_MOUSE_EVENT_PROCESSOR(processEnterWindow)
DECLARE_MOUSE_EVENT_PROCESSOR(processLeaveWindow)
DECLARE_MOUSE_EVENT_PROCESSOR(processLeftDown)
DECLARE_MOUSE_EVENT_PROCESSOR(processMiddleDown)
DECLARE_MOUSE_EVENT_PROCESSOR(processRightDown)
DECLARE_MOUSE_EVENT_PROCESSOR(processLeftUp)
DECLARE_MOUSE_EVENT_PROCESSOR(processMiddleUp)
DECLARE_MOUSE_EVENT_PROCESSOR(processRightUp)
DECLARE_MOUSE_EVENT_PROCESSOR(processLeftDoubleClick)
DECLARE_MOUSE_EVENT_PROCESSOR(processMiddleDoubleClick)
DECLARE_MOUSE_EVENT_PROCESSOR(processRightDoubleClick)
DECLARE_MOUSE_EVENT_PROCESSOR(processMouseWheel)
DECLARE_MOUSE_EVENT_PROCESSOR(processMouseMove)

void GameCore::processKeyDown(const wxKeyEvent &event) {}
void GameCore::processKeyUp(const wxKeyEvent &event) {}

