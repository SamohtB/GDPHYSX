#pragma once
#ifndef SINGLETON_PHYSICS_GENERATOR_MANAGER_H
#define SINGLETON_PHYSICS_GENERATOR_MANAGER_H

#include <vector>

#include "SFML/Graphics.hpp"
#include "../GameObject.h"

namespace singleton
{
    using namespace gamecore;

    class GameObjectManager
    {
    public:
        void ProcessInput(sf::Event event);
        void Update(sf::Time deltaTime);
        void PhysicsUpdate(sf::Time deltaTime);
        void Draw(sf::RenderWindow* window);

        void AddObject(GameObject* gameObject);

    private:
        std::vector<GameObject*> gameObjectList;

    public:
		static GameObjectManager* GetInstance();

    private:
		GameObjectManager() {}
		GameObjectManager(const GameObjectManager&) = delete;
		GameObjectManager& operator=(const GameObjectManager&) = delete;

	private:
		static GameObjectManager* Instance;
    };
}
#endif // !SINGLETON_PHYSICS_GENERATOR_MANAGER_H


