#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include "Game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture( const char* name);

};

//ham su li va cham
namespace CommonFuction
{
	bool collision(const SDL_Rect& rec1, const SDL_Rect& rec2);
	bool checkMouse(const int& x, const int& y,const SDL_Rect& rec);

}

#endif
