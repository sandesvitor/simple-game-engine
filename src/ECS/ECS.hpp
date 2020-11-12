#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>


class Component;
class GameObject;

using ComponentID = std::size_t;

inline  ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template<typename T> 
inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;



class Component
{
    public:
        GameObject* gameObject;

        virtual void init(){}
        virtual void update(){}
        virtual void draw(){}

        virtual ~Component(){}
};


class GameObject
{
    private:
        std::string name;
        bool active = true;
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;

    public:
        GameObject(const std::string& name){
            this->name = name;
        }

        void update(){
            for(auto& c : components) c->update();
        }

        void draw(){
            for(auto& c : components) c->draw();
        }
        
        bool isActive() const { return active; }
        void destroy() { active = false; }

        template<typename T> 
        bool hasComponent() const 
        {
            return componentBitSet[getComponentTypeID<T>()];
        }

        template<typename T, typename... TArgs>
        T& addComponent(TArgs&&... mArgs)
        {
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->gameObject = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPtr));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitSet[getComponentTypeID<T>()] = true;

            c->init();
            return *c;
        }

        template<typename T>
        T& getComponent() const
        {
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

        ~GameObject() {
        
            std::cout 
                << "[" 
                << this->name 
                << "] "
                << "and Components Destroyed!" << std::endl;
        }
};


class GameObjectFactory
{
    private:
        std::vector<std::unique_ptr<GameObject>> gameObjects;

    public:
        void update()
        {
            for (auto& entity : gameObjects) entity->update();
        }

        void draw()
        {
            for (auto& entity : gameObjects)  entity->draw();
        }

        void refresh()
        {
            gameObjects.erase(std::remove_if(std::begin(gameObjects), std::end(gameObjects),
                [](const std::unique_ptr<GameObject> &mGameObject)
                {
                    return !mGameObject->isActive();
                }),
                    std::end(gameObjects));
        }

        GameObject& addGameObject(const std::string& name)
        {
            GameObject* gameObject = new GameObject(name);
            
            // gameObject->addComponent<Transform>(); ==> IMPLEMENTAR DEPOIS (COMPONENTE DEFAULT "TRANSFORM")

            std::unique_ptr<GameObject> uPtr{ gameObject };
            gameObjects.emplace_back(std::move(uPtr));

            return *gameObject;
        }
        
        ~GameObjectFactory(){
            std::cout << "[GameObjectFactory] Destroyed!" << std::endl;
        }
};