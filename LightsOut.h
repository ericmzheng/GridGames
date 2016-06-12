#ifndef _LIGHTS_OUT_H_
#define _LIGHTS_OUT_H_

#include <vector>
#include <wx/wx.h>
#include "lib/GameCore.h"

class LightsOut: public GameCore
{
public:
    LightsOut();
    void initialize() override;

    void processLeftDown(const wxMouseEvent &event, unsigned row, unsigned col) override;
    void processLeftUp(const wxMouseEvent &event, unsigned row, unsigned col) override;
private:
    static const unsigned InitRows = 5;
    static const unsigned InitCols = 5;
    static const unsigned InitWidth = 400;
    static const unsigned InitHeight = 400;
    static const wxColour LightColor;

    void flip(unsigned row, unsigned col);

    unsigned m_downRow;
    unsigned m_downCol;

    bool m_lights[InitRows][InitCols];
};

const wxColour LightsOut::LightColor = wxColour(255, 0, 0);

GameCore *getGameCore()
{
    return new LightsOut();
}

wxString getGameTitle()
{
    return "Lights Out";
}

#endif // _LIGHTS_OUT_H_

