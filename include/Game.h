//헤더파일 (클래스의 선언을 담당)
#include "SDL.h"
#include "TextureManager.h"

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
	int m_currentFrame;
	TextureManager m_textureManager;
	//SDL_Texture* m_pTexture;
	//SDL_Texture* m_Background;
	//SDL_Rect m_BgsourceRectangle, m_sourceRectangle, m_sourceRectangle2;// 원본 사각형
	//SDL_Rect m_BgdestinationRectangle, m_destinationRectangle, m_destinationRectangle2; // 대상 사각형
 	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};

/*typedef struct SDL_Rect {
	int x, y;
	int w, h;
} SDL_Rect; */