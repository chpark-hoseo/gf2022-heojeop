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

    switch (State)
    {
    case Player::idle:

        m_currentRow = idle;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);

        break;
    case Player::UpSideWalk:
        break;
    case Player::DownWalk:
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
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setX(2);
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
        flip = SDL_FLIP_HORIZONTAL;
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setY(-2);
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {

        m_currentFrame = ((SDL_GetTicks() / 100) % 6);
        m_velocity.setY(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
        State = DownWalk;
    }
    if (TheInputHandler::Instance()->getMouseButtonState(RIGHT)){
        
        m_currentRow = 4; 
    }
}


void Player::clean() {}