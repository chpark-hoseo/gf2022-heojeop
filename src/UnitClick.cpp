#include "UnitClick.h"
#include "InputHandler.h"

UnitClick::UnitClick(const LoaderParams* pParams) : SDLGameObject(pParams) {
    //Clicked = false;
}

void UnitClick::draw() {

	SDLGameObject::draw(flip);
}

void UnitClick::update() {

    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if (pMousePos->getX() < (m_position.getX() + m_width) and pMousePos->getX() > m_position.getX()
        and pMousePos->getY() < (m_position.getY() + m_height)
        and pMousePos->getY() > m_position.getY())
    {
        if (TheInputHandler::Instance()->getMouseButtonState(LEFT) and m_bReleased)
        {
            //m_currentFrame = CLICKED;
            m_callback();
            m_bReleased = false;
        }
        else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            //m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        //m_currentFrame = MOUSE_OUT;
    }
}
