#include "Background.h"
#include "Player.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Background::draw() {
	SDLGameObject::draw(flip = SDL_FLIP_NONE);
}

void Background::update() {
	
}

void Background::clean() {

}