#pragma once
#include "SDLGameObject.h"

class Title : public SDLGameObject
{

public:

    Title(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();

};