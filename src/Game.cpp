#include "Game.hpp"
#include "ECS/Components.hpp"


Manager manager;
auto& Pokeball(manager.addGameObject("Pokeball"));
auto& Grass_1(manager.addGameObject("Grass_1"));
auto& Grass_2(manager.addGameObject("Grass_2"));
auto& Monster(manager.addGameObject("Monster"));

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
    Pokeball.getComponent<Transform>().setPosition(new Vector2(200.0f, 0.0f));
    Pokeball.getComponent<Transform>().setScale(new Vector2(4.0f, 4.0f));

    Monster.addComponent<Transform>();
    Monster.addComponent<Sprite>("assets/MonsterCorrupted.png", renderer);
    Monster.getComponent<Transform>().setPosition(new Vector2(400.0f, 200.0f));
    Monster.getComponent<Transform>().setScale(new Vector2(6.0f, 6.0f));

    Grass_1.addComponent<Transform>();
    Grass_1.addComponent<Sprite>("assets/grass.png", renderer);
    Grass_1.getComponent<Transform>().setPosition(new Vector2(80.0f, 400.0f));
    Grass_1.getComponent<Transform>().setScale(new Vector2(30.0f, 4.0f));
    
    Grass_2.addComponent<Transform>();
    Grass_2.addComponent<Sprite>("assets/grass.png", renderer);
    Grass_2.getComponent<Transform>().setPosition(new Vector2(80.0f, 500.0f));
    Grass_2.getComponent<Transform>().setScale(new Vector2(30.0f, 4.0f));

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
                        break;
                    case SDLK_RIGHT:
                        SDL_Log("RIGHT");
                        break;
                    case SDLK_UP:
                        SDL_Log("UP");
                        break;
                    case SDLK_DOWN:
                        SDL_Log("DOWN");
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
    Grass_1.getComponent<Sprite>().update();
    Grass_2.getComponent<Sprite>().update();
    Monster.getComponent<Sprite>().update();


    // Entities ==> components:
    manager.update();
}

void Game::clear()
{}

void Game::render()
{
    SDL_RenderClear(renderer);

    Pokeball.getComponent<Sprite>().draw();
    Grass_1.getComponent<Sprite>().draw();
    Grass_2.getComponent<Sprite>().draw();
    Monster.getComponent<Sprite>().draw();


    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);    
    SDL_DestroyWindow(window);   
    SDL_Quit();
    SDL_Log("Game Cleaned!");
}