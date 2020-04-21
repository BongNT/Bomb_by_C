#include "Object.h"
#include"TextureManager.h"

const int SCREEN_WIDTH = 630;
const int SCREEN_HEIGHT = 495;

Object::Object( const char* somename,int x,int y,int w,int h) {
	direction = 4;
	objTexture = TextureManager::LoadTexture( somename);
	xval = x;		
	yval = y;
	dst.w = w;
	dst.h = h;
}
Object::~Object(){
	SDL_DestroyTexture(Object::objTexture);
}
void Object::objMoveUp(const char* fileUp) {
	if (yval  > 0) yval -= speed;
	SDL_DestroyTexture(Object::objTexture);
	Object::objTexture = TextureManager::LoadTexture( fileUp);
}
void Object::objMoveDown( const char* fileDown) {
	if ( yval + dst.h < SCREEN_HEIGHT ) yval += speed;
	SDL_DestroyTexture(Object::objTexture);
	Object::objTexture = TextureManager::LoadTexture( fileDown);
}
void Object::objMoveLeft( const char* fileLeft) {
	if (xval > 0)xval -= speed;
	SDL_DestroyTexture(Object::objTexture);
	Object::objTexture = TextureManager::LoadTexture( fileLeft);
}
void Object::objMoveRight( const char* fileRight) {
	if (xval + dst.w < SCREEN_WIDTH)xval += speed;
	SDL_DestroyTexture(Object::objTexture);
	Object::objTexture = TextureManager::LoadTexture( fileRight);
}
void Object::objSetPosition() {
	dst.x = xval;	//vi tri sau khi di chuyen
	dst.y = yval;	

}

void Object::objRender() {
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &dst);
}

void Object::AutoMove() {
	speed = 3;
	if (xval == 0 ) {
		direction = 4;
	}
	if (xval + dst.w == SCREEN_WIDTH) {
		
		direction = 3;
	}
	if (direction==4) {
		Object::objMoveRight("Images/monster_right.png"); 
	}
	else if (direction == 3) {
		Object::objMoveLeft("Images/monster_left.png");
	}
}