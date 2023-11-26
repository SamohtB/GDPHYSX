#pragma once
#ifndef PHYSICS_FORCE_GENERATOR_H
#define PHYSICS_FORCE_GENERATOR_H

#include "../Particle2D.h"

namespace physics
{
	class IParticleForceGenerator
	{
	public:
		virtual void UpdateForce(Particle2D* particle, float duration) = 0;
	};
}

#endif