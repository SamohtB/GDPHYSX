#pragma once
#ifndef PHYSICS_PARTICLE_CONTACT_H
#define PHYSICS_PARTICLE_CONTACT_H

#include "Particle3D.h"

namespace physics
{
	class ParticleContact
	{
	public:
		Particle3D* particles[2];
		float restituion;
		Vector3D contactNormal;
		void Resolve(float deltaTime);

	protected:
		float CalculateSeparatingVelocity();

	private:
		void ResolveVelocity(float duration);
	};
}

#endif // !PHYSICS_PARTICLE_CONTACT_H



