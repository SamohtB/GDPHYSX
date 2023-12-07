#pragma once
#ifndef PHYSICS_INTERSECTION_TESTS_H
#define PHYSICS_INTERSECTION_TESTS_H

#include "CollisionPrimitive.h"

namespace physics
{
	class IntersectionTests
	{
	public:
		static bool BoxAndHalfSpace(CollisionBox &box, CollisionFloor& floor)
		{
			float projectedRadius = TrasformToAxis(box, floor.direction);

			float boxDistance = floor.direction.Dot(box.GetAxisVector(3))- projectedRadius;

			return boxDistance <= floor.offset;
		}

		static inline float TransformToAxis(CollisionBox &box, Vector2D &axis)
		{
			return
				box.halfSize.x * std::abs(axis.Dot(box.GetAxisVector(0))) +
				box.halfSize.y * std::abs(axis.Dot(box.GetAxisVector(1)));
		}
	};
}

#endif
