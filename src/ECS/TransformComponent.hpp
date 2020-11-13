#pragma once
#include "Components.hpp"
#include "../Physics/Vector2D.hpp"

class Transform : public Component
{
    public:
        Vector2D* position;
        Vector2D* scale;
        Vector2D* velocity;

        int height = 32;
        int width = 32;

        float speed = 3.0f;

    Transform(){
        this->position = new Vector2D(0.0f, 0.0f);
        this->scale = new Vector2D(1.0f, 1.0f);
    }

    void init() override
    {
        this->velocity = new Vector2D(0.0f, 0.0f);
    }

    void update() override
    {
        this->position->x += this->velocity->x * speed;
        this->position->y += this->velocity->y * speed;
    }

    void translateX(float horizontal){
        this->position->x += horizontal;
    }

    void translateY(float vertical){
        this->position->y += vertical;
    }

    void reScaleX(float xScale){
        this->scale->x += xScale;
    }
    
    void reScaleY(float yScale){
        this->scale->y += yScale;
    }

    ~Transform()
    {
        delete this->velocity;
        delete this->position;
        delete this->scale;
        
        std::cout 
            << "[Transform] Component Destroyed - " 
            << gameObject->name 
            << " Game Object" 
        <<std::endl;
    }
};