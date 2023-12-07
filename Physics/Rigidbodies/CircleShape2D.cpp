#include "CircleShape2D.h"

using namespace physics;

float CircleShape2D::GetInertiaTensor(float mass)
{
	return mass * this->radius * this->radius * 0.4f;
}

