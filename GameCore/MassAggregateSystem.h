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
		MassAggregateSystem(Vector3D gravity = Vector3D(0, 100.0f, 0), int maxContacts = 5, float restitution = 0.9f);
		~MassAggregateSystem();

		void AttachParticleToParticleSpring(Particle3D* particle1, Particle3D* particle2, float springConstant, float restLength, bool hasGravity = true);
		void AttachParticleToParticleRod(Particle3D* particle, Particle3D* particle2, float maxLength, bool hasGravity = true);
		void AttachParticleToAnchoredSpring(Particle3D* particle, Vector3D* anchor, float springConstant, float restLength, bool hasGravity = true);
		void AttachParticleToAnchoredCable(Particle3D* particle, Vector3D* anchor, float maxLength, float restitution, bool hasGravity = true);

		void AddParticle(Particle3D* particle, bool hasGravity = true, bool hasOverlap = true);
		void Update(float deltaTime);

	private:
		ParticleWorld* particleWorld;
		ParticleGravity* gravity;
		ParticleOverlapContact* overlapContact;
	};
}


#endif

