#pragma once
#include "SDLGameObject.h"

//SDL �� ��ӹ޵��� ����


class Enemy : public SDLGameObject
{
public:
    
    
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();

    int getXPos();
    int getYPos();
private:
    enum EnemyState
    {
        Chase,
        Death

    };
    
    EnemyState enemystate = Chase;
};
