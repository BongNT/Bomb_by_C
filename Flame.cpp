#include"Game.h"
#include"TextureManager.h"
#include"Flame.h"

Flame::Flame() {
	flameTexture[FLAME_DEFAULT] = TextureManager::LoadTexture("Images/bombbang.png");
	dst0.w = 135;
	dst0.h = 135;
	flameTexture[FLAME_UP] = TextureManager::LoadTexture("Images/bombbang_up_1.png");
	flameTexture[FLAME_DOWN] = TextureManager::LoadTexture("Images/bombbang_down_1.png");
	flameTexture[FLAME_LEFT] = TextureManager::LoadTexture("Images/bombbang_left_1.png");
	flameTexture[FLAME_RIGHT] = TextureManager::LoadTexture("Images/bombbang_right_1.png");
}
Flame::~Flame() {
	for (int i = 0; i < FLAME_RIGHT; i++) {
		SDL_DestroyTexture(flameTexture[i]);
	}
}
void Flame::ResetTime() {
	timeExist=20;
	/*dst0.w = 0;
	dst0.h = 0;*/
}
void Flame::Setposition(int x, int y) {
	dst0.x = x - 45;
	dst0.y = y - 45;
	
}
void Flame::Update() {
	if (timeExist > 0) {
		
		
		Flame::Render();
		timeExist--;
		std::cout << timeExist;
		//std::cout << "X"<<timeExist;
	}
	else {		//bien mat
		dst0.w = 0;
		dst0.h = 0;
		//timeExist = 20;
		//std::cout << "Y";
	}
}
void Flame::Render() {
	dst0.w = 135;
	dst0.h = 135;
	SDL_RenderCopy(Game::renderer, flameTexture[FLAME_DEFAULT], NULL, &dst0);

}