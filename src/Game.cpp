#include "Game.hpp"
#include "ECS/Components.hpp"


GameObjectFactory gFactory;
auto& Pokeball(gFactory.addGameObject("Pokeball"));

Game::Game()
{}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_Log("Failed to initialize SDL Subsystems: %s", SDL_GetError());
        isRunning = false;
    }

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if(window == nullptr){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        isRunning = false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        isRunning = false;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);



    Pokeball.addComponent<Transform>();
    Pokeball.addComponent<Sprite>("assets/pokeball.png", renderer);
    Pokeball.getComponent<Transform>().setPosition(new Vector2D(0.0f, 0.0f));
    Pokeball.getComponent<Transform>().setScale(new Vector2D(4.0f, 4.0f));

    isRunning = true;
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch( event.type ){
            case SDL_QUIT:
                isRunning = false;
            /* Look for a keypress */
            case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
                    // ARROW UP - ARROW DOWN - ARROW RIGHT - ARROW LEFT
                    case SDLK_LEFT:
                        SDL_Log("LEFT");
                        Pokeball.getComponent<Transform>().translateX(-30.0f);
                        break;
                    case SDLK_RIGHT:
                        SDL_Log("RIGHT");
                        Pokeball.getComponent<Transform>().translateX(30.0f);
                        break;
                    case SDLK_UP:
                        SDL_Log("UP");
                        Pokeball.getComponent<Transform>().translateY(-30.0f);
                        break;
                    case SDLK_DOWN:
                        SDL_Log("DOWN");
                        Pokeball.getComponent<Transform>().translateY(30.0f);
                        break;
                    
                    // W - S - D - A
                    case SDLK_a:
                        SDL_Log("LEFT");
                        break;
                    case SDLK_d:
                        SDL_Log("RIGHT");
                        break;
                    case SDLK_w:
                        SDL_Log("UP");
                        break;
                    case SDLK_s:
                        SDL_Log("DOWN");
                        break;




                    default:
                        break;
                }
            
            default:
                break;
        }
    }
}

void Game::update()
{
    Pokeball.getComponent<Sprite>().update();
    Pokeball.getComponent<Transform>().update();


    // Entities ==> components:
    gFactory.update();
}

void Game::clear()
{}

void Game::render()
{
    SDL_RenderClear(renderer);

    Pokeball.getComponent<Sprite>().draw();


    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);    
    SDL_DestroyWindow(window);   
    SDL_Quit();
    SDL_Log("Game Cleaned!");
}