//Game.h에서 선언한 클래스의 정의(기능)
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"

//정적멤버변수정의
Game* Game::s_pInstance = 0;



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
	if (!TheTextureManager::Instance()->load("assets/Background1.jpg", "Background", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/Charac.png", "Charactor", m_pRenderer))
	{
		return false;
	} 
	
	m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 2048, 600, "Background")));
	m_gameObjects.push_back(new Player(new LoaderParams(100, 270, 280, 244, "Charactor")));


	m_bRunning = true; //true 로 변경 후 정상 실행중 전환
	return true;
}




void Game::update() {
	//대상상자 위치 Update 

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
	
}


void Game::render() {
	SDL_RenderClear(m_pRenderer); //백버퍼 그리기

	//백버퍼와 메인버퍼 사이에 랜더링 할 함수를 삽입 ) ****************** 중요 ********************
	

	for (int i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}


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
	TheInputHandler::Instance()->update();
	
	//while 문을 이용하여 이벤트를 검사
	/*while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false; // false 전환을 통해 프로그램 종료
			break;
		default:
			break;
		}
	}*/
}
//window와 render 삭제후 완전종료
void Game::clean() {

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


