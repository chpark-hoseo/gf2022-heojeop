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
    m_currentFrame = ((SDL_GetTicks() / 100) % 8);
    //printf("%d\n", g);
    printf("Frame =  %d \n ", m_currentFrame);
    int a = Player::m_position.getY();
    //printf("%d\n", cha);
    if (cha == idle || cha == guard ) {
        m_currentRow = idle;
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        handleInput();
    }

    if (cha == upper) {
        m_currentRow = upper;
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
    if (cha == attack ) {
        m_currentFrame = ((SDL_GetTicks() / 50) % 24);

    }
    if (cha == dash) {
        m_currentRow = dash;
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
    if (cha == jump || cha == jumpattack) {
       
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
            m_currentRow = run;
            m_velocity.setX(5);
            cha = idle;
        }
        if (cha == jump) {
            cha = jump;
            flip = SDL_FLIP_NONE;
            m_currentRow = jump;
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
            m_currentRow = run;
            m_velocity.setX(-5);
            cha = idle;
        }
        if (cha == jump) {
            cha = jump;
            flip = SDL_FLIP_HORIZONTAL;
            m_currentRow = jump;
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
            m_currentRow = run;
            m_velocity.setY(-3);
            cha = idle;
            if (Player::m_position.getY() <= 230) {
                m_velocity.setY(0);

            }
            if (cha == jump) {
                cha = jump;
                m_currentRow = jump;
                m_velocity.setX(0);
            }
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {

        if (cha != jump) {
            cha = run;
            flip = flip;
            m_currentRow = run;
            m_velocity.setY(3);
            cha = idle;
            if (Player::m_position.getY() >= 390) {
                m_velocity.setY(0);
            }
        }
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
        if (cha == jump) {
            return;
        }
        g = Player::m_position.getY();
        m_currentRow = 2;
        cha = jump;

    }
    
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X)) {
        if (cha == idle || cha == run ) {
            cha = attack;
            m_velocity.setX(0);
            m_velocity.setY(0);
            m_currentRow = attack;
        }

        /*if (cha == attack1 && (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))) {
     
            m_velocity.setX(0);
            m_velocity.setY(0);
            m_currentRow = attack2;
        }
        if (cha == attack2 && (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))) {
            cha == attack3;
            m_velocity.setX(0);
            m_velocity.setY(0);
            m_currentRow = attack3;
        }*/ 
        if (cha == jump) {
            m_currentRow = jumpattack;
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
        if (cha == run) {
            cha = dash;
        }

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
        if (cha != jump) {
            cha = guard;
            m_velocity.setX(0);
            m_currentRow = guard;
        }
        if (cha == jump) {
            m_currentRow = m_currentRow;
        }

    }
}

void Player::clean() {}