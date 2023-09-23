#pragma once
#ifndef GAMECORE_GAME_H
#define GAMECORE_GAME_H

#include <vector>
#include <iomanip>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../Config/Settings.h"
#include "../Entities/Runner.h"


namespace gamecore
{
	using namespace entity;

	class Game
	{

	private:
		struct RaceMetrics
		{
			std::string name;
			float velocityMagnitude;
			float averageVelocity;
			float timeToComplete;
		};

	public:
		Game();
		~Game() = default;

		void Run();
		void ProcessInput();
		void Update(sf::Time deltaTime);
		void Render();

		sf::RenderWindow renderWindow;


	private:
		void SetRunners();
		void DisplayResults(RaceMetrics metrics, int place);

	private:
		std::vector<Runner*> runnerList;
		sf::RectangleShape* finishLine;
		std::vector<RaceMetrics> raceMetrics;

		bool isRaceEnd;
		float timeElapsed;
	};
}

#endif


