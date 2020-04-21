#ifndef BOMB_H_
#define BOMB_H_
#include"Flame.h"
#include"Game.h"

class Bomb {

public:
    /*int xval;
    int yval;*/
    
    Bomb();
    ~Bomb();
    void BombSetPosition(int x, int y);
    void ResetTime();
    void Update();
    void Render(/*int x, int y*/);
    bool Exploded() {
        return checkExplode;
        //else return false;
    };


private:
    int timeToExplode = 120;
    bool checkExplode = false;
    
    SDL_Texture* bombTexture = NULL;
    SDL_Rect dst;
    SDL_Rect src={ 0,0,45,45 };

};

#endif