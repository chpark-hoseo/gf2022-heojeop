#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"



class PlayState : public GameState
{
public:
    PlayState();
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
protected:
private:

    //Private methods:
    bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

    //Atributes:
    static const std::string s_playID; 
    std::vector<GameObject*> m_gameObjects; 
};