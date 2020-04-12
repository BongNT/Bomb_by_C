#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* someRender, const char* name) {
	SDL_Texture* rTexture = NULL;
	SDL_Surface* tempSurface = IMG_Load(name);
	rTexture = SDL_CreateTextureFromSurface(someRender, tempSurface);
	if (rTexture == NULL) {
		std::cout << "unable to create texture from surface !" << std::endl;
	}
	SDL_FreeSurface(tempSurface);
	return rTexture;
}