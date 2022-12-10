#pragma once
#include "SDLGameObject.h"
#include "Player.h"

class Background : public SDLGameObject{
public:


    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:

    int CurrentPosition;
    void MoveChar();
    Player *player;
};