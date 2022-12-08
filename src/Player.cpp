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


    m_currentFrame = ((SDL_GetTicks() / 100) % 8);
    
    //Gravity();
    switch (State)
    {
    case Player::idle:

        m_currentRow = idle;
        Gravity();
        break;
    case Player::Jump:
        m_currentRow = Jump;
        Jumping();
        break;
    case Player::Dash:
        m_currentRow = Dash;
        break;
    case Player::Walk:

        m_currentRow = Walk;

        break;
    case Player::Death:
        break;
    case Player::DoubbleJump:
        break;
    default:
        break;
    case Player::IsFalling:
        Gravity();
        if (m_position.getY() == Ground) {
            State = idle;
        }
        break;
    }

    m_velocity.setX(0);
    m_velocity.setY(0);
    m_acceleration.setX(0);
    handleInput();
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 


}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        if (State == Jump || State == IsFalling) {
            m_velocity.setX(-2);
        }
        else {
            m_velocity.setX(-2);
            flip = SDL_FLIP_HORIZONTAL;
            State = Walk;
        }

    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        if (State == Jump || State == IsFalling) {
            m_velocity.setX(2);
        }
        else {
            m_velocity.setX(2);
            flip = SDL_FLIP_NONE;
            State = Walk;
        }
        State = idle;

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {

        if (State == IsFalling) {
            return;
        }
        else {
            State = Jump;
        }

        

    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT)) {
        if (State != Jump || State != IsFalling) {
            m_acceleration.setX(-3);
            //m_velocity.setX(-3);
            State = Dash;
        }
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LSHIFT)) {
        if (State == Walk  ) {
            m_acceleration.setX(3);
            //m_velocity.setX(3);
            State = Dash;
        }
    }
}


void Player::Gravity() {
    m_acceleration.setY(15);
    if (m_position.getY() >= Ground) {
        m_acceleration.setY(0);
        m_position.setY(Ground);
    }
}

void Player::Jumping() {
    int CurrentPosition = m_position.getY();
    m_acceleration.setY(-15);
    if (m_position.getY() < 430) {
        State = IsFalling;
    }
}

Vector2D* Player::CurrentPosition() {

    return &m_position;
}

int Player::PlayerPo() {
    return m_position.getX();
}



void Player::clean() {}