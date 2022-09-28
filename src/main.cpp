// 20191246 장태훈 GameFrameWork SDL 
#ifndef __Game__
#define __Game__

#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[]){
	//Game 객체 생성
	g_game = new Game();

	//init함수(window제목, x위치, y위치, 좌표에서 창의 너비, 좌표에서 창의 높이,  Flags)
	g_game->init("Game Class", 640, 480, 640, 480, 0);
	
	
	//while문을 통해 함수들 실행
	while (g_game->running()) {
		g_game->handleEvents(); //종료버튼
		g_game->update(); //실행중
		g_game->render(); //메인 버퍼 출력
	}
	g_game->clean(); //정상 종료


	

	return 0;

}
#endif







