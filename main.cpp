#include "Game.h"
#include "TextureManager.h"

const int SCREEN_WIDTH = 630;
const int SCREEN_HEIGHT = 495;
const int fps = 60;
const int framedelay = 1000 / fps;

Game* game = NULL;
int main(int argc, char* argv[])
{
	game = new Game();
	game->init(" BOOM! ", SCREEN_WIDTH, SCREEN_HEIGHT);

	
	int frameStart;
	int frametime;

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->autoDisplay();
		game->handleEvents();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - frameStart;//miliseconds
		if (framedelay - frametime > 0) {
			SDL_Delay(framedelay - frametime);
		}
	}

	game->clean();
	return 0;
}