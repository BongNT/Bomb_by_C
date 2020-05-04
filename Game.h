
#ifndef GAME_H_
#define GAME_H_
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>


class Game
{
public:
	int win;//0=game dang chay; 1=win; -1=lose;
	bool playAgain=true;
	bool playing = true;
	bool exiting = false;
	bool showMenu = true;
	Game();
	~Game();
	static SDL_Renderer* renderer ;
	
	void init(const char* title, int width, int height);
	void initGame();

	void initMenu();
	void updateMenu();
	void handleMenu();

	bool running() { return isRunning; }
	void autoDisplay();
	void handleEvents();

	void update();
	void render();
	void clean();
	void outgame();
	void showLoseOrWin();

private:
	
	bool isRunning = false;
	int frame = 0;
	int timeShowResult ;
	SDL_Window* window=NULL;
	
};
#endif