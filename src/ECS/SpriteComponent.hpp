#pragma once

#include "../TextureManager.hpp"
#include "Components.hpp"
#include "libs/SDL2/SDL.h"

class Sprite : public Component
{
    private:
        Transform *transform;
        SDL_Texture *texture;
        SDL_Renderer *renderer;

        SDL_Rect srcRect, destRect;

    public:
        Sprite() = default;
        Sprite(const char* filePath, SDL_Renderer* renderer){
            this->renderer = renderer;
            this->texture = TextureManager::LoadTexture(filePath, this->renderer);
        }

        void init() override
        {
            this->transform = &gameObject->getComponent<Transform>();

            srcRect.x = srcRect.y = 0;
            srcRect.w = srcRect.h = 32;
            destRect.w = destRect.h = 32 * 2;
            destRect.x = this->transform->position->x;
            destRect.y = this->transform->position->y;
        }

        void update() override
        {
            destRect.x = this->transform->position->x;
            destRect.y = this->transform->position->y;
        }

        void draw() override
        {
            TextureManager::Draw(this->renderer, this->texture, this->srcRect, this->destRect);
        }

        ~Sprite(){
            std::cout << "[Sprite] Component Destroyed" << std::endl;
        }
};
