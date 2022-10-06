#include "SDL.h"
#pragma once
class TextureManager {
public:
	TextureManager() {}
	~TextureManager(){}


	//load(이미지 파일 이름 , 해당 텍스쳐 별명(id) , 해당 텍스쳐를 띄울 랜더러)
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	//draw(그리고 싶은 텍스쳐 별명(id) , 화면의 위치 , 텍스쳐 크기 , 랜더러 , 이미지 옵션)
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawFrame(그리고 싶은 텍스쳐 별명(id) , 화면의 위치 , 텍스쳐 크기,시트의 행(row) , 나타낼 프레임 , 랜더러 , 이미지 옵션)
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
	


	std::map<std::string, SDL_Texture*> m_textureMap;
};
