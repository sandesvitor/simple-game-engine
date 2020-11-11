#pragma once
#include "libs/SDL2/SDL.h"
#include "libs/SDL2/SDL_image.h"

class TextureManager
{
    public:
        static SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer* renderer);

        static void Draw(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest);
};