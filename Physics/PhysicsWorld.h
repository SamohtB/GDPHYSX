#pragma once
#ifndef PHYSICS_PHYSICS_WORLD_H
#define PHYSICS_PHYSICS_WORLD_H

#include <vector>

#include "Rigidbodies/Rigidbody2D.h"
#include "Rigidbodies/RigidbodyForceGenerator.h"

namespace  physics
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld(unsigned maxContacts, unsigned iterations = 0);
		~PhysicsWorld();

		void StartFrame();
		void Integrate(float deltaTime);
		void RunPhysics(float deltaTime);

		unsigned maxContacts;
		bool calculateIterations;

		std::vector<Rigidbody2D*> rigidbodyList;
		RigidbodyForceRegistry registry;
	};
}

#endif


