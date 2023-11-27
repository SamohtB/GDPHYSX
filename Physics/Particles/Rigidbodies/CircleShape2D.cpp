#include "CircleShape2D.h"

using namespace physics;

float CircleShape2D::GetInertiaTensor(float mass)
{
	return (mass * this->radius * this->radius) / 12.0f;
}

