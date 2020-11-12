# **Simple Game Engine** 
## (v 0.1)
___

## 1. ***Scrippiting API:***

### A **GameObject** is an entity composed of an array of **Components**.

Ex: Creating an GameObject and manipulating its Components with Manager class:
```c++
Manager manager;

auto& PokeBall(manager.addGameObject("Pokeball"));

Pokeball.addComponent<Transform>();
Transform* _transform = Pokeball.getComponent<Transform>();

_transform.setPosition(new Vector2(100.0f, 20.0f)) 
// default == Vector2(x = 0.0f, y = 0.0f);

_transform.setScale(new Vector2(20.0f, 5.0f))
// default == Vector2(x = 1.0f, y = 1.0f);

Pokeball.addComponent<Sprite>("assets/pokeball.png");
```

## 1. ***Game Objects***
## 1. ***Physics***
- ### class Vector2