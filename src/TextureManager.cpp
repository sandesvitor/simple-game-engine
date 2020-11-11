#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filePath, SDL_Renderer* renderer)
{
    SDL_Surface* tmpSurface = IMG_Load(filePath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return texture;
}

void TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest)
{
    SDL_RenderCopy(renderer, texture, &src, &dest);
}