#include "Player.h"
#include "Game.h"
#include "UnitClick.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
    SDLGameObject::draw(flip);
}
//������X ��ǥ�� -1 �� Update
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
    }

    handleInput();
    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
    m_currentRow = idle;
    m_currentFrame = ((SDL_GetTicks() / 200) % 8);

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
        printf("Charactor UnClicked ");
    }
    if (TheInputHandler::Instance()->getMouseButtonState(RIGHT) && Clicked == true) {
        vec = TheInputHandler::Instance()->getMousePosition();
        State = Move;
        Clicked = false;
    }

}



bool Player::Clickabled() {

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
    if (bool Clickable = pMousePos->getX() < (m_position.getX() + m_width) and pMousePos->getX() > m_position.getX() and pMousePos->getY() < (m_position.getY() + m_height) and pMousePos->getY() > m_position.getY() == 1)
        return true;
    else
        return false;
}


void Player::clean() {}