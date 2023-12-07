#pragma once
#ifndef PHYSICS_RIGIDBODY_FORCE_REGISTRY_H
#define PHYSICS_RIGIDBODY_FORCE_REGISTRY_H

#include <vector>
#include "RigidbodyForceGenerator.h"

namespace physics
{
	class RigidbodyForceRegistry
	{
	protected:
		struct RigidbodyForceRegistration
		{
			Rigidbody2D* rigidbody;
			RigidbodyForceGenerator* forceGenerator;
		};

		typedef std::vector<RigidbodyForceRegistration> Registry;
		Registry registrations;

	public:
		void Add(Rigidbody2D* particle, RigidbodyForceGenerator* forceGenerator);
		//void Remove(Rigidbody2D* particle, RigidbodyForceGenerator* forceGenerator);
		//void Clear();
		void UpdateForces(float duration);


	};
}


#endif


