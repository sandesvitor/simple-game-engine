#pragma once
#include <iostream>

class Vector2D
{
    public:
        float x, y;

    public:
        Vector2D(float x = 0, float y = 0){
            this->x = x;
            this->y = y;
        }
    

        // OVERLOADING add and subtraction operators:
        Vector2D operator + (const Vector2D& v2) {
            return Vector2D(this->x + v2.x, this->y + v2.y);
        }
        
        Vector2D operator - (const Vector2D& v2) {
            return Vector2D(this->x - v2.x, this->y - v2.y);
        }
        
        Vector2D operator * (const float& scalar) {
            return Vector2D(this->x * scalar, this->y * scalar);
        }
        
        Vector2D operator / (const float& divider) {
            return Vector2D(this->x / divider, this->y / divider);
        }

        ~Vector2D(){
            std::cout << "[Vector 2D - Physics] destroyed!" << std::endl;
        }

};