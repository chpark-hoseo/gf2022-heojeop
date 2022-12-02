#include "Mouse.h"
#include "InputHandler.h"


Mouse::Mouse(const LoaderParams* pParams) : SDLGameObject(pParams) {};

void Mouse::draw() {

	SDLGameObject::draw(flip);
}


void Mouse::update(){

	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT)) {

	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	m_currentFrame = 0;
	SDLGameObject::update();
}
