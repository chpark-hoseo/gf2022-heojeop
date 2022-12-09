#pragma once
#include "SDLGameObject.h"

//SDL 을 상속받도록 수정


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
