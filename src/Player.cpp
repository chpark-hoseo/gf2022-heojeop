#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip);
}
//������X ��ǥ�� -1 �� Update
void Player::update()
{ 
    
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    
    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        flip = SDL_FLIP_NONE;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        flip = SDL_FLIP_HORIZONTAL;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setY(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setY(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)){
        
        
    }
}


void Player::clean() {}