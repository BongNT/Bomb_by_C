#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace std;
const int WEIGHT_SCREEN=600;
const int HEIGHT_SCREEN=600;
const char* TITLE_WINDOW="BOOM!";
enum KeyPress{
    KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_SPACE,
	KEY_PRESS_TOTAL
};

struct character{
    int x;
    int y;
    const int size=40;
    int speed=1;
    //them 1 ham dat boom

    void directionCharacter(){

    }
};
SDL_Window *gWindow=NULL;
SDL_Surface *gScreenSurface=NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface *gKeyPressSurfaces[ KEY_PRESS_TOTAL ];//dieu khien di chuyen
SDL_Surface *gPNGSurface = NULL;     //anh hien thi hien tai

SDL_Surface* loadSurface( std::string path ){
    SDL_Surface *optimizedSurface=NULL;
    SDL_Surface *LoadSurface=IMG_Load(path.c_str());
    if(LoadSurface==NULL){
        std::cout<<"Unable to load image %s! SDL_image Error: "<<IMG_GetError()<<endl;
    }
    else{
        optimizedSurface=SDL_ConvertSurface(LoadSurface,gScreenSurface->format,0);
    }
    SDL_FreeSurface(LoadSurface);
    return optimizedSurface;
}

bool init(){
    bool success=true;
    if(SDL_Init(SDL_INIT_AUDIO)<0){
        std::cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<endl;
        success=false;
    }
    else
    {
        gWindow = SDL_CreateWindow(TITLE_WINDOW,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WEIGHT_SCREEN,HEIGHT_SCREEN,SDL_WINDOW_SHOWN);
        if(gWindow==NULL){
            std::cout<<"Window could not be created! SDL Error: "<<SDL_GetError()<<endl;
            success=false;
        }
        else
        {
            int imgFlags = IMG_INIT_PNG;
            			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				std::cout<< "SDL_image could not initialize! SDL_image Error: "<< IMG_GetError() <<endl;
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
        }
    }
    return success;
}
bool loadMedia(){

    bool success = true;
    gKeyPressSurfaces[KEY_PRESS_UP] = loadSurface("Images/bomber_up.png");
    if(gKeyPressSurfaces[KEY_PRESS_UP] == NULL){
        std::cout<<"Failed to load up image!"<<endl;
    }
    gKeyPressSurfaces[KEY_PRESS_DOWN] = loadSurface("Images/bomber_down.png");
    if(gKeyPressSurfaces[KEY_PRESS_DOWN] == NULL){
        std::cout<<"Failed to load down image!"<<endl;
    }
    gKeyPressSurfaces[KEY_PRESS_LEFT] = loadSurface("Images/bomber_left.png");
    if(gKeyPressSurfaces[KEY_PRESS_LEFT] == NULL){
        std::cout<<"Failed to load left image!"<<endl;
    }
    gKeyPressSurfaces[KEY_PRESS_RIGHT] = loadSurface("Images/bomber_right.png");
    if(gKeyPressSurfaces[KEY_PRESS_RIGHT] == NULL){
        std::cout<<"Failed to load right image!"<<endl;
    }
    gKeyPressSurfaces[KEY_PRESS_SPACE]=loadSurface("Images/bomb.png");
    if(gKeyPressSurfaces[KEY_PRESS_SPACE]==NULL){
        std::cout<<"Failed to load space(boom) image!"<<endl;
    }
    return success;
}
void close(){
    for( int i = 0; i < KEY_PRESS_TOTAL; i++ ){
        SDL_FreeSurface( gKeyPressSurfaces[i] );
        gKeyPressSurfaces[i] = NULL;
    }
    SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;
}

void moveRight(int &x,int &y){
    x+=40;
}
void moveLeft(int &x,int &y){
    x-=40;
}
void moveUp(int &x,int &y){
    y-=40;
}
void moveDown(int &x,int &y){
    y+=40;
}
int main( int argc, char* args[] ){
    if( !init() ){
        std::cout<<"Failed to initialize!"<<endl;
    }
    else{
        if( !loadMedia() )
		{
			std::cout<<"Failed to load media!"<<endl;
		}
		else
        {
            SDL_Event e;
            bool quit =false;
            SDL_Rect boomer;
                boomer.x=0;
                boomer.y=0;
                boomer.h=40;
                boomer.w=40;
            while(!quit){
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT ){
                        quit=true;
                    }
                    else if( e.type == SDL_KEYDOWN ){
                        switch(e.key.keysym.sym){
                            case SDLK_UP :
                            {
                                gCurrentSurface=gKeyPressSurfaces[KEY_PRESS_UP];
                                moveUp(boomer.x,boomer.y);
                                break;

                            }
                            case SDLK_DOWN :
                            {
                                gCurrentSurface=gKeyPressSurfaces[KEY_PRESS_DOWN];
                                moveDown(boomer.x,boomer.y);
                                break;
                            }
                            case SDLK_LEFT :
                            {
                                gCurrentSurface=gKeyPressSurfaces[KEY_PRESS_LEFT];
                                break;
                            }
                            case SDLK_RIGHT :
                            {
                                gCurrentSurface=gKeyPressSurfaces[KEY_PRESS_RIGHT];
                                break;
                            }
                            case SDLK_SPACE :
                            {
                                gCurrentSurface=gKeyPressSurfaces[KEY_PRESS_SPACE];
                                break;
                                //in ra boom
                            }
                            default:
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_DEFAULT ];
							break;
                        }

                    }
                }


                SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, &boomer );

				SDL_UpdateWindowSurface( gWindow );

            }
		}
    }
    close();
    return 0;
}

