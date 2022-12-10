#pragma once
#include "GameState.h"
#include "GameObject.h"


using namespace std;

class GameOverState : public GameState
{
public:
    GameOverState();

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

  
    virtual string getStateID() const;

protected:
private:

    
    static void s_gameOverToMain(); 
    static void s_restartPlay(); 

    static const string s_gameOverID; 

    vector<GameObject*> m_gameObjects; 
};