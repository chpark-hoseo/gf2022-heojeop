#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Bullet : public SDLGameObject {
public:

    Bullet(const LoaderParams* pParams);
    
    void FireBullet();
    virtual void draw();
    virtual void update();
    virtual void clean() {}
};