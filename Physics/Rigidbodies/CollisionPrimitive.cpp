#include "CollisionPrimitive.h"

using namespace physics;

Vector2D CollisionPrimitive::GetAxisVector(int i)
{
	auto matrix = this->body->transformMatrix.getMatrix();
	return Vector2D(matrix[i*4], matrix[i*4+1]);
}
