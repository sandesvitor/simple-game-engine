/*
    AABB ==> Axis Alligned Binding Box
    
    Checks if "x" and "y" of 2 or more objects, are overlapping:
        
        Checks for collision:
        
        - Ax + Aw >= B.x
            - Bx + Bw >= Ax
                - Ay + Ah >= By
                    - By + Bh >= Ay
*/


#pragma once

#include <string>
#include "libs/SDL2/SDL.h"
#include "ECS.hpp"
#include "Components.hpp"

class Collider : public Component
{
    public:

        SDL_Renderer *renderer;
        SDL_Rect collider;
        std::string tag;
        Transform *transform;
        
        // desenhar o box collider para Debugar:
        bool isDebugDrawActive;
        
        Collider(){}
        
        Collider(std::string tag, SDL_Renderer* renderer){
            this->tag = tag;
            this->renderer = renderer;
            
            this->isDebugDrawActive = false;
        }

        void init() override {
            // GAMBIARRA PRA INSERIR O TRANSFORM COMO PRIMEIRO COMPONENTE!
            if(!gameObject->hasComponent<Transform>()){
                gameObject->addComponent<Transform>();
            }
            transform = &gameObject->getComponent<Transform>();
        }

        void update() override {
            this->collider.x = this->transform->position->x;
            this->collider.y = this->transform->position->y;
            this->collider.w = this->transform->width * this->transform->scale->x;
            this->collider.h = this->transform->height * this->transform->scale->y;
        }

        void draw() override {
            if(this->isDebugDrawActive){
                // desenhar rect do Collider
                SDL_SetRenderDrawColor(this->renderer, 255,255,255,255);
                SDL_RenderDrawRect(this->renderer, &(this->collider));
                SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
            }
        }

        ~Collider(){
            std::cout 
                << "[Collider] Component Destroyed - " 
                << gameObject->name 
                << " Game Object" 
            <<std::endl;
        }
};