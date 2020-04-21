#ifndef OBJECT_H_
#define OBJECT_H_

#include"Game.h"


class Object{

public:
	int xval = 0;//gia tri toa do hien tai
	int yval = 0;

	Object( const char* somename, int x, int y, int w, int h);//gia tri toa do dau vao //vi tri ban dau do minh nhap vao
	~Object();

	//cac ham thay doi vi tri hinh anh cua object
	
	void objMoveUp( const char* fileUp);
	void objMoveDown( const char* fileDown);
	void objMoveLeft( const char* fileLeft);
	void objMoveRight( const char* fileRight);

	void objSetPosition();
	void objRender();
	//ham danh rieng cho monster:
	void AutoMove();

private:
	SDL_Texture* objTexture = NULL;
	SDL_Rect dst;
	int speed = 15;
	int direction;//1=up,2=down.3=left,4=right
};

#endif
