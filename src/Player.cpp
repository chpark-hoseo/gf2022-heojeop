#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw();
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    m_x -= 1;
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

void Player::clean() {}