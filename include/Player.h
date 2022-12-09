#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "GamePlayState.h"
#include <vector>
class Background;

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
    void PlayerDeath();
    int a;
private:

    PlayState* playstate;
    InputHandler* inputHandler;
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

