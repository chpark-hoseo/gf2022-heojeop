#pragma once
#include "SDLGameObject.h"

//SDL �� ��ӹ޵��� ����
class Background : public SDLGameObject{

public:

    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();

};