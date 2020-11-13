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

        SDL_Rect collider;
        std::string tag;
        Transform *transform;
        
        Collider(){}
        
        Collider(std::string tag){
            this->tag = tag;
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
            this->collider.y = this->transform->position->x;
            this->collider.w = this->transform->width * this->transform->scale->x;
            this->collider.h = this->transform->height * this->transform->scale->y;
        }

        ~Collider(){
            std::cout 
                << "[Collider] Component Destroyed - " 
                << gameObject->name 
                << " Game Object" 
            <<std::endl;
        }
};