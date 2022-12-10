#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip, angle);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position) / 500;
    getAngle();
    m_currentFrame = 0;
    handleInput();
    
    
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
}

void Player::getAngle() {
    int mmpx = (int)InputHandler::Instance()->m_mousePosition->getX();
    int mmpy = (int)InputHandler::Instance()->m_mousePosition->getY();
    int mpx = m_position.getX();
    int mpy = m_position.getY();

    int x = mpx - mmpx;
    int y = mpy - mmpy;

    int degree = atan2(x, y) * -180 / 3.14;

    printf("%d\n", degree);

    angle = degree;
}

void Player::handleInput()
{

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {

        Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
        m_velocity = (*vec - m_position) / 100;
        ps = Boost;

    }
}

void Player::ResetPosition() {

    ps = idle;
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