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

    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
    m_currentRow = idle;
    m_currentFrame = ((SDL_GetTicks() / 200) % 8);

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if (pMousePos->getX() < (m_position.getX() + m_width) and pMousePos->getX() > m_position.getX()
        and pMousePos->getY() < (m_position.getY() + m_height)
        and pMousePos->getY() > m_position.getY()) {
        Clickable = true;
        printf("Clickable");
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
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && Clickable == true) {
        Clicked = true;
        printf("Charactor Clicked ");
    }
    if (TheInputHandler::Instance()->getMouseButtonState(RIGHT) && Clicked == true) {
        
        Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
        m_velocity = (*vec - m_position) / 100;

    }
}



void Player::fire() {
    
}


void Player::clean() {}