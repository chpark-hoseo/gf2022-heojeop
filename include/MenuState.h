#pragma once
#include <string>
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "Button.h"

class MenuState : public GameState
{
public:
    MenuState();

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
protected:
private:

    static const std::string s_menuID; 
    std::vector<GameObject*> m_gameObjects; 

    
    static void s_menuToPlay();
    static void s_exitFromMenu();
};