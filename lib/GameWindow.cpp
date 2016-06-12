#include "GameWindow.h"

GameWindow::GameWindow(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER)
{
    m_pFileMenu = new wxMenu;
    m_pFileMenu->Append(wxID_EXIT, wxT("&Quit"));
    m_pMenuBar = new wxMenuBar;
    m_pMenuBar->Append(m_pFileMenu, wxT("&File"));
    SetMenuBar(m_pMenuBar);

    m_pStatusBar = CreateStatusBar();
    m_pStatusBar->SetStatusText(wxT(""));

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GameWindow::OnQuit));

    m_pCore = getGameCore();
    m_pGrid = new Grid(this, m_pCore);
    m_pCore->setGrid(m_pGrid);
    m_pCore->initialize();

    Fit();
}

void GameWindow::OnQuit(wxCommandEvent &event)
{
    Close(true);
}

