#ifndef BOMB_H_
#define BOMB_H_
#include"Flame.h"
#include"Game.h"

class Bomb {

public:
    
    int timeToExplode;
    SDL_Rect dst;
    bool set ;

    Bomb();
    ~Bomb();

    void BombSetPosition(int x, int y);
    void ResetTime();
    void Update();
    void Render();
    bool Exploded() {
        return checkExplode;
        //no thi true, chua no thi false
    };
    void BombExplode();
    void free();


private:
    
    bool checkExplode = false;
    
    SDL_Texture* bombTexture = NULL;
    
    

};

#endif