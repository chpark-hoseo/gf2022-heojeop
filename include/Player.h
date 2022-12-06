﻿#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <vector>

//SDL 을 상속받도록 수정



class Player : public SDLGameObject
{

public:

    std::vector<GameObject*> m_gameObjects;
    
    Player(const LoaderParams* pParams);
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void fire();
    bool Clicked = false;
    bool Clickable = false;

private:
    enum PlayerState
    {
        idle,
        UpSideWalk,
        DownWalk,
        DownRolling,
        DownSideRolling,
        UpRolling,
        UpSideRolling
      
    };

    PlayerState State = idle;
};

