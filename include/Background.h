#pragma once
#include "SDLGameObject.h"
#include "Player.h"

//SDL �� ��ӹ޵��� ����
class Background : public SDLGameObject{

public:

    Player* player;
    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void MoveBackGround();

private :

};