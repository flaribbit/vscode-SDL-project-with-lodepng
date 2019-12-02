#include <stdio.h>
#include <SDL.h>
#include "sprite.h"

extern SDL_Renderer *renderer;

int WinMain(int argc, char *argv[])
{
    SDL_Window *window=SDL_CreateWindow("demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    bool quit=false;
    SDL_Event event;
    SDL_Point point;
    Sprite img("test_alpha.png");
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    while(!quit){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        img.Draw(point.x,point.y);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    quit=true;
                    break;
                case SDL_MOUSEMOTION:
                    SDL_RenderDrawLine(renderer,point.x,point.y,event.motion.x,event.motion.y);
                    point.x=event.motion.x;
                    point.y=event.motion.y;
                    break;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
