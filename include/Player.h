#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <vector>

//SDL 을 상속받도록 수정



class Player : public SDLGameObject
{

public:


    Player(const LoaderParams* pParams);
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void ResetPosition();
private:


    void getAngle();
    InputHandler* inputHandler;
    enum PlayerState
    {
        idle,
        Rush,
        Boost,
        RightDrift,
        LeftDrift
      
    };

    PlayerState ps = idle;
    std::vector<GameObject*> m_gameObjects;
    
};

