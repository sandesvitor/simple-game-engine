#pragma once
#include "ECS.hpp"
#include "Vector2D.hpp"


class RigidBody2D : public Component
{
    public:
        RigidBody2D(){}
        ~RigidBody2D(){}
    
    private:
        float mass;
        float gravity;

        Vector2D force;
        Vector2D drag;

        Vector2D velocity;
        Vector2D acceleration;
};