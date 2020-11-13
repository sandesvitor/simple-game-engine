#pragma once
#include "Components.hpp"
#include "../Physics/Vector2D.hpp"


class RigidBody2D : public Component
{
    private:
        Transform* transform;
        float mass;
        float gravity;
        Vector2D* position;

        Vector2D* force;
        Vector2D* drag;

        Vector2D* velocity;
        Vector2D* acceleration;
    
    public:
        RigidBody2D(){
            this->mass = 1.0f;
            this->gravity = 9.8f;
        }

        void init() override
        {
            // GAMBIARRA PRA INSERIR O TRANSFORM COMO PRIMEIRO COMPONENTE!
            if(!gameObject->hasComponent<Transform>()){
                gameObject->addComponent<Transform>();
            }
            this->transform = &gameObject->getComponent<Transform>();
            this->position = this->transform->position;
            this->velocity = new Vector2D();
        }

        void update() override
        {   
            // CLEAN HEAP BEFORE UPDATE FRAME TO AVOID MEMORY LEAK:
            

            //ACCELERATION:            
            // this->acceleration->x = (this->force->x + this->drag->x) / this->mass;
            // this->acceleration->y = this->gravity + this->force->y/this->mass;


            // this->velocity = this->acceleration * deltaTime;
            // this->position = this->velocity * deltaTime;
        }

        void draw() override
        {
        }

        // MASS:
        void setMass(float mass){
            this->mass = mass;
        }
        void setGravity(float gravity){
            this->gravity = gravity;
        }

        // FORCE:
        inline void applyForce(Vector2D* F){
            this->force = F;
        }
        inline void applyForceX(float Fx){
            this->force->x = Fx;
        }
        inline void applyForceY(float Fy){
            this->force->y = Fy;
        }
        inline void unSetForce(){
            this->force = new Vector2D(0.0f, 0.0f);
        }
        
        
        // DRAG:
        inline void applyDrag(Vector2D* D){
            this->drag = D;
        }
        inline void unSetDrag(){
            this->drag = new Vector2D(0.0f, 0.0f);
        }






        ~RigidBody2D(){
            std::cout << "[RigidBody2D] Component Destroyed" << std::endl;
        }
    
};