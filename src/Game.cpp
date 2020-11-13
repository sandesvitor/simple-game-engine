#include "Game.hpp"
#include "ECS/Components.hpp"

SDL_Event Game::event;
GameObjectManager gameObjectManager;
auto& Pokeball(gameObjectManager.addGameObject("Pokeball"));

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

    this->window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if(this->window == nullptr){
        SDL_Log("Failed to create window: %s", SDL_GetError());
        isRunning = false;
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(this->renderer == nullptr){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        isRunning = false;
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);



    Pokeball.addComponent<Transform>();
    Pokeball.addComponent<Sprite>("assets/pokeball.png", this->renderer);
    Pokeball.addComponent<KeyboardController>();
    

    isRunning = true;
    std::cout << "<<<<<<< GAME::INIT completed >>>>>>>" << std::endl;
}

void Game::handleEvents()
{
    SDL_PollEvent(&Game::event);

    switch(Game::event.type ){
        case SDL_QUIT:
            isRunning = false;
        default:
            break;
    }
    
}

void Game::update()
{
    gameObjectManager.update();
    gameObjectManager.refresh();
}

void Game::clear()
{}

void Game::render()
{
    SDL_RenderClear(this->renderer);

    Pokeball.getComponent<Sprite>().draw();


    SDL_RenderPresent(this->renderer);
}

Game::~Game()
{
    SDL_DestroyRenderer(this->renderer);    
    SDL_DestroyWindow(this->window);   
    SDL_Quit();
    SDL_Log("Game Cleaned!");
}