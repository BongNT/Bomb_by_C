
#include "Game.h"
#include "TextureManager.h"

SDL_Texture* backGroundText = NULL;
SDL_Texture* bomberUP = NULL;
SDL_Rect a = { 0,0,45,65 };
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height)
{
	

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "unable to init!" << std::endl;	
	}
	else 
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "unable to create window" << std::endl;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) 
			{
				std::cout << "unable to create renderer" << std::endl;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //trang
				
				backGroundText = TextureManager::LoadTexture(renderer,"Images/background_Play.png");

				/*tempSurface = IMG_Load("Images/bomber_up.png");
				bomberUP = SDL_CreateTextureFromSurface(renderer, tempSurface);
				SDL_FreeSurface(tempSurface);*/
			}

			isRunning = true;
		}
	}
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{	
	a.x = cnt;
	cnt++;
	std::cout << cnt << std::endl;
}

void Game::render()			//xep chong hinh anh duoi cung hien ra tren cung
{
	
	SDL_RenderClear(renderer);								
	SDL_RenderCopy(renderer, backGroundText, NULL, NULL);
	SDL_RenderCopy(renderer, bomberUP, NULL, &a);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}