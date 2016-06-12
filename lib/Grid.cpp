#include "Grid.h"

Grid::Grid(wxFrame *parent, GameCore *core)
    : wxPanel(parent), m_pCore(core), m_rows(0), m_cols(0)
{
    Connect(wxEVT_ENTER_WINDOW,     wxMouseEventHandler(Grid::onEnterWindow));
    Connect(wxEVT_LEAVE_WINDOW,     wxMouseEventHandler(Grid::onLeaveWindow));
    Connect(wxEVT_LEFT_DOWN,        wxMouseEventHandler(Grid::onLeftDown));
    Connect(wxEVT_MIDDLE_DOWN,      wxMouseEventHandler(Grid::onMiddleDown));
    Connect(wxEVT_RIGHT_DOWN,       wxMouseEventHandler(Grid::onRightDown));
    Connect(wxEVT_LEFT_UP,          wxMouseEventHandler(Grid::onLeftUp));
    Connect(wxEVT_MIDDLE_UP,        wxMouseEventHandler(Grid::onMiddleUp));
    Connect(wxEVT_RIGHT_UP,         wxMouseEventHandler(Grid::onRightUp));
    Connect(wxEVT_LEFT_DCLICK,      wxMouseEventHandler(Grid::onLeftDoubleClick));
    Connect(wxEVT_MIDDLE_DCLICK,    wxMouseEventHandler(Grid::onMiddleDoubleClick));
    Connect(wxEVT_RIGHT_DCLICK,     wxMouseEventHandler(Grid::onRightDoubleClick));
    Connect(wxEVT_MOUSEWHEEL,       wxMouseEventHandler(Grid::onMouseWheel));
    Connect(wxEVT_MOTION,           wxMouseEventHandler(Grid::onMouseMove));

#ifdef GRAB_KEYS
    Connect(wxEVT_KEY_DOWN,         wxKeyEventHandler(Grid::onKeyDown));
    Connect(wxEVT_KEY_UP,           wxKeyEventHandler(Grid::onKeyUp));
#endif

    Connect(wxEVT_PAINT,            wxPaintEventHandler(Grid::onPaint));
}

void Grid::addRow()
{
    m_vGridElements.resize(m_rows + 1);
    for (unsigned j = 0; j < m_cols; j++)
        m_vGridElements[m_rows][j] = m_pCore->createGridElement(m_rows, j);
    m_rows++;
}

void Grid::addCol()
{
    for (unsigned i = 0; i < m_rows; i++)
    {
        m_vGridElements[i].resize(m_cols + 1);
        m_vGridElements[i][m_cols] = m_pCore->createGridElement(i, m_cols);
    }
    m_cols++;
}

void Grid::setColor(const wxColour &color, const unsigned row, const unsigned col)
{
    GridElement *element = getElement(row, col);
    if (element)
        element->setColor(color);
}

void Grid::unsetColor(const unsigned row, const unsigned col)
{
    GridElement *element = getElement(row, col);
    if (element)
        element->unsetColor();
}

void Grid::unsetColor(const wxColour &color, const unsigned row, const unsigned col)
{
    GridElement *element = getElement(row, col);
    if (element)
        element->unsetColor(color);
}

GridElement *Grid::getElement(const unsigned row, const unsigned col) const
{
    if (row < m_vGridElements.size() && col < m_vGridElements[row].size())
        return m_vGridElements[row][col];
    return NULL;
}

DECLARE_MOUSE_EVENT_HANDLER(onEnterWindow,          processEnterWindow      )
DECLARE_MOUSE_EVENT_HANDLER(onLeaveWindow,          processLeaveWindow      )
DECLARE_MOUSE_EVENT_HANDLER(onLeftDown,             processLeftDown         )
DECLARE_MOUSE_EVENT_HANDLER(onMiddleDown,           processMiddleDown       )
DECLARE_MOUSE_EVENT_HANDLER(onRightDown,            processRightDown        )
DECLARE_MOUSE_EVENT_HANDLER(onLeftUp,               processLeftUp           )
DECLARE_MOUSE_EVENT_HANDLER(onMiddleUp,             processMiddleUp         )
DECLARE_MOUSE_EVENT_HANDLER(onRightUp,              processRightUp          )
DECLARE_MOUSE_EVENT_HANDLER(onLeftDoubleClick,      processLeftDoubleClick  )
DECLARE_MOUSE_EVENT_HANDLER(onMiddleDoubleClick,    processMiddleDoubleClick)
DECLARE_MOUSE_EVENT_HANDLER(onRightDoubleClick,     processRightDoubleClick )
DECLARE_MOUSE_EVENT_HANDLER(onMouseWheel,           processMouseWheel       )
DECLARE_MOUSE_EVENT_HANDLER(onMouseMove,            processMouseMove        )

void Grid::onKeyDown(wxKeyEvent &event)
{
    m_pCore->processKeyDown(event);
}

void Grid::onKeyUp(wxKeyEvent &event)
{
    m_pCore->processKeyUp(event);
}

void Grid::onPaint(wxPaintEvent &event)
{
    for (unsigned i = 0; i < m_rows; i++)
        for (unsigned j = 0; j < m_cols; j++)
            paint(i, j);
}

void Grid::paint(const unsigned row, const unsigned col)
{
    wxPaintDC context(this);
    wxSize size = GetSize();

    GridElement *element = getElement(row, col);
    if (!element)
        return;

    wxColour color = element->getColor();
    unsigned width = size.GetWidth() / m_cols;
    unsigned height = size.GetHeight() / m_rows;

    context.SetBrush(wxBrush(color));
    context.DrawRectangle(col * width, row * height, width, height);
}

