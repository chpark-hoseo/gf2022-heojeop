#include "Background.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {

		int CurrentPosition = m_position.getX();
}

void Background::draw() {
	SDLGameObject::draw(flip, angle);
}

void Background::update() {

	m_currentFrame = 0;
	SDLGameObject::update();
	
}

void Background::MoveChar() {


}

void Background::clean() {

}