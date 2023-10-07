#pragma once
#ifndef GAMECORE_GAMEOBJECT_H
#define GAMECORE_GAMEOBJECT_H

#include <string>

#include "SFML/Graphics.hpp"

namespace gamecore
{
	class GameObject
	{
	public:
		GameObject(std::string name);

		virtual void Initialize() = 0;
        virtual void ProcessInput(sf::Event event);
        virtual void Update(sf::Time deltaTime);
		virtual void PhysicsUpdate(sf::Time deltaTime);
        virtual void Draw(sf::RenderWindow* window, sf::RenderStates renderStates);

		std::string GetName();

	protected:
		std::string name;

	};
}

#endif // !GAMECORE_GAMEOBJECT_H
