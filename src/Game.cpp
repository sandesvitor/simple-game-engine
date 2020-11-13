#include "Game.hpp"
#include "ECS/Components.hpp"
#include "ECS/Collision.hpp"

SDL_Event Game::event;
GameObjectManager gameObjectManager;

// GAME OBJECTS:
GameObject& Pokeball(gameObjectManager.addGameObject("Pokeball"));
GameObject& Wall(gameObjectManager.addGameObject("Wall"));

SDL_Rect debugRect;

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


    Pokeball.addComponent<Transform>();
    Pokeball.addComponent<Sprite>("assets/pokeball.png", this->renderer);
    Pokeball.addComponent<Collider>("[Tag]Player", this->renderer);
    Pokeball.getComponent<Collider>().isDebugDrawActive = true;
    Pokeball.getComponent<Transform>().position->x = 100.0f;
    Pokeball.getComponent<Transform>().position->y = 100.0f;    
    Pokeball.addComponent<KeyboardController>();

    Wall.addComponent<Transform>();
    Wall.addComponent<Sprite>("assets/grass.png", this->renderer);
    Wall.addComponent<Collider>("[Tag]Obstacle", this->renderer);
    Wall.getComponent<Collider>().isDebugDrawActive = true;
    Wall.getComponent<Transform>().position->x = 400.0f;
    Wall.getComponent<Transform>().position->y = 200.0f;    


    isRunning = true;
    std::cout << "<<<<<<< GAME::INIT completed >>>>>>>\n" << std::endl;
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

    debugRect = {250, 150, 200, 200};

    if(Collision::AABB(Pokeball.getComponent<Collider>().collider, Wall.getComponent<Collider>().collider)){
        std::cout << "Pokeball Hit The Wall!" << std::endl;
    }
}

void Game::clear()
{}

void Game::render()
{
    SDL_RenderClear(this->renderer);

    gameObjectManager.draw();

    SDL_RenderPresent(this->renderer);
}

Game::~Game()
{
    std::cout << "<<<<<<< GAME::~GAME >>>>>>>" << std::endl;
    SDL_DestroyRenderer(this->renderer);    
    SDL_DestroyWindow(this->window);   
    SDL_Quit();
    SDL_Log("Game Cleaned!");
}