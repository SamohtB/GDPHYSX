#pragma once
#ifndef PHYSICS_PARTICLE_LINK_H
#define PHYSICS_PARTICLE_LINK_H

#include "../Particle3D.h"
#include "../ParticleContact.h"

namespace physics
{
	class ParticleLink
	{
	public:
		Particle3D* particles[2];

	protected:
		float CurrentLength();
		virtual unsigned FillContact(ParticleContact* contact) = 0;
	};	
}


#endif


