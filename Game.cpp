
#include "Game.h"
#include "TextureManager.h"
#include"Object.h"
#include"Bomb.h"
#include"Flame.h"

SDL_Renderer* Game::renderer = NULL;
SDL_Texture* backGroundText = NULL;
Object* player = NULL;
Bomb* bomb=NULL;
Flame* bombBang = NULL;
Object* monster = NULL;
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
				
				backGroundText = TextureManager::LoadTexture("Images/background_Play.png");
				player = new Object( "Images/bomber_down.png", 0, 0, 45, 65);
				monster = new Object("Images/monster_right.png", 45, 45, 45, 65);
				
			}

			isRunning = true;
		}
	}
}

void Game::autoDisplay() {
	monster->Object::AutoMove();
}
void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) 
	{

		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}
		else if(event.type == SDL_KEYDOWN )
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
				{
					player->Object::objMoveUp( "Images/bomber_up.png");
					
					break;
				}
				case SDLK_DOWN:
				{
					player->Object::objMoveDown( "Images/bomber_down.png");
					
					break;
				}
				case SDLK_LEFT:
				{
					player->Object::objMoveLeft( "Images/bomber_left.png");
					
					break;
				}
				case SDLK_RIGHT:
				{
					player->Object::objMoveRight( "Images/bomber_right.png");
					
					break;
				}
				case SDLK_SPACE:
				{	
					//xu li bomb,flame
					if (bomb == NULL) {
						bomb = new Bomb();
						bombBang = new Flame();
					}
					if (bomb != NULL) {
						bomb->Bomb::BombSetPosition(player->xval, (player->yval) + 20);
						bombBang->Flame::Setposition(player->xval, (player->yval) + 20);
						bomb->Bomb::ResetTime();
						bombBang->Flame::ResetTime();
					}

					break;
				}
			}
		}
	}

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
	monster->objSetPosition();
	player->objSetPosition();
	frame++;
	//std::cout << frame << std::endl;
}

void Game::render()			//xep chong hinh anh duoi cung hien ra tren cung
{
	
	SDL_RenderClear(renderer);								
	SDL_RenderCopy(renderer, backGroundText, NULL, NULL);

	monster->objRender();
	if (bomb != NULL) {
		bomb->Bomb::Update();
		if (bomb->Bomb::Exploded()) {
			bombBang->Flame::Update();

		}
	}
	player->objRender();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	delete player;
	delete bombBang;
	delete bomb;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}