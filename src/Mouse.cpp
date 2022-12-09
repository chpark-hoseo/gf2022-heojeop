#include "Mouse.h"

Mouse::Mouse(const LoaderParams* pParams) : SDLGameObject(pParams) {};

void Mouse::draw() {

	SDLGameObject::draw(flip, angle);
}


void Mouse::update(){

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	m_currentFrame = 0;
	SDLGameObject::update();

}


