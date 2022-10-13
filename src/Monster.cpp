#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}
//대상상자X 좌표를 -1 씩 Update
void Monster::update(int i) {
    
    if (m_x < 370) {
        m_x += i;
    }

    
}