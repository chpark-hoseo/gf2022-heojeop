#pragma once
#include "SDLGameObject.h"
#include "Player.h"

//SDL 을 상속받도록 수정


class Enemy : public SDLGameObject
{
public:
    
    void Chase();
    bool Destroyed();
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:

    //PlayState* playstate;
    Vector2D* ps();
    Player* player;
};
