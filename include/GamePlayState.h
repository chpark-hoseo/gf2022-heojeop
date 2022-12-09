#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Enemy.h"
#include "Player.h"

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

    Player* player;
    Enemy* enemy;
    bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
    static const std::string s_playID; 
    std::vector<GameObject*> m_gameObjects; 
};