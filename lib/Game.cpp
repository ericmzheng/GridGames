#include "Game.h"

bool Game::OnInit()
{
    GameWindow *window = new GameWindow(getGameTitle());
    window->Show(true);
    return true;
}

