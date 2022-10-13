#include "GameObject.h"
#include "TextureManager.h"


//��ü �ʱⰪ ����
void GameObject::load(int x, int y, int width, int height, std::string textureID) {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
        m_textureID = textureID;
        m_currentRow = 0;
        m_currentFrame = 0;
}

// TextureManager �̿��Ͽ� m_textureID �׸���
void GameObject::draw(SDL_Renderer* pRenderer) {
    TheTextureManager::Instance()->drawFrame(m_textureID,
            m_x, m_y,
            m_width, m_height,
            m_currentRow,
            m_currentFrame,
            pRenderer);
}
//��� ���� X ��ǥ�� +1 �� Update
void GameObject::update(){
    m_x += 1;       
}
