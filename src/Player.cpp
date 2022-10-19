#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    m_currentRow = 5;
    m_velocity.setX(0);
    m_velocity.setY(0);
    m_acceleration.setX(0);
    m_acceleration.setY(0);
    handleInput();

    m_currentFrame = ((SDL_GetTicks() / 120) % 8);

    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
    
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