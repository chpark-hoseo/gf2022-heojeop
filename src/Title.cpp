#include "Title.h"

Title::Title(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Title::draw() {
	m_currentFrame = 0;
	SDLGameObject::draw(flip, angle);

}

void Title::update() {
	SDLGameObject::update();
	
}

void Title::clean() {
	
}