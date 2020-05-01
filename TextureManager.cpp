#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture( const char* name) {
	SDL_Texture* rTexture = NULL;
	SDL_Surface* tempSurface = IMG_Load(name);
	rTexture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (rTexture == NULL) {
		std::cout << "unable to create texture from surface !"<<SDL_GetError << std::endl;
	}
	SDL_FreeSurface(tempSurface);
	return rTexture;
}
bool CommonFuction::collision(const SDL_Rect& rec1, const SDL_Rect& rec2) {
	/*  A(x,y)----B(a,y)
		  |	       |
	    C(x,b)----D(a,b)    
			
	*/
	if (rec1.w == 0 && rec1.h == 0)return false;
	if (rec2.w == 0 && rec2.h == 0)return false;

	int x1 = rec1.x;
	int a1 = x1 + rec1.w;
	int y1 = rec1.y;
	int b1 = y1 + rec1.h;

	int x2 = rec2.x;
	int a2 = x2 + rec2.w;
	int y2 = rec2.y;
	int b2 = y2 + rec2.h;
	if (rec1.h == 65 ) {
		y1 += 20;	
	}
	if (rec2.h == 65) {
		y2 += 20;
		
	}

	//TH: rec1 < rec2
	if (a1 < a2 && a1 > x2) {
		if (b1 > y2 && b1 < b2) {//1
			return true;
		}
		if (y1 > y2 && y1 < b2) {//3
			return true;
		}
	}
	if (x1 > x2 && x1 < a2) {
		if (b1 > y2 && b1 < b2) {//2
			return true;
		}
		if (y1 < b2 && y1 > y2) {
			return true;
		}
	}
	//TH:rec1 > rec2
	if (a2 < a1 && a2 > x1) {
		if (b2 > y1 && b2 < b1) {//1
			return true;
		}
		if (y2 > y1 && y2 < b1) {//3
			return true;
		}
	}
	if (x2 > x1 && x2 < a1) {
		if (b2 > y1 && b2 < b1) {//2
			return true;
		}
		if (y2 < b1 && y2 > y1) {
			return true;
		}
	}
	//TH:rec1 = rec2
	if (x1 == x2 && a1 == a2 && y1 == y2)return true;
	if (x1 == x2 && a1 == a2) {
		if (y1 < y2 && rec1.h + rec2.h-40 > b2 - y1)return true;
		if (y1 > y2 && rec1.h + rec2.h - 40 > b1 - y2)return true;
	}
	if (y1 == y2 && b1 == b2) {
		if (x1<x2 && rec1.w + rec2.w>a2 - x1)return true;
		if (x1>x2 && rec1.w + rec2.w>a1 - x2)return true;
	}
	return false;
}

bool CommonFuction::checkMouse(const int& x, const int& y, const SDL_Rect& rec)
{
	if (x >= rec.x && x <= rec.x + rec.w && y >= rec.y && y <= rec.y + rec.h) {
		return true;
	}
	return false;
}


