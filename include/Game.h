﻿//헤더파일 (클래스의 선언을 담당)
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
class Game {

	

public:
	std::vector<GameObject*> m_gameObjects;

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }

private:

	Game() {}
	~Game() {}
	static Game* s_pInstance;
	int m_currentFrame;
	//TextureManager m_textureManager;
 	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};




typedef Game TheGame;