// 20191246 장태훈 GameFrameWork SDL 

#include "main.h"
#include <SDL2/SDL.h>


SDL_Window*		g_pWindow = 0; 
SDL_Renderer*	g_pRenderer = 0;
bool g_bRunning = false; //게임 실행시 참일경우 동작


//창 제목, x위치, y위치, 좌표에서 창의 너비, 좌표에서 창의 높이,  Flags)
bool init(const char* title, int xpos, int ypos, int height, int width, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        // g_pWindow 가 0이 아닐경우 Renderer 초기화
        if (g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else {
        return false;
    }
    // RGB 값으로 색상을 설정하는 함수( Red, Green, Blue, 투명도)

        SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
        SDL_Delay(1000);

    
    return true;
}

void render() {

    
    //백버퍼 그리기
    
    SDL_RenderClear(g_pRenderer);

    //메인버퍼 출력
    SDL_RenderPresent(g_pRenderer);

    // RGB 값으로 색상을 설정하는 함수 ( Red, Green, Blue, 투명도를 지정한 범위 내에서 rand 함수로 지정)
    SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);
}

int main(int argc, char* args[]){
    //init 함수 호출
        if (init("Breaking Up HelloSDL",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640, 480, SDL_WINDOW_SHOWN))
        {
            g_bRunning = true;

        }
        else {
            return 1;
        }
    while(g_bRunning){
        //render 함수 호출
        render();        
    }
    SDL_Quit();
    return 0;
}





