#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include "Game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(SDL_Renderer* someRender, const char* name);

};

#endif
