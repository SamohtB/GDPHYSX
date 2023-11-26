#pragma once
#ifndef PHYSICS_PARTICLES_GRAVITY_H
#define PHYSICS_PARTICLES_GRAVITY_H

#include "IParticleForceGenerator.h"

namespace physics
{
	class ParticleGravity : public IParticleForceGenerator
	{
	public:
		ParticleGravity(Vector2D gravity) : gravity(gravity){};
		virtual void UpdateForce(Particle2D* particle, float duration);
	private:
		Vector2D gravity;
	};
}

#endif // PHYSICS_PARTICLES_GRAVITY_H



