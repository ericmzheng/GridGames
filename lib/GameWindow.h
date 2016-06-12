#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_

#include <wx/wx.h>
#include "Grid.h"
#include "GameCore.h"

GameCore *getGameCore();

class GameWindow : public wxFrame
{
public:
    GameWindow(const wxString &title);
    void OnQuit(wxCommandEvent &event);
protected:
    GameCore    *m_pCore;
    Grid        *m_pGrid;
    wxMenuBar   *m_pMenuBar;
    wxMenu      *m_pFileMenu;
    wxStatusBar *m_pStatusBar;
};

#endif // _GAME_WINDOW_H_

