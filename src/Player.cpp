#include "Player.h"
#include "Game.h"
#include "UnitClick.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    switch (State)
    {
    case Player::idle:
        
        m_currentFrame = 
        break;
    case Player::Jump:
        break;
    case Player::Dash:
        break;
    case Player::Walk:
        break;
    case Player::Death:
        break;
    case Player::DoubbleJump:
        break;
    default:
        break;
    }
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

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT)) {

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT)) {

    }
}




void Player::clean() {}