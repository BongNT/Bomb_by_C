#ifndef OBJECT_H_
#define OBJECT_H_

#include"Game.h"


class Object{

public:
	bool death = false;
	bool canMove = true;//bien cho monster
	int timeToDeath = 15;
	int xval = 0;//gia tri toa do hien tai
	int yval = 0;
	SDL_Rect dst;

	Object();//gia tri toa do dau vao //vi tri ban dau do minh nhap vao
	~Object();
	void free();
	void CreateObj(const char* somename, int x, int y, int w, int h);
	void LoadObjDeath(const char* somename);
	void ShowDeath();
	//cac ham thay doi vi tri hinh anh cua object
	void objSetSpeed(int val) { speed = val; }
	void objMoveUp( const char* fileUp);
	void objMoveDown( const char* fileDown);
	void objMoveLeft( const char* fileLeft);
	void objMoveRight( const char* fileRight);
	void objSetPosition();
	void objRender();
	void Disappear();
	//ham danh rieng cho monster:
	
	void AutoMove();
	void AutoChangeDirection(const SDL_Rect& bombRect);
	

private:
	SDL_Texture* objTexture = NULL;
	int speed;
	int direction;//1=up,2=down.3=left,4=right
};

#endif
