#pragma once
#include "SDLGameObject.h"

//SDL �� ��ӹ޵��� ����


class Enemy : public SDLGameObject
{
public:
    
    bool Destroyed();
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:

};
