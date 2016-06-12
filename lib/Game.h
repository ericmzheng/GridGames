#ifndef _GAME_H_
#define _GAME_H_

#include <wx/wx.h>
#include "GameWindow.h"

wxString getGameTitle();

class Game : public wxApp
{
public:
    virtual bool OnInit();
};

#endif // _GAME_H_

