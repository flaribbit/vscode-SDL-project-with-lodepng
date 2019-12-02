#include "sprite.h"
#include "lodepng.h"
SDL_Renderer *renderer;

Sprite::Sprite(string file){
    int error=lodepng_decode32_file(&raw,&w,&h,file.c_str());
    if(error){
        printf("decoder error %u: %s\n", error, lodepng_error_text(error));
        return;
    }
    surface=SDL_CreateRGBSurfaceWithFormatFrom((void*)raw,w,h,32,4*w,SDL_PIXELFORMAT_RGBA32);
    if(!surface){
        printf("Creating surface failed: %s\n", SDL_GetError());
        return;
    }
    texture=SDL_CreateTextureFromSurface(renderer,surface);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
    free(raw);
}

void Sprite::Draw(int x,int y){
    SDL_Rect src={0,0,(int)w,(int)h},dst={x,y,(int)w,(int)h};
    SDL_RenderCopy(renderer,texture,&src,&dst);
}
