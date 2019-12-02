#include "SDL.h"
#include <iostream>
using namespace std;
extern SDL_Renderer *renderer;

class Sprite
{
private:
    unsigned int w,h;
    unsigned char *raw;
    SDL_Surface *surface;
    SDL_Texture *texture;
public:
    Sprite(string file);
    ~Sprite();
    void Draw(int x,int y);
};
