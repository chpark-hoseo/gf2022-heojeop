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
    m_currentRow = 5;
    m_velocity.setX(0);
    m_velocity.setY(0);
    m_acceleration.setX(0);
    m_acceleration.setY(0);
    handleInput();

    m_currentFrame = ((SDL_GetTicks() / 120) % 8);

    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
    
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        flip = SDL_FLIP_NONE;
        m_currentRow = 4;
        m_velocity.setX(2);
        m_acceleration.setX(2);

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        flip = SDL_FLIP_HORIZONTAL;
        m_currentRow = 4;
        m_velocity.setX(-2);
        m_acceleration.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {

        m_currentRow = 5;
        m_velocity.setY(-2);
        m_acceleration.setY(-5);
        
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
        
        m_currentRow = 2;
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
        m_currentRow = 2;
      
    }
}
void jump() {
    
}
void attackcount() {

}

void Player::clean() {}