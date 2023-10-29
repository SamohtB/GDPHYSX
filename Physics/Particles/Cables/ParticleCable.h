#pragma once
#ifndef PHYSICS_PARTICLE_CABLE_H
#define PHYSICS_PARTICLE_CABLE_H

#include "ParticleLink.h"

namespace physics
{
	class ParticleCable : public ParticleLink
	{
	public:
		float maxLength;
		float restitution;
		unsigned FillContact(ParticleContact* contact) override;
	};
}

#endif


