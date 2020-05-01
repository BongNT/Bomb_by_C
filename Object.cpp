#include "Object.h"
#include"TextureManager.h"

const int SCREEN_WIDTH = 675;
const int SCREEN_HEIGHT = 725;

Object::Object() {
	direction = 4;
	xval = 0;
	yval = 0;
	speed = 0;
	dst = { 0,0,0,0 };
}
Object::~Object(){
}
void Object::free()
{
	SDL_DestroyTexture(Object::objTexture);
}
void Object::CreateObj(const char* somename, int x, int y, int w, int h) {
	
	objTexture = TextureManager::LoadTexture(somename);
	xval = x;
	yval = y;
	dst.w = w;
	dst.h = h;
}
void Object::LoadObjDeath(const char* somename) {
	SDL_DestroyTexture(objTexture);
	objTexture = TextureManager::LoadTexture(somename);
	
}
void Object::ShowDeath() {
	if (timeToDeath > 0)timeToDeath--;
	else {
		death = true;
	}
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
	/*	
		1
	3	+	4
		2
	*/

	Object::objSetSpeed(3);
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
void Object::AutoChangeDirection(const SDL_Rect& bombRect) {
	if (bombRect.w != 0 && bombRect.h != 0) {
		if (bombRect.y < dst.y + dst.h && bombRect.y >= dst.y) {
			if (direction == 4 && dst.x + dst.w + speed > bombRect.x && dst.x + dst.w <= bombRect.x) {
				direction = 3;
			}
			if (direction == 3 && dst.x + speed > bombRect.x + bombRect.w && dst.x <= bombRect.x + bombRect.w) {
				direction = 4;
			}
		}
		
		
	}
}
void Object::Disappear() {
	dst = { 0,0,0,0 };
}
