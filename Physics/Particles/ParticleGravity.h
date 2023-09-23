#pragma once
#ifndef PHYSICS_PARTICLES_GRAVITY_H
#define PHYSICS_PARTICLES_GRAVITY_H

#include "IParticleForceGenerator.h"

namespace physics
{
	class ParticleGravity : public IParticleForceGenerator
	{
	public:
		ParticleGravity(Vector3D gravity) : gravity(gravity){};
		virtual void UpdateForce(Particles3D* particle, float duration);
	private:
		Vector3D gravity;
	};
}

#endif // PHYSICS_PARTICLES_GRAVITY_H



