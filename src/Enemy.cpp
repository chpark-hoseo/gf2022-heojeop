#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{
    
    SDLGameObject::draw(flip);
}

void Enemy::update()
{
    Vector2D* playerposition = player->CurrentPosition();
    //m_velocity = *playerposition;
    m_currentFrame = 0;
    SDLGameObject::update();
}

bool Enemy::Destroyed() {
    printf(" Destroyed !!");
    return true;
}


void Enemy::clean() {}
