#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

class Mouse : public SDLGameObject {
	
public:

	Mouse(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	bool CursorState();
	//virtual void clean();

};