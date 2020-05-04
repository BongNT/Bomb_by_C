#include"Bomb.h"
#include "TextureManager.h"
#include"Game.h"
#include"Flame.h"
const int time = 120;
Bomb::~Bomb() {
}

Bomb::Bomb() {
	bombTexture = TextureManager::LoadTexture("Images/bomb.png");
	timeToExplode = time;
	dst.w = 0;
	dst.h = 0;
	set = false;
}


void Bomb::BombSetPosition(int x, int y) {
	dst.x = x;
	dst.y = y;
	
}
void Bomb::ResetTime() {
	timeToExplode = time;
	
}
void Bomb::BombExplode() {
	timeToExplode = 0;
	dst.w = 0;//bomb bien mat
	dst.h = 0;
	checkExplode = true;
}
void Bomb::Update( ) {
	
	if (timeToExplode > 0) {
		if (timeToExplode == time)checkExplode = false;
		dst.w = 45;
		dst.h = 45;
		
		timeToExplode--;
		
	}
	else {
		BombExplode();
	}

}
void Bomb::Render() {
	SDL_RenderCopy(Game::renderer, bombTexture, NULL, &dst);
}
void Bomb::free() {
	SDL_DestroyTexture(bombTexture);
}