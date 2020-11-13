#pragma once

#include "ECS.hpp"
#include "Components.hpp"
#include "../Game.hpp"

class KeyboardController : public Component
{
    public:
        Transform *transform;

        void init() override {
            // GAMBIARRA PRA INSERIR O TRANSFORM COMO PRIMEIRO COMPONENTE!
            if(!gameObject->hasComponent<Transform>()){
                gameObject->addComponent<Transform>();
            }
            
            this->transform = &gameObject->getComponent<Transform>();
        }      

        void update() override {
            
            if(Game::event.type == SDL_KEYDOWN){

                switch (Game::event.key.keysym.sym){  
                    case SDLK_w:
                        transform->velocity->y = -1.0f;
                        break;
                    case SDLK_a:
                        transform->velocity->x = -1.0f;
                        break;
                    case SDLK_s:
                        transform->velocity->y = 1.0f;
                        break;
                    case SDLK_d:
                        transform->velocity->x = 1.0;
                        break;
                    
                    default:
                        break;
                }
            }

            if(Game::event.type == SDL_KEYUP){
                switch (Game::event.key.keysym.sym){
                    case SDLK_w:
                        transform->velocity->y = 0.0f;
                        break;
                    case SDLK_a:
                        transform->velocity->x = 0.0f;
                        break;
                    case SDLK_s:
                        transform->velocity->y = 0.0f;
                        break;
                    case SDLK_d:
                        transform->velocity->x = 0.0;
                        break;
                    
                    default:
                        break;
                }
            }
        }

        ~KeyboardController(){
            std::cout 
                << "[KeyboardController] Component Destroyed - " 
                << gameObject->name 
                << " Game Object" 
            <<std::endl;
        }
};
