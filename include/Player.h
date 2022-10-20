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
    

private:
    float gravity = 0.2f;
    float fallspped = -5.0f;
    float jumpforce = 5.0f;
    float curjumpforce = 0.0;
    float deltatime;
    enum charstate { idle, run, attack, upper, dash , jumpattack, jump, guard };
    charstate cha = idle;
};

