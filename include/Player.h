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
    enum charstate { idle = 0, run = 1 , jump = 2 , jumpattack = 4, dash = 5, attack = 3, upper = 6, guard = 7, air};
    charstate cha = idle;
};

