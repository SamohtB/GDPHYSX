#pragma once
#ifndef PHYSICS_CIRCLE_SHAPE_2D_H
#define PHYSICS_CIRCLE_SHAPE_2D_H

#include "Shape2D.h"

namespace physics
{
	class CircleShape2D : public Shape2D
	{
	public:
		CircleShape2D(float radius) : radius(radius) {}
		float GetInertiaTensor(float mass) override;

	private:
		float radius;
		
	};
}

#endif


