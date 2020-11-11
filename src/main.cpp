#include <iostream>
#include "libs/SDL2/SDL.h"
#include "libs/SDL2/SDL_image.h"

#include "Game.hpp"


Game *game = nullptr;

int main(int argc, char *argv[]) {
    
    std::cout << "                                                       \n"
                "   ███████╗██╗███╗   ███╗██████╗ ██╗     ███████╗       \n"  
                "   ██╔════╝██║████╗ ████║██╔══██╗██║     ██╔════╝       \n"   
                "   ███████╗██║██╔████╔██║██████╔╝██║     █████╗         \n" 
                "   ╚════██║██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝         \n"  
                "   ███████║██║██║ ╚═╝ ██║██║     ███████╗███████╗       \n"   
                "   ╚══════╝╚═╝╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝       \n"  
                "                                                         \n" 
                "    ██████╗  █████╗ ███╗   ███╗███████╗                  \n"  
                "    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝                 \n"   
                "    ██║  ███╗███████║██╔████╔██║█████╗                   \n"  
                "    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝                   \n"   
                "    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗                 \n"   
                "    ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝                  \n" 
                "                                                         \n" 
                "   ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗     \n"
                "   ██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝     \n"
                "   █████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗       \n" 
                "   ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝       \n" 
                "   ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗     \n" 
                "   ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝     \n"
                "                                                         \n"
            << std::endl;


    //##########################
    // INITIALIZATION VARIABLES:
    const int WIDTH = 1080;
    const int HEIGHT = 720;
    const short MAX_FPS = 60;
    const short TIME_PER_FRAME = 1000/MAX_FPS;
    short fps = MAX_FPS;
    Uint32 startingTick = 0;
    Uint32 endingTick = 0;
    Uint32 deltaTime = 0;
    //##########################

    game = new Game();
    game->init("SnadesGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    while (game->running())
    {
        // STARTING FPS CALCULATION:
        if(!startingTick){
            startingTick = SDL_GetTicks();
        } else {
            deltaTime = endingTick - startingTick;
        }


        // GAME MAIN LOOP:
        game->handleEvents();
        game->update();
        game->render();


        // CAPPING FPS:
        if(deltaTime < TIME_PER_FRAME){
            SDL_Delay(TIME_PER_FRAME - deltaTime);
        } else if(deltaTime > TIME_PER_FRAME){
            // fps = 1000/deltaTime;
        }
        // std::cout << "FPS: " << fps << std::endl;        
        
        startingTick = endingTick;
        endingTick = SDL_GetTicks();
    }

    delete game;
    return 0;
}