#pragma once
#include "Components.hpp"
#include "../Physics/Vector2.hpp"

class Transform : public Component
{
    public:
        Vector2* position;
        Vector2* scale;

    // Same as UnityEngine.OnAwake

    Transform(){}

    void init() override
    {
        this->position = new Vector2();
        this->scale = new Vector2(1.0f, 1.0f);
    }

    void update() override
    {
    }

    void setPosition(Vector2 *newPosition)
    {
        free(this->position); // AQUI É "FREE()" OU DELETE ????
        this->position = newPosition;
    }

    void setScale(Vector2 *newScale)
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