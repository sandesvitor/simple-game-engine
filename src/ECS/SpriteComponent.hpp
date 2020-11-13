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
            // GAMBIARRA PRA INSERIR O TRANSFORM COMO PRIMEIRO COMPONENTE!
            if(!gameObject->hasComponent<Transform>()){
                gameObject->addComponent<Transform>();
            }

            
            this->transform = &gameObject->getComponent<Transform>();

            srcRect.x = this->transform->position->x;
            srcRect.y = this->transform->position->y;
            srcRect.w = this->transform->width;
            srcRect.h = this->transform->height;
            
            destRect.w = this->transform->width * this->transform->scale->x; 
            destRect.h = this->transform->height * this->transform->scale->y;
            destRect.x = this->transform->position->x;
            destRect.y = this->transform->position->y;
        }

        void update() override
        {
            destRect.x = this->transform->position->x;
            destRect.y = this->transform->position->y;
            destRect.w = 32 * this->transform->scale->x; 
            destRect.h = 32 * this->transform->scale->y;
        }

        void draw() override
        {
            TextureManager::Draw(this->renderer, this->texture, this->srcRect, this->destRect);
        }

        ~Sprite(){
            SDL_DestroyTexture(this->texture);

            std::cout 
                << "[Sprite] Component Destroyed - " 
                << gameObject->name 
                << " Game Object" 
            <<std::endl;
        }
};
