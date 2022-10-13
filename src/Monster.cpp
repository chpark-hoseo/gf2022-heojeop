#include "Monster.h"

void Monster::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}
//������X ��ǥ�� -1 �� Update
void Monster::update(int i) {
    
    if (m_x < 370) {
        m_x += i;
    }

    
}