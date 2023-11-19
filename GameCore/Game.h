#pragma once
#ifndef GAMECORE_GAME_H
#define GAMECORE_GAME_H

#include <vector>
#include <iomanip>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../Config/Settings.h"
#include "Managers/GameObjectManager.h"

#include "../Physics/Particles/Forces/ParticleDrag.h"
#include "MassAggregateSystem.h"

#include "../Entities/ParticleObject.h"
#include "../Entities/VisibleLine.h"
#include "../Entities/FidgetSpinner.h"

namespace gamecore
{
	using namespace singleton;
	using namespace physics;
	using namespace entity;

	class Game
	{
	public:
		void CreateParticles();
		void CreateRodConnections();
		Game();

		~Game() = default;

		void Run();
		void ProcessInput();
		void Update(sf::Time deltaTime);
		void Render();

	private:
		sf::RenderWindow renderWindow;
		MassAggregateSystem* massAggregateSystem;
		std::vector<ParticleObject*> particleList;
		Vector3D* screenCenter;
		FidgetSpinner* spinner;
	};
}

#endif


