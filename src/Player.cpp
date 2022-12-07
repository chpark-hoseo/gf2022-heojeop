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
    case Move:
        if (m_position.getX() != vec->getX()){
            m_velocity = (*vec - m_position) / 100 ;
            printf("%d", vec);
        }
        //Vector2D* ClickPosition = TheInputHandler::Instance()->getMousePosition();
        break;
    case idle:
        m_currentRow = idle;
        m_currentFrame = ((SDL_GetTicks() / 200) % 8);
        m_velocity.setX(0);
        m_velocity.setY(0);
    }

    Clickabled();

    handleInput();
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    Clickabled();

}

void Player::handleInput()
{

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && Clickabled()) {
        Clicked = true;
        printf("Charactor Clicked ");
    }
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && !Clickabled()) {
        Clicked = false;
        State = idle;
        printf("Charactor UnClicked ");
    }
    if (TheInputHandler::Instance()->getMouseButtonState(RIGHT) && Clicked == true) {
        vec = TheInputHandler::Instance()->getMousePosition();
        State = Move;
        //Clicked = false;
    }

}



bool Player::Clickabled() {

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
    if (bool Clickable = pMousePos->getX() < (m_position.getX() + m_width) and pMousePos->getX() > m_position.getX() and pMousePos->getY() < (m_position.getY() + m_height) and pMousePos->getY() > m_position.getY() == 1)
        return true;
    else
        return false;

    printf("%d", Clickable);
}


void Player::clean() {}