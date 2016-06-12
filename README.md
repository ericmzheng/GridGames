# GridGames
A library for writing simple board games

## How to Use
1. Create a class extending GameCore and overriding any used methods.
2. Create two functions:
    ```
    GameCore *getGameCore()
    {
        return new MyGameCore();
    }

    wxString getGameTitle()
    {
        return "My Game Title";
    }
    ```
3. Compile your game.
