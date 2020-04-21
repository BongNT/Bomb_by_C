#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture( const char* name) {
	SDL_Texture* rTexture = NULL;
	SDL_Surface* tempSurface = IMG_Load(name);
	rTexture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (rTexture == NULL) {
		std::cout << "unable to create texture from surface !" << std::endl;
	}
	SDL_FreeSurface(tempSurface);
	return rTexture;
}