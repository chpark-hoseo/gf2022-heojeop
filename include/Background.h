#pragma once
#include "SDLGameObject.h"

//SDL 을 상속받도록 수정
class Background : public SDLGameObject{

public:

    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();

};