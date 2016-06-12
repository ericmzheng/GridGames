#include "LightsOut.h"

LightsOut::LightsOut()
    : GameCore(), m_downRow(-1), m_downCol(-1)
{
}

void LightsOut::initialize()
{
    for (unsigned i = 0; i < InitRows; i++)
        m_pGrid->addRow();
    for (unsigned i = 0; i < InitCols; i++)
        m_pGrid->addCol();

    for (unsigned i = 0; i < InitRows; i++)
        for (unsigned j = 0; j < InitCols; j++)
            m_lights[i][j] = false;

    m_pGrid->SetSize(InitWidth, InitHeight);
}

void LightsOut::processLeftDown(const wxMouseEvent &event, unsigned row, unsigned col)
{
    m_downRow = row;
    m_downCol = col;
}

void LightsOut::processLeftUp(const wxMouseEvent &event, unsigned row, unsigned col)
{
    if (row != m_downRow || col != m_downCol)
        return;

    flip(row, col);
    if (row > 0)
        flip(row - 1, col);
    if (col > 0)
        flip(row, col - 1);
    if (row < InitRows - 1)
        flip(row + 1, col);
    if (col < InitCols - 1)
        flip(row, col + 1);

    m_pGrid->Refresh();
}

void LightsOut::flip(unsigned row, unsigned col)
{
    if (m_lights[row][col])
        m_pGrid->unsetColor(row, col);
    else
        m_pGrid->setColor(LightColor, row, col);
    m_lights[row][col] = !m_lights[row][col];
}

