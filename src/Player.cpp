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
    if (cha == attack) {
        m_currentFrame = ((SDL_GetTicks() / 50) % 24);
        handleInput();
    }else if (cha == upper || cha == dash || cha == jump || cha == jumpattack) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        handleInput();
    }
    if (cha == idle) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_currentRow = 0;
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        handleInput();
    }
    

    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
    
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        cha = run; 
        if (cha == run) {
            flip = SDL_FLIP_NONE;
            m_currentRow = 1;
            m_velocity.setX(5);
        }
        cha = idle;

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        cha = run;
        if (cha == run) {
            flip = SDL_FLIP_HORIZONTAL;
            m_currentRow = 1;
            m_velocity.setX(-5);
        }
        cha = idle;

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
        cha = jump;
        if (cha == jump) {
            m_currentRow = 2;
        }

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
        if (cha == idle || cha == run) {
            cha = attack;
            m_velocity.setX(0);
            m_currentRow = 3;
        }
        if (cha == jump) {
            cha = jumpattack;
            m_velocity.setX(0);
            m_currentRow = 4;
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z)) {
        if (cha == idle || cha == run || cha == attack) {
            cha = upper;
            m_velocity.setX(0);
            m_currentRow = 6;
        }

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
        if (cha == idle || cha == run) {
            cha = dash;
            m_velocity.setX(0);
            m_currentRow = 5;
        }

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
        if (cha != jump) {
            cha = guard;
            m_velocity.setX(0);
            m_currentRow = 7;
        }
        if (cha == jump) {
            m_currentRow = m_currentRow;
        }
    }
}
void jump() {
    
   
}
void attackcount() {
    
}

void Player::clean() {}