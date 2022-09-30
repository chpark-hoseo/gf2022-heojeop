//Game.h에서 선언한 클래스의 정의(기능)
#include "Game.h"

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
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");

	//생성한 surface 를 이용하여 Texture 생성
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	//사용한 surface 삭제

	SDL_FreeSurface(pTempSurface);

	//Load 한 Texture 의 크기를 가져옴
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	//원본 상자와 대상상자 생성 위치 설정
	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;

	//출력 범위를 동일하게 설정
	
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;


	printf("SDL_Init failed: %s\n", SDL_GetError());

	m_bRunning = true; //true 로 변경 후 정상 실행중 전환
	return true;
}



void Game::update() {

	m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);

}


void Game::render() {
	SDL_RenderClear(m_pRenderer); //백버퍼 그리기

	//백버퍼와 메인버퍼 사이에 랜더링 할 함수를 삽입 ) ****************** 중요 ********************

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	
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
	SDL_DestroyTexture(m_pTexture);
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


