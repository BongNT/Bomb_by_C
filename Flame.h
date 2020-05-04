#ifndef FLAME_H_
#define FLAME_H_

#include"Game.h"

class Flame {

public:
	bool set ;
	int timeExist = 20;
	Flame();
	~Flame();
	bool isShowing = false;
	void ResetTime();
	bool DestroyObj(const SDL_Rect& rec1);
	void Update();
	void Render();
	void Setposition(int x, int y);
	void free();
	
private:
	int bombLength = 1;
	
	SDL_Rect dst0;
	int xval, yval;
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
