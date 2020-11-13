#pragma once
#include "libs/SDL2/SDL.h"
#include "libs/SDL2/SDL_image.h"

class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
        
        void handleEvents();
        void update();
        void render();
        void clear();

        inline bool running(){ return isRunning; }

        static SDL_Event event;
        
    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};