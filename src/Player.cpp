#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update(){
    m_x -= 1;
}