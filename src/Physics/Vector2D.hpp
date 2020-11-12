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
    

        // overwriting add and subtraction operators:
        inline Vector2D operator+(const Vector2D& v2) const {
            return Vector2D(this->x + v2.x, this->y + v2.y);
        }
        
        inline Vector2D operator-(const Vector2D& v2) const {
            return Vector2D(this->x - v2.x, this->y - v2.y);
        }
        
        inline Vector2D operator*(const float scalar) const {
            return Vector2D(this->x * scalar, this->y * scalar);
        }

        ~Vector2D(){
            std::cout << "[Vector 2D - Physics] destroyed!" << std::endl;
        }

};