#pragma once
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



private:

    enum PlayerState
    {
        idle,
        Jump,
        Dash,
        Walk,
        Death,
        DoubbleJump
      
    };

    PlayerState State = idle;
};

