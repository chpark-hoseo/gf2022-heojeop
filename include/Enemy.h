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

};
