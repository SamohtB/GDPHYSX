#include "NarrowPhase.h"

using namespace physics;

static float TransformToAxis(CollisionBox& box, Vector2D& axis)
{
	return
		box.halfSize.x * std::abs(axis.Dot(box.GetAxisVector(0))) +
		box.halfSize.y * std::abs(axis.Dot(box.GetAxisVector(1)));
}

Vector2D CollisionPrimitive::GetAxisVector(int i)
{
	auto matrix = this->body->transformMatrix.getMatrix();
	return Vector2D(matrix[i*4], matrix[i*4+1]);
}

bool IntersectionTests::BoxAndHalfSpace(CollisionBox& box, CollisionFloor& floor)
{
	float projectedRadius = TransformToAxis(box, floor.direction);

	float boxDistance = floor.direction.Dot(box.GetAxisVector(3)) - projectedRadius;

	return boxDistance <= floor.offset;
}

