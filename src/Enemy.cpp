#include "Enemy.h"


Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{
    
    SDLGameObject::draw(flip);
}

void Enemy::update()
{

    Vector2D* playerposition = player->CurrentPosition();
    //printf("%d", &playerposition);
    m_currentFrame = 0;
    SDLGameObject::update();
}

bool Enemy::Destroyed() {

    return true;
}


void Enemy::clean() {}
