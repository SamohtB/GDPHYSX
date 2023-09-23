#pragma once
#ifndef PHYSICS_PARTICLE_PHYSICS_REGISTRY_H
#define PHYSICS_PARTICLE_PHYSICS_REGISTRY_H

#include <vector>

#include "Particles3D.h"
#include "IParticleForceGenerator.h"

namespace physics
{
	class ParticleForceRegistry
	{
	protected:
		struct ParticleForceRegistration
		{
			Particles3D* particle;
			IParticleForceGenerator* forceGenerator;
		};

		typedef std::vector<ParticleForceRegistration> Registry;
		Registry registrations;

	public:
		void Add(Particles3D* particle, IParticleForceGenerator* forceGenerator);
		void Remove(Particles3D* particle, IParticleForceGenerator* forceGenerator);
		void Clear();
		void UpdateForces(float duration);
	};
}

#endif // !1






