#include "GameObject.h"
#include "TextureManager.h"


//객체 초기값 설정
void GameObject::load(int x, int y, int width, int height, std::string textureID) {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
        m_textureID = textureID;
        m_currentRow = 0;
        m_currentFrame = 0;
}

// TextureManager 이용하여 m_textureID 그리기
void GameObject::draw(SDL_Renderer* pRenderer) {
    TheTextureManager::Instance()->drawFrame(m_textureID,
            m_x, m_y,
            m_width, m_height,
            m_currentRow,
            m_currentFrame,
            pRenderer);
}
//대상 상자 X 좌표를 +1 씩 Update
void GameObject::update(){
    m_x += 1;       
}
