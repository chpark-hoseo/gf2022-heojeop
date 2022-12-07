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
    bool Clickabled();


private:
    Vector2D *vec;
    bool Clicked = false;
    bool Clickable = false;
    enum PlayerState
    {
        idle,
        UpSideWalk,
        DownWalk,
        DownRolling,
        DownSideRolling,
        UpRolling,
        UpSideRolling,
        Move
      
    };

    PlayerState State = idle;
};

