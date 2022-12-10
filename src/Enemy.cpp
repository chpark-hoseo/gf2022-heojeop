#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{

    
    SDLGameObject::draw(flip, angle);
}

void Enemy::update()
{

    switch (enemystate)
    {
    case Enemy::Chase:
        
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_velocity.setY(2);
        m_acceleration.setY(2);
        break;
    case Enemy::Death:
        
        break;
    default:
        break;
    }


    SDLGameObject::update();


}

int Enemy::getXPos() {
    return m_position.getX();
}

int Enemy::getYPos() {
    return m_position.getY();
}



void Enemy::clean() {
   
    
}
