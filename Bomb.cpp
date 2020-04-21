#include"Bomb.h"
#include "TextureManager.h"
#include"Game.h"
#include"Flame.h"

Bomb::~Bomb() {
	SDL_DestroyTexture(bombTexture);
}

Bomb::Bomb() {
	bombTexture = TextureManager::LoadTexture("Images/bomb.png");
	
	dst.w = 0;
	dst.h = 0;

}


void Bomb::BombSetPosition(int x, int y) {
	dst.x = x;
	dst.y = y;
	/*dst.w = 45;
	dst.h = 45;*/
}
void Bomb::ResetTime() {
	timeToExplode = 120;
	/*dst.w = 0;
	dst.h = 0;*/
}
void Bomb::Update( ) {
	
	if (timeToExplode > 0) {
		if (timeToExplode == 120)checkExplode = false;
		dst.w = 45;
		dst.h = 45;
		Bomb::Render();
		timeToExplode--;
		
	}
	else {
		dst.w = 0;//bomb bien mat
		dst.h = 0;
		checkExplode = true;
	}

}
void Bomb::Render() {
	SDL_RenderCopy(Game::renderer, bombTexture, NULL, &dst);
}