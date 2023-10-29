#pragma once
#ifndef PHYSICS_PARTICLE_ROD_H
#define PHYSICS_PARTICLE_ROD_H

#include "ParticleLink.h"

namespace physics
{
	class ParticleRod : public ParticleLink
	{
	public:
		float length;
		unsigned FillContact(ParticleContact* contact) override;
	};

}


#endif


