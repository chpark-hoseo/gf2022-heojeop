#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::a(){

}
void Player::draw()
{
    SDLGameObject::draw(flip);
}
//������X ��ǥ�� -1 �� Update
void Player::update()
{
    int a = Player::m_position.getY();
    printf("%d\n", a);
    printf("Frame =  %d \n ", m_currentFrame);

    if (cha == idle) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 8);
        m_currentRow = 0;
        m_velocity.setX(0);
        m_velocity.setY(0);
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        handleInput();
    }

    if (cha == attack) {
        m_currentFrame = ((SDL_GetTicks() / 50) % 24);
        handleInput();
    }

    printf("cha = %d\n", cha);

    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
    
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
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        cha = run;
        if (cha == run) {
            flip = flip;
            m_currentRow = 1;
            m_velocity.setY(-3);
            if (Player::m_position.getY() <= 230) {
                m_velocity.setY(0);
            }
        }
        cha = idle;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        cha = run;
        if (cha == run) {
            flip = flip;
            m_currentRow = 1;
            m_velocity.setY(3);
            if (Player::m_position.getY() >= 390) {
                m_velocity.setY(0);
            }
        }
        cha = idle;
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C)) {
        cha = jump;

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

void Player::clean() {}