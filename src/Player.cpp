#include "Player.h"
#include "Game.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip, angle);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    
    int a = (int)InputHandler::Instance()->m_mousePosition->getX();

    angle = a;
    printf("%d\n" , a);
    m_currentFrame = 0;
    m_velocity.setX(0);
    m_velocity.setY(0);
    m_acceleration.setX(0);
    handleInput();
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    

}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {

        
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {

        playstate->fire();
    }

}











//void Player::Gravity() {
//    m_acceleration.setY(15);
//    if (m_position.getY() >= Ground) {
//        m_acceleration.setY(0);
//        m_position.setY(Ground);
//    }
//}
//
//void Player::Jumping() {
//    int CurrentPosition = m_position.getY();
//    m_acceleration.setY(-15);
//    if (m_position.getY() < 430) {
//        State = IsFalling;
//    }
//}
//
//int Player::GetPlayerYPosition() {
//
//    return m_position.getX();
//}
//
//void Player::PlayerDeath() {
//
//    
//}



void Player::clean() {}