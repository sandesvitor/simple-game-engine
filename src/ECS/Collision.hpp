#pragma once

#include "../../libs/SDL2/SDL.h"

class Collision
{
    public:
        static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB){
            if(
                rectA.x + rectA.w >= rectB.x &&
                rectB.x + rectB.w >= rectA.x &&
                rectA.y + rectA.h >= rectB.y &&
                rectB.y + rectB.h >= rectA.y
            ) {
                return true;
            }

            return false;
        }
};