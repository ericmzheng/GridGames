#include "GridElement.h"

GridElement::GridElement(unsigned row, unsigned col)
    : m_row(row), m_col(col), m_defaultColor(*wxLIGHT_GREY)
{
}

GridElement::GridElement(const wxColour &color, unsigned row, unsigned col)
    : m_row(row), m_col(col), m_defaultColor(color)
{
}

wxColour GridElement::getColor() const
{
    if (!m_vColorStack.empty())
        return m_vColorStack.back();
    return m_defaultColor;
}

void GridElement::setColor(const wxColour &color)
{
    m_vColorStack.push_back(color);
}

void GridElement::unsetColor()
{
    if (!m_vColorStack.empty())
        m_vColorStack.pop_back();
}

void GridElement::unsetColor(const wxColour &color)
{
    for (std::vector<wxColour>::reverse_iterator i = m_vColorStack.rbegin();
         i != m_vColorStack.rend();
         i++)
    {
        if (*i == color)
        {
            m_vColorStack.erase(std::next(i).base());
            break;
        }
    }
}

