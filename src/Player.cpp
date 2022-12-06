#include "Player.h"
#include "Game.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{ 
    
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    switch (State)
    {
    case Player::idle:

        m_currentRow = idle;
        m_currentFrame = ((SDL_GetTicks() / 200) % 8);

        break;
    case Player::UpSideWalk:
        break;
    case Player::DownWalk:
        m_currentFrame = DownWalk;
        break;
    case Player::DownRolling:

        break;
    case Player::DownSideRolling:
        break;
    case Player::UpRolling:
        break;
    case Player::UpSideRolling:
        break;
    default:
        break;
    }
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
        flip = SDL_FLIP_NONE;
        State = DownWalk;
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
        flip = SDL_FLIP_HORIZONTAL;
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {

        m_velocity.setY(-2);
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
        m_velocity.setY(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
        State = DownWalk;
    }
    if (TheInputHandler::Instance()->getMouseButtonState(RIGHT)) {
         
    }
}

void Player::fire() {
    
}


void Player::clean() {}