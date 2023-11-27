#pragma once
#ifndef PHYSICS_RIGIDBODIES_H
#define PHYSICS_RIGIDBODIES_H

#include "../Particle2D.h"
#include  "Shape2D.h" 

namespace physics
{
	class Rigidbody2D : public Particle2D
	{
	public:
		virtual void Integrate(float deltaTime);
		void AddForceOnPoint(Vector2D point, Vector2D force);
		void ClearTorqueAccumulator();

		float rotation = 0.0f;
		float angularVelocity = 0.0f;
		float angularDamping = 0.0f;
		float torqueAccumulator = 0.0f;

		Shape2D* shape;
	};
}


#endif

