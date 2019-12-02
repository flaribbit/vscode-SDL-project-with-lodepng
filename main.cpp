#include <stdio.h>
#include <SDL.h>
#include "lodepng.h"

SDL_Surface *LoadPNG(char *file){
    unsigned char *image;
    unsigned width,height;
    SDL_Surface *surface;
    int error=lodepng_decode32_file(&image,&width,&height,file);
    if(error){
        printf("decoder error %u: %s\n", error, lodepng_error_text(error));
        return 0;
    }
    surface=SDL_CreateRGBSurfaceFrom((void*)image,width,height,32,4*width,0x000000ff,0x0000ff00,0x00ff0000,0xff000000);
    free(image);
    if(!surface){
        printf("Creating surface failed: %s\n", SDL_GetError());
        return 0;
    }
    return surface;
}

int WinMain(int argc, char *argv[])
{
    SDL_Window *window=SDL_CreateWindow("demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    bool quit=false;
    SDL_Event event;
    SDL_Point point;
    SDL_Surface *imgsurf=LoadPNG((char*)"test.png");
    SDL_Texture *imgtext=SDL_CreateTextureFromSurface(renderer,imgsurf);
    SDL_Rect src,dst;
    src={x:0,y:0,w:imgsurf->w,h:imgsurf->h};
    dst={x:0,y:0,w:src.w,h:src.h};
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    while(!quit){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,imgtext,&src,&dst);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    quit=true;
                    break;
                case SDL_MOUSEMOTION:
                    //SDL_RenderDrawLine(renderer,point.x,point.y,event.motion.x,event.motion.y);
                    dst.x=point.x=event.motion.x;
                    dst.y=point.y=event.motion.y;
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
