#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw();
}
//������X ��ǥ�� -1 �� Update
void Player::update()
{
    
    m_currentFrame = ((SDL_GetTicks() / 200) % 6);
    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
    handleInput();
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
        m_velocity.setY(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
        m_velocity.setY(2);
    }
}

void Player::clean() {}