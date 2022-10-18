#include "TextureManager.h"

//멤버 변수는 모든 객체가 공유하고 프로그램 전체 영역에서 메모리 유지가 되어야 하기 때문에 전역 범위에서 초기화를 해 주어야 함
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
	
	

	//파일 입출력 예외처리
	SDL_Surface* psurface = IMG_Load(fileName.c_str());
	if (psurface == nullptr) {
		return EXIT_FAILURE;
	}

	SDL_Texture* ptexture = SDL_CreateTextureFromSurface(pRenderer, psurface);
	//Surface 에 값이 있으면 Map 에 ID 저장

	SDL_FreeSurface(psurface); //사용한 Surface 메모리 해제

	if (ptexture != nullptr) {
		m_textureMap[id] = ptexture;
		return true;
	}
	//강제종료
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	
	//원본상자 , 대상상자 크기와 위치 
	srcRect.x = 0; 
	srcRect.y = 0;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x; 
	dstRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}

// TextureMap 지우기
void TextureManager::clearTextureMap(std::string id) {
	m_textureMap.erase(id);
}