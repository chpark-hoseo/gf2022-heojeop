#pragma once
#include <vector>
#include "GameState.h"

class GameStateMachine 
{
public:

    GameStateMachine();

    void pushState(GameState* pState); 
    void changeState(GameState* pState); 
    void popState(); 

    void update();
    void render();

protected:
private:

    std::vector<GameState*> m_gameStates; 
};