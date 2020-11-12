#pragma once
#include "Components.hpp"
#include "../Physics/Vector2D.hpp"

class Transform : public Component
{
    public:
        Vector2D* position;
        Vector2D* scale;

    // Same as UnityEngine.OnAwake

    Transform(){}

    void init() override
    {
        this->position = new Vector2D();
        this->scale = new Vector2D(1.0f, 1.0f);
    }

    void update() override
    {
    }

    void setPosition(Vector2D *newPosition)
    {
        free(this->position); // AQUI É "FREE()" OU DELETE ????
        this->position = newPosition;
    }

    void setScale(Vector2D*newScale)
    {
        free(this->scale); // AQUI É "FREE()" OU DELETE ????
        this->scale = newScale;
    }

    ~Transform()
    {
        delete this->position;
        delete this->scale;
        std::cout << "[Transform] Component Destroyed" << std::endl;
    }
};