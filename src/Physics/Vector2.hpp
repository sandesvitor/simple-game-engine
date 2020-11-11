#pragma once
#include <iostream>

class Vector2
{
    public:
        float x, y;

    public:
        Vector2(float x = 0, float y = 0){
            this->x = x;
            this->y = y;
        }
    

        // overwriting add and subtraction operators:
        inline Vector2 operator+(const Vector2& v2) const {
            return Vector2(this->x + v2.x, this->y + v2.y);
        }
        
        inline Vector2 operator-(const Vector2& v2) const {
            return Vector2(this->x - v2.x, this->y - v2.y);
        }
        
        inline Vector2 operator*(const float scalar) const {
            return Vector2(this->x * scalar, this->y * scalar);
        }

        ~Vector2(){
            std::cout << "[Vector 2 - Physics] destroyed!" << std::endl;
        }

};