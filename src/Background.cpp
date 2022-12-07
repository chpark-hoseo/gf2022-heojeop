#include "Background.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Background::draw() {
	SDLGameObject::draw(flip);
}

void Background::update() {

	m_currentFrame = 0;
	SDLGameObject::update();
	
}

void Background::clean() {

}