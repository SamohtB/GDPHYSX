#pragma once
#ifndef PHYSICS_NARROW_PHASE_H
#define PHYSICS_NARROW_PHASE_H

#include "Rigidbody2D.h"

namespace physics
{
	class CollisionFloor
	{
	public:
		Vector2D direction;
		float offset;
	};

	class CollisionPrimitive
	{
	public:
		Rigidbody2D* body;
		Vector2D GetAxisVector(int i);
	};

	class CollisionBox : public CollisionPrimitive
	{
	public:
		Vector2D halfSize;
	};

	class IntersectionTests
	{
	public:
		static bool BoxAndHalfSpace(CollisionBox& box, CollisionFloor& floor);
	};
}

#endif



