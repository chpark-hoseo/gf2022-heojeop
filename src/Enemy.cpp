#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Enemy::draw()
{
    SDLGameObject::draw();
}
//������X ��ǥ�� -1 �� Update
void Enemy::update()
{
    m_x -= 1;
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean() {}