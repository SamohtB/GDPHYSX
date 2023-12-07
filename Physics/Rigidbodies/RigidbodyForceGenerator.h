#pragma once
#ifndef PHYSICS_RIGIDBODY_FORCE_GENERATOR_H
#define PHYSICS_RIGIDBODY_FORCE_GENERATOR_H

#include "Rigidbody2D.h"

namespace physics
{
	class RigidbodyForceGenerator
	{
	public:
		virtual void UpdateForce(Rigidbody2D* rigidbody, float duration) = 0;
	};
}

#endif