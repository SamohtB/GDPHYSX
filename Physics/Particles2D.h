#pragma once
#ifndef PHYSICS_PARTICLES2D_H
#define PHYSICS_PARTICLES2D_H

#include "../MyVectors/Vector3D.h"
#include <cassert>

namespace physics
{
	using namespace vectors;
	class Particles3D
	{
	public:
		Particles3D() = default;
		void Integrate(float deltaTime);

	public:
		void SetDamping(float damping);
		float GetDamping();

		void SetMass(float mass);
		float GetMass();

		void SetVelocity(Vector3D velocity);
		Vector3D GetVelocity();

		void SetAcceleration(Vector3D acceleration);
		Vector3D GetAcceleration();

		void SetPosition(Vector3D position);
		Vector3D GetPosition();

	private:
		float inverseMass;
		float damping;

		Vector3D position;
		Vector3D velocity;
		Vector3D acceleration;
	};
}
#endif // !PHYSICS_PARTICLES2D_H
