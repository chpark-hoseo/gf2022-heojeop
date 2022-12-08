#pragma once
#include <vector>
#include <iostream>
#include "GameState.h"
#include "GameObject.h"

class PauseState : public GameState
{
public:

    virtual void update(); 
    virtual void render(); 

    virtual bool onEnter();
    virtual bool onExit();  

   
    virtual std::string getStateID() const;
protected:
private:

   
    static void s_pauseToMain(); 
    static void s_resumePlay(); 
    static void s_Save();
    static void s_Option();
 
    static const std::string s_pauseID;

    std::vector <GameObject*> m_gameObjects; 
};