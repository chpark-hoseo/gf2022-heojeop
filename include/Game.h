//헤더파일 (클래스의 선언을 담당)
#include "SDL.h"

class Game {
public:
	Game(){}
	~Game(){}

	int i = 0;
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void moveTexture();

private:
	SDL_Texture* m_pTexture; 
	SDL_Texture* m_pBTexture;
	SDL_Rect m_sourceRectangle; // 원본 사각형
	SDL_Rect m_destinationRectangle; // 대상 사각형
 	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};

/*typedef struct SDL_Rect {
	int x, y;
	int w, h;
} SDL_Rect; */