//Game.h에서 선언한 클래스의 정의(기능)
#include "Game.h"
#include "TextureManager.h"


bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags) {


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

			}

			else {
				return false; //랜더러 생성 실패
			}

		}
		else {
			return false; //Window 생성 실패
		}
	}
	else {
		return false; //SDL 초기화 실패
	}


	//surface 생성

	if ( !TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	m_bRunning = true; //true 로 변경 후 정상 실행중 전환
	return true;
}




void Game::update() {

	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

}


void Game::render() {
	SDL_RenderClear(m_pRenderer); //백버퍼 그리기

	//백버퍼와 메인버퍼 사이에 랜더링 할 함수를 삽입 ) ****************** 중요 ********************
	
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
	/// ///////////////////////////////////////////////////////////////////////////////////////

	SDL_RenderPresent(m_pRenderer); // 메인버퍼 출력


}

	
//running 함수가 실행되면 현재 m_bRunning의 상태 리턴
bool Game::running() {
	return m_bRunning;
}
//정상적인 프로그램 종료를 위해 종료버튼 구현
void Game::handleEvents() {
	SDL_Event event;
	//while 문을 이용하여 이벤트를 검사
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false; // false 전환을 통해 프로그램 종료
			break;
		default:
			break;
		}
	}
}
//window와 render 삭제후 완전종료
void Game::clean() {

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


