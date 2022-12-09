#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{
    
    SDLGameObject::draw(flip, angle);
}

void Enemy::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 8);
    m_velocity.setY(2);
    m_acceleration.setY(1);
    m_currentRow = 0;
    SDLGameObject::update();


}

bool Enemy::Destroyed() {

    printf(" Destroyed !!");
    return true;
}


void Enemy::clean() {
   
    
}
