
#ifndef GAME_H_
#define GAME_H_
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>


class Game
{
public:
	Game();
	~Game();
	static SDL_Renderer* renderer ;
	void autoDisplay();
	void init(const char* title, int width, int height);
	bool running() { return isRunning; }
	void handleEvents();
	void update();
	void render();
	void clean();
	

private:
	bool isRunning = false;
	int frame = 0;
	SDL_Window* window=NULL;
	
};
#endif