#pragma once
#ifndef ENTITY_RUNNER_H
#define ENTITY_RUNNER_H

#include "SFML/Graphics.hpp"
#include "../MyVectors/Vector3D.h"
#include "../Physics/Particles3D.h"

namespace entity
{
	using namespace vectors;
	using namespace physics;

	class Runner : public sf::CircleShape
	{
	public:
		Runner(Vector3D initialPosition, Vector3D initialVelocity, Vector3D initialAcceleration);
		void PhysicsUpdate(float deltaTime);

		void SetName(std::string name);
		std::string GetName();

		void IsFinished(bool state);
		bool IsFinished();

	public:
		Particles3D particle;

	private:
		std::string name;
		bool isFinished;
	};
}

#endif // !ENTITY_RUNNER_H
