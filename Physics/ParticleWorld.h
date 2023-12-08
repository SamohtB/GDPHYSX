#pragma once
#ifndef PHYSICS_PARTICLE_WORLD_H
#define PHYSICS_PARTICLE_WORLD_H

#include <vector>

#include "Rigidbodies/Rigidbody2D.h"
#include "Rigidbodies/RigidbodyForceGenerator.h"
#include "Particles/Cables/ParticleContactResolver.h"
#include "Particles/Cables/ParticleContactGenerator.h"

namespace  physics
{
	class ParticleWorld
	{
	public:
		ParticleWorld(unsigned maxContacts, unsigned iterations = 0);
		~ParticleWorld();

		unsigned GenerateContacts();
		void StartFrame();

		void Integrate(float deltaTime);
		void RunPhysics(float deltaTime);

		unsigned maxContacts;
		bool calculateIterations;

		std::vector<Rigidbody2D*> rigidbodyList;
		RigidbodyForceRegistry registry;

		ParticleContactResolver resolver;
		std::vector<ParticleContactGenerator*> particleContactGeneratorList;
		ParticleContact* particleContactArray;


	};
}

#endif


