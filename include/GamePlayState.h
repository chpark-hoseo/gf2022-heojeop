#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"

class PlayState : public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const;
    
protected:

private:

    bool FirstFlag = false;
    bool SecondFlag = false;
    bool ThirdFlag = false;
    
    int FlagPoint = 0;
    bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
    static const std::string s_playID; 
    std::vector<GameObject*> m_gameObjects; 
};