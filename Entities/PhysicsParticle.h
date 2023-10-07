#pragma once
#ifndef ENTITY_PHYSICS_PARTICLE_H
#define ENTITY_PHYSICS_PARTICLE_H

#include "SFML/Graphics.hpp"

#include "../Physics/Particles/Particle3D.h"
#include "../BaseClasses/GameObject.h"
#include "../BaseClasses/MyEnums.h"

namespace entity
{
	using namespace physics;
	using namespace baseclass;

	class PhysicsParticle :  public GameObject, sf::CircleShape
	{
	public:
		PhysicsParticle(std::string name);
		void Initialize();
		void PhysicsUpdate(sf::Time deltaTime) override;
		void Draw(sf::RenderWindow* renderWindow, sf::RenderStates renderStates) override;

		void SetPosition(float x, float y, float z);

	public:
		Particle3D particle;
		

	private:

	};
}

#endif // !ENTITY_SPRING_POINT_PARTICLE_H





