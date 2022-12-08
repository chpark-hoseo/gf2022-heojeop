﻿#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <vector>

//SDL 을 상속받도록 수정



class Player : public SDLGameObject
{

public:

    std::vector<GameObject*> m_gameObjects;
    Vector2D *CurrentPosition();
    Player(const LoaderParams* pParams);
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();



private:

    
    void Jumping();
    void Gravity();
    int Ground = 500;
    enum PlayerState
    {
        idle,
        Jump,
        Dash,
        Walk,
        Death,
        DoubbleJump,
        IsFalling
      
    };

    PlayerState State = idle;
};

