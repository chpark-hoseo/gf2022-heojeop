#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

int g = 0;
void Player::a(){

}
void Player::draw()
{
    SDLGameObject::draw(flip);
}
//대상상자X 좌표를 -1 씩 Update
void Player::update()
{
    handleInput();
    
    //printf("%d\n", g);
    //printf("Frame =  %d \n ", m_currentFrame);
    int a = Player::m_position.getY();
    printf("%d\n", cha);
    if (cha == idle || cha == guard ) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_currentRow = 0;
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        handleInput();
    }

    if (cha == upper) {
        m_currentRow = 6;
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
    if (cha == attack) {
        m_currentFrame = ((SDL_GetTicks() / 50) % 24);
        handleInput();
    }
    if (cha == dash) {
        m_currentRow = 5;
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
    if (cha == jump || cha == jumpattack) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        if (Player::m_position.getY() == g) {
            m_acceleration.setY(-1);
        }
        if (Player::m_position.getY() < g - 100) {
            m_acceleration.setY(1);
            handleInput();
        }
        if (cha == jump && Player::m_position.getY() > g) {
            m_velocity.setX(0);
            m_velocity.setY(0);
            m_position.setY(g);
            m_acceleration.setY(0);
            if (Player::m_position.getY() == g) {
                cha = idle;
            }
        }
    }

    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
    
}


void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        if (cha != jump) {
            cha = run;
            flip = SDL_FLIP_NONE;
            m_currentRow = 1;
            m_velocity.setX(5);
            cha = idle;
        }
        if (cha == jump) {
            cha = jump;
            flip = SDL_FLIP_NONE;
            m_currentRow = 2;
            m_velocity.setX(5);
        }
        if (cha == upper) {
            return;
        }
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        if (cha != jump ) {
            cha = run;
            flip = SDL_FLIP_HORIZONTAL;
            m_currentRow = 1;
            m_velocity.setX(-5);
            cha = idle;
        }
        if (cha == jump) {
            cha = jump;
            flip = SDL_FLIP_HORIZONTAL;
            m_currentRow = 2;
            m_velocity.setX(-5);
        }
        if (cha == upper) {
            return;
        }
        
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        if (cha != jump) {
            cha = run;
            flip = flip;
            m_currentRow = 1;
            m_velocity.setY(-3);
            cha = idle;
            if (Player::m_position.getY() <= 230) {
                m_velocity.setY(0);

            }
            if (cha == jump) {
                cha = jump;
                m_currentRow = 2;
                m_velocity.setX(0);
            }
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {

        if (cha != jump) {
            cha = run;
            flip = flip;
            m_currentRow = 1;
            m_velocity.setY(3);
            cha = idle;
            if (Player::m_position.getY() >= 390) {
                m_velocity.setY(0);
            }
        }
        if (cha == jump ) {
            return;
        }

    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
        if (cha == jump) {
            return;
        }
        m_currentRow = 2;
        g = Player::m_position.getY();
        cha = jump;

    }
    
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
        if (cha == idle || cha == run) {
            cha = attack;
            m_velocity.setX(0);
            m_velocity.setY(0);
            m_currentRow = 3;
        }
        if (cha == jump) {
            m_currentRow = 4;
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z)) {
        if (cha == idle || cha == run || cha == attack) {
            cha = upper;
        }
        if (cha == upper) {
            return;
        }

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
        if (cha == idle || cha == run) {
            cha = dash;
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

void Player::clean() {}