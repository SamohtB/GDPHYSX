#pragma once
#ifndef PHYSICS_PARTICLE_CONTACT_H
#define PHYSICS_PARTICLE_CONTACT_H

#include "../Particle2D.h"

namespace physics
{
	class ParticleContact
	{
	friend class ParticleContactResolver;

	public:
		Particle2D* particles[2];
		Vector2D particleMovement[2];

		float restitution;
		float penetration;

		Vector2D contactNormal;
		void Resolve(float deltaTime);

	protected:
		float CalculateSeparatingVelocity();

	private:
		void ResolveVelocity(float duration);
		void ResolveInterpenetration(float deltaTime);
	};
}

#endif // !PHYSICS_PARTICLE_CONTACT_H



