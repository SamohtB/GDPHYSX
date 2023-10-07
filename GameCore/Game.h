#pragma once
#ifndef GAMECORE_GAME_H
#define GAMECORE_GAME_H

#include <vector>
#include <iomanip>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../Config/Settings.h"
#include "Managers/GameObjectManager.h"

#include "../Physics/Particles/ParticleForceRegistry.h"
#include "../Entities/PhysicsParticle.h"


namespace gamecore
{
	using namespace entity;
	using namespace singleton;
	using namespace physics;

	class Game
	{
	private:

	public:
		Game();
		~Game() = default;

		void Run();
		void ProcessInput();
		void ProcessKeyBoardInput(sf::Keyboard::Key key, bool keyState);
		void Update(sf::Time deltaTime);
		void Render();

		sf::RenderWindow renderWindow;

	private:
		Vector3D mousePos;
		bool isSpacePressed;

	private:
		ParticleForceRegistry* registry;
	};
}

#endif


