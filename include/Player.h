#pragma once
#include "SDLGameObject.h"

//SDL 을 상속받도록 수정


class Player : public SDLGameObject
{
public:
    
    Player(const LoaderParams* pParams);
    void handleInput();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void a();

    
private:
    int g;
    enum charstate { idle, run , jump , attack , upper , dash, jumpattack,  guard, air};
    charstate cha = idle;
};

