//Game.h���� ������ Ŭ������ ����(���)
#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else {
				return false; //������ ���� ����
			}

		}
		else {
			return false; //Window ���� ����
		}
	}
	else {
		return false; //SDL �ʱ�ȭ ����
	}
	m_bRunning = true; //true �� ���� �� ���� ������ ��ȯ
	return true;
}

void Game::update() {

}
//����
void Game::render() {
	SDL_RenderClear(m_pRenderer); //����� �׸���
	SDL_RenderPresent(m_pRenderer); // ���ι��� ���
}
//running �Լ��� ����Ǹ� ���� m_bRunning�� ���� ����
bool Game::running() {
	return m_bRunning;
}
//�������� ���α׷� ���Ḧ ���� �����ư ����
void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false; // false ��ȯ�� ���� ���α׷� ����
			break;
		default:
			break;
		}
	}
}
//window�� render ������ ��������
void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


