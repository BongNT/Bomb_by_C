
#include "Game.h"
#include "TextureManager.h"
#include"Object.h"
#include"Bomb.h"
#include"Flame.h"
#include<vector>

SDL_Renderer* Game::renderer = NULL;

SDL_Texture* backGroundText = NULL;
SDL_Texture* playButton=NULL;
SDL_Texture* exitButton=NULL;
int xmouse = 0;
int ymouse = 0;
SDL_Rect playRec;
SDL_Rect exitRec;

Object* player = NULL;
std::vector<Object*>listMonster;
std::vector<Bomb*>listBomb;
std::vector<Flame*>listFlame;
void MakeListMonster() {
	
	int numberMonster = 5;
	Object* tempMonster = new Object[numberMonster];
	for (int i = 0; i < numberMonster; i++) {
		Object* pMonster = (tempMonster + i);
		pMonster->CreateObj("Images/monster_right.png", 0, 150 * (i), 45, 65);
		listMonster.push_back(pMonster);
	}
	
}
void MakeListBomb() {
	int numberBomb = 3;
	Flame* tempFlame = new Flame[numberBomb];
	Bomb* tempBomb = new Bomb[numberBomb];
	for (int i = 0; i < numberBomb; i++) {
		Bomb* pBomb = (tempBomb + i);
		listBomb.push_back(pBomb);
		Flame* pFlame = (tempFlame + i);
		listFlame.push_back(pFlame);
	}
}


Game::Game()
{	
	win = 0;
	timeShowResult = 120;
}

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
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
				
			}
			
			isRunning = true;
		}
	}
}

void Game::initGame()
{	
	if (backGroundText != NULL)SDL_DestroyTexture(backGroundText);
	backGroundText = TextureManager::LoadTexture("Images/background_Play.png");
	player = new Object();
	player->CreateObj("Images/bomber_down.png", 450, 205, 45, 65);
	player->Object::objSetSpeed(20);
	isRunning = true;
	timeShowResult = 120;
	win = 0;

	MakeListMonster();
	MakeListBomb();
}
void Game::initMenu() {
	if (backGroundText != NULL)SDL_DestroyTexture(backGroundText);
	backGroundText = TextureManager::LoadTexture("Images/background_Menu.png");
	if (playButton != NULL)SDL_DestroyTexture(playButton);
	playButton = TextureManager::LoadTexture("Images/Play.png");
	if (exitButton != NULL)SDL_DestroyTexture(exitButton);
	exitButton= TextureManager::LoadTexture("Images/Exit.png");
	playRec = { 500,250,200,55 };
	exitRec = { 500,350,200,55 };
	exiting = false;
}

void Game::updateMenu()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backGroundText, NULL, NULL);
	SDL_RenderCopy(renderer, playButton, NULL, &playRec);
	SDL_RenderCopy(renderer, exitButton, NULL, &exitRec);
	SDL_RenderPresent(renderer);
}

void Game::handleMenu()
{
	SDL_Event menuEvent;
	while (SDL_PollEvent(&menuEvent) != 0) {

		switch (menuEvent.type)
		{
		case SDL_QUIT:
		{
			isRunning = false;
			playAgain = false;
			showMenu = false;
			exiting = true;
			break;
		}
		case SDL_MOUSEMOTION:
		{
			xmouse = menuEvent.motion.x;
			ymouse = menuEvent.motion.y;
			if (CommonFuction::checkMouse(xmouse, ymouse, playRec)) {
				SDL_DestroyTexture(playButton);
				playButton = TextureManager::LoadTexture("Images/Play2.png");
			}
			else {
				SDL_DestroyTexture(playButton);
				playButton = TextureManager::LoadTexture("Images/Play.png");
			}
			if (CommonFuction::checkMouse(xmouse, ymouse, exitRec)) {
				SDL_DestroyTexture(exitButton);
				exitButton = TextureManager::LoadTexture("Images/Exit2.png");
			}
			else {
				SDL_DestroyTexture(exitButton);
				exitButton = TextureManager::LoadTexture("Images/Exit.png");
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			xmouse = menuEvent.motion.x;
			ymouse = menuEvent.motion.y;

			if (CommonFuction::checkMouse(xmouse, ymouse, playRec)) {
				SDL_DestroyTexture(playButton);
				playButton = TextureManager::LoadTexture("Images/Play2.png");
				exiting = false;
				showMenu = false;
			}
			if (CommonFuction::checkMouse(xmouse, ymouse, exitRec)) {
				SDL_DestroyTexture(exitButton);
				exitButton = TextureManager::LoadTexture("Images/Exit2.png");
				showMenu = false;
				exiting = true;
				
			}

		}
		default:
			break;
		}
	}

}

void Game::autoDisplay() {

	for (int i = 0; i < listMonster.size(); i++) {
		if (listMonster[i]->Object::canMove) {
			listMonster[i]->AutoMove();
		}
		for (int j = 0; j < listBomb.size(); j++) {
			if (listBomb[j]->set==true && listMonster[i] != NULL){
				listMonster[i]->Object::AutoChangeDirection(listBomb[j]->dst);

			}
		}
		
	}
	

}
void Game::handleEvents()
{
	SDL_Event event;

 	while (SDL_PollEvent(&event) != 0) 
	{

		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			playAgain = false;
			showMenu = false;
			exiting = true;
			

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
					
					
					for (int i = 0; i < listBomb.size(); i++) {
						
						if (listBomb[i]->set == false && listFlame[i]->set == false) {
							
							listBomb[i]->ResetTime();
							listFlame[i]->ResetTime();
							listBomb[i]->BombSetPosition(player->xval, (player->yval) + 20);
							listFlame[i]->Setposition(player->xval, (player->yval) + 20);
							listBomb[i]->set = true;
							listFlame[i]->set = true;
							break;

						}
						
					}
					break;
				}
			}
		}
	}

	
}

void Game::update()
{	//player chet
	if (player->canMove == false) {
		player->LoadObjDeath("Images/bomber_dead.png");
		player->ShowDeath();
		win = -1;
	}
	//monster va cham vs player
	for (int i = 0; i < listMonster.size(); i++) {
		listMonster[i]->objSetPosition();
		if (CommonFuction::collision(player->dst, listMonster[i]->dst)) {
			win = -1;
			
		}
	}
	//monster chet
	for (int i = 0; i < listMonster.size(); i++) {
		if (listMonster[i]->canMove == false) {
			listMonster[i]->LoadObjDeath("Images/ghost.png");
			listMonster[i]->ShowDeath();
		}
		if (listMonster[i]->death) {
			listMonster[i]->free();
			listMonster.erase(listMonster.begin() + i);
		}
	}
	player->objSetPosition();
	frame++;
	//std::cout << frame << std::endl;
}

void Game::render()			//xep chong hinh anh duoi cung hien ra tren cung
{
	
	SDL_RenderClear(renderer);								
	SDL_RenderCopy(renderer, backGroundText, NULL, NULL);
	//in ra monster
	for (int i = 0; i < listMonster.size(); i++) {
		listMonster[i]->objRender();
	}
	//in ra bomb va flame
	for (int j = 0; j < listBomb.size(); j++) {
		if (listBomb[j]->set==true) {
			listBomb[j]->Bomb::Update();
			listBomb[j]->Render();
			if (listBomb[j]->Bomb::Exploded()) 
			{//xu li bomb no
				listFlame[j]->Flame::Update();
				if (listFlame[j]->timeExist <= 0) {
					listBomb[j]->set = false;
					listFlame[j]->set = false;
				}
				//bomb vs monster
				for (int i = 0; i < listMonster.size(); i++) {
					if (listFlame[j]->Flame::isShowing && listFlame[j]->Flame::DestroyObj(listMonster[i]->dst)) {//va cham bomb va chet
						listMonster[i]->canMove = false;
					}
				}
				//flame vs bomb
				for (int i = j+1; i < listBomb.size(); i++) {
					if (listFlame[j]->Flame::isShowing && listFlame[j]->DestroyObj(listBomb[i]->dst)) {
						listBomb[i]->BombExplode();
					}
				}
				//bomb vs player
				if (listFlame[j]->Flame::isShowing && listFlame[j]->Flame::DestroyObj(player->dst)) {
					player->canMove = false;
					if (player->death == true) {
						win = -1;
						
						break;
						
					}
				}

			}
		}
	}
	//win(tieu diet het quai vat
	if (listMonster.size() == 0) {
		
		win = 1;
	}
	player->objRender();

	SDL_RenderPresent(renderer);
	
}

void Game::clean()
{
	for (int i = 0; i < listBomb.size(); i++) {
		listBomb[i]->free();
		listFlame[i]->free();
		
	}
	for (int i = 0; i < listMonster.size(); i++) {
		listMonster[i]->free();
		
	}
	listBomb.clear();
	listFlame.clear();
	listMonster.clear();
	delete player;
	
	
}
void Game::outgame() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::showLoseOrWin()
{
	
	if (win == -1) {
		SDL_DestroyTexture(backGroundText);
		backGroundText = TextureManager::LoadTexture("Images/lose.png");
		win = 2;
		if (timeShowResult > 0)timeShowResult--;
		else {
			isRunning = false;
			playAgain = true;
		}
	}
	else if(win == 1){
		SDL_DestroyTexture(backGroundText);
		backGroundText = TextureManager::LoadTexture("Images/win.png");
		win = 2;
	}
	if (timeShowResult > 0)timeShowResult--;
	else {
		isRunning = false;
		playAgain = true;
	}
}
