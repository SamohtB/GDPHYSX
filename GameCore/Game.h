#pragma once
#ifndef GAMECORE_GAME_H
#define GAMECORE_GAME_H

#include <vector>
#include <iomanip>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../Config/Settings.h"
#include "Managers/GameObjectManager.h"
#include "MassAggregateSystem.h"

#include "../Entities/ParticleObject.h"
#include "../Entities/Box2D.h"


namespace gamecore
{
	using namespace singleton;
	using namespace physics;
	using namespace entity;

	class Game
	{
	public:
		Game();
		~Game() = default;

		void Run();
		void ProcessInput();
		void Update(sf::Time deltaTime);
		void Render();

	private:
		sf::RenderWindow renderWindow;
		MassAggregateSystem* massAggregateSystem;
	};
}

#endif


