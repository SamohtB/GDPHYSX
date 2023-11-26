#pragma once
#ifndef GAMECORE_MASS_AGGREGATE_SYSTEM
#define GAMECORE_MASS_AGGREGATE_SYSTEM

#include "../Physics/Particles/ParticleWorld.h"
#include "../Physics/Particles/Forces/ParticleGravity.h"
#include "../Physics/Particles/Cables/ParticleOverlapContact.h"
#include "../Physics/Particles/Cables/ParticleGroundContact.h"
#include "../Physics/Particles/SpringLikeForces/ParticleAnchoredSpring.h"
#include "../Physics/Particles/Cables/ParticleAnchoredCable.h"
#include "../Physics/Particles/SpringLikeForces/ParticleSpring.h"
#include "../Physics/Particles/Cables/ParticleRod.h"


namespace gamecore
{
	using namespace physics;

	class MassAggregateSystem
	{
	public:
		MassAggregateSystem(Vector2D gravity = Vector2D(0.0f, 100.0f), int maxContacts = 5, float restitution = 0.9f);
		~MassAggregateSystem();

		void AttachParticleToParticleSpring(Particle2D* particle1, Particle2D* particle2, float springConstant, float restLength, bool hasGravity = true);
		void AttachParticleToParticleRod(Particle2D* particle, Particle2D* particle2, float maxLength, bool hasGravity = true);
		void AttachParticleToAnchoredSpring(Particle2D* particle, Vector2D* anchor, float springConstant, float restLength, bool hasGravity = true);
		void AttachParticleToAnchoredCable(Particle2D* particle, Vector2D* anchor, float maxLength, float restitution, bool hasGravity = true);

		void AddParticle(Particle2D* particle, bool hasGravity = true, bool hasOverlap = true);
		void Update(float deltaTime);

	private:
		ParticleWorld* particleWorld;
		ParticleGravity* gravity;
		ParticleOverlapContact* overlapContact;
	};
}


#endif


