#include "Game.h"
#include "TextureManager.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 672;
const int fps = 60;
const int framedelay = 1000 / fps;

Game* game = NULL;
int main(int argc, char* argv[])
{
	game = new Game();
	game->init(" BOOM! By Nguyen Thanh Bong ", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	
	while (game->playAgain) {
		game->playAgain = false;
		game->showMenu = true;
		game->initMenu();
		while (game->showMenu) {
			game->updateMenu();
			game->handleMenu();

		}

		if (game->exiting == false)
		{
			
			game->initGame();
			int frameStart;
			int frametime;
			
			while (game->running())
			{
				frameStart = SDL_GetTicks();

				game->autoDisplay();
				game->handleEvents();
				game->update();
				game->render();

				if(game->win != 0)game->showLoseOrWin();
				frametime = SDL_GetTicks() - frameStart;//miliseconds
				if (framedelay - frametime > 0) {
					SDL_Delay(framedelay - frametime);
				}
			}
			
			
			game->clean();
		}
	}
	
	
	game->outgame();

	
	return 0;
}