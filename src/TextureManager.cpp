#include "TextureManager.h"

//��� ������ ��� ��ü�� �����ϰ� ���α׷� ��ü �������� �޸� ������ �Ǿ�� �ϱ� ������ ���� �������� �ʱ�ȭ�� �� �־�� ��
TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
	
	

	//���� ����� ����ó��
	SDL_Surface* psurface = IMG_Load(fileName.c_str());
	if (psurface == nullptr) {
		return EXIT_FAILURE;
	}

	SDL_Texture* ptexture = SDL_CreateTextureFromSurface(pRenderer, psurface);
	//Surface �� ���� ������ Map �� ID ����

	SDL_FreeSurface(psurface); //����� Surface �޸� ����

	if (ptexture != nullptr) {
		m_textureMap[id] = ptexture;
		return true;
	}
	//��������
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	
	//�������� , ������ ũ��� ��ġ 
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

// TextureMap �����
void TextureManager::clearTextureMap(std::string id) {
	m_textureMap.erase(id);
}