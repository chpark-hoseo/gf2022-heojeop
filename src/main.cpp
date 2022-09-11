// 20191246 장태훈 GameFrameWork SDL 

#include "main.h"
#include <SDL2/SDL.h>


SDL_Window*		g_pWindow = 0; 
SDL_Renderer*	g_pRenderer = 0;


int main(int argc, char* args[]){

	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) { 
		//SDL 하위 시스템 초기화

		//SDL_CreateWindow(창 제목, 좌표x, 좌표y, width 크기, height 크기)
		g_pWindow = SDL_CreateWindow("Setting up SDL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,640, 480,
			SDL_WINDOW_SHOWN);
		
		// window 생성에 성공하면 랜더러 생성
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		return 1; //SDL 초기화 실패시 
	}
	
	// RGB 값으로 색상을 설정하는 함수 ( Red, Green, Blue, 투명도)
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255); 
	SDL_RenderClear(g_pRenderer);	// window를 지우고
	SDL_RenderPresent(g_pRenderer);	// window를 보여줌

	SDL_Delay(5000); // 5000ms 이후에
	SDL_Quit();	// SDL 을 종료함

	return 0;
}

