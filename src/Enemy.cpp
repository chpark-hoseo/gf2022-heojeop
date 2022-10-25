#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{
    SDLGameObject::draw(flip = SDL_FLIP_NONE);
}

void Enemy::update()
{
   // m_acceleration.setX(0.1);
    SDLGameObject::update();
}
void Enemy::clean() {}