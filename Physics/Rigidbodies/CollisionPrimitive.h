#pragma once
#ifndef PHYSICS_COLLISION_PRIMITIVE_H
#define PHYSICS_COLLISION_PRIMITIVE_H

#include "Rigidbody2D.h"

namespace physics
{
	class CollisionPrimitive
	{
	public:
		Rigidbody2D* body;
		Vector2D GetAxisVector(int i);
	};
}


#endif

#ifndef PHYSICS_COLLISION_BOX_H
#define PHYSICS_COLLISION_BOX_H

namespace physics
{

	class CollisionBox : public CollisionPrimitive
	{
	public:
		Vector2D halfSize;
	};
}

#endif

#ifndef PHYSICS_COLLISION_FLOOR_H
#define PHYSICS_COLLISION_FLOOR_H

namespace physics
{

	class CollisionFloor
	{
	public:
		Vector2D direction;
		float offset;
	};
}

#endif



