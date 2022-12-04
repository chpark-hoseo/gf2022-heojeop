#pragma once
#include "SDLGameObject.h"

//SDL 을 상속받도록 수정



class Player : public SDLGameObject
{

public:

    Player(const LoaderParams* pParams);
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();
    
private:
    enum PlayerState
    {
        idle,
        UpSideWalk,
        DownWalk,
        DownWalk,
        DownRolling,
        DownSideRolling,
        UpRolling,
        UpSideRolling
      
    };
    PlayerState State = idle;
};

