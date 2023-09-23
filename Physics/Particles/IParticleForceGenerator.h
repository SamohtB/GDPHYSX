#pragma once
#ifndef PHYSICS_FORCE_GENERATOR_H
#define PHYSICS_FORCE_GENERATOR_H

#include "Particles3D.h"

namespace physics
{
	class IParticleForceGenerator
	{
	public:
		virtual void UpdateForce(Particles3D* particle, float duration) = 0;
	};
}

#endif