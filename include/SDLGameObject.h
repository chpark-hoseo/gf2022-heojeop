#pragma once
#include "Vector2D.h"
#include "GameObject.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw(SDL_RendererFlip flip, int angle);
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}
	Vector2D& getPosition();
	int getWidth(); 
	int getHeight();

protected:
	
	Vector2D m_acceleration;
	Vector2D m_velocity;
	Vector2D m_position;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	int angle = 0;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame = 0;
	std::string m_textureID;
};