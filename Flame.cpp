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
	xval = 0;
	yval = 0;
	set = false;
}
Flame::~Flame() {
}
void Flame::ResetTime() {
	timeExist=20;
	
}
void Flame::Setposition(int x, int y) {
	dst0.x = x - 45;
	dst0.y = y - 45;
	xval = x;
	yval = y;
	
}
bool Flame::DestroyObj(const SDL_Rect& rec1) {
	SDL_Rect rec2 = { xval-45,yval,135,45 }, rec3 = { xval,yval-45,45,135 };
	if (CommonFuction::collision(rec1, rec2))return true;
	if (CommonFuction::collision(rec1, rec3))return true;
	return false;
}

//thoi gian ton tai
void Flame::Update() {
	if (timeExist > 0) {
		
		isShowing = true;
		Flame::Render();
		timeExist--;
		//std::cout << timeExist;
		
	}
	else {		
		//bien mat
		dst0.w = 0;
		dst0.h = 0;
		isShowing = false;
		
		
	}
}
void Flame::Render() {
	dst0.w = 135;
	dst0.h = 135;
	SDL_RenderCopy(Game::renderer, flameTexture[FLAME_DEFAULT], NULL, &dst0);

}
void Flame::free()
{
	for (int i = 0; i < FLAME_TOTAL; i++) {
		SDL_DestroyTexture(flameTexture[i]);
	}
}