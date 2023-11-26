#pragma once
#ifndef PHYSICS_PARTICLE_ANCHORED_SPRING_H
#define PHYSICS_PARTICLE_ANCHORED_SPRING_H

#include "../Forces/IParticleForceGenerator.h"

namespace physics
{
	class ParticleAnchoredSpring : public IParticleForceGenerator
	{
	public:
		ParticleAnchoredSpring(Vector2D* anchor, float springConstant, float restLength) : 
			anchor(anchor), springConstant(springConstant), restLength(restLength) {}

		virtual void UpdateForce(Particle2D* particle, float deltaTime);
		
	private:
		Vector2D* anchor;
		float springConstant;
		float restLength;
	};
}



#endif // !PHYSICS_PARTICLE_ANCHORED_SPRING_H


