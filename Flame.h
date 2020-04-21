#ifndef FLAME_H_
#define FLAME_H_

#include"Game.h"

class Flame {

public:
	
	Flame();
	~Flame();
	void ResetTime();
	void Update();
	void Render();
	void Setposition(int x, int y);
	void returnTimeExist();
private:
	int bombLength = 1;
	int timeExist = 20;
	SDL_Rect dst0;
	enum direction
	{
	FLAME_DEFAULT,
	FLAME_UP,
	FLAME_DOWN,
	FLAME_LEFT,
	FLAME_RIGHT,
	FLAME_TOTAL,
	};
	SDL_Texture* flameTexture[FLAME_TOTAL];
};

#endif
