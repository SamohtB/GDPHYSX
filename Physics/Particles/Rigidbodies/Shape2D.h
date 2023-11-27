#pragma once
#ifndef PHYSICS_SHAPE_2D_H
#define PHYSICS_SHAPE_2D_H

namespace physics
{
	class Shape2D
	{
	public:
		virtual float GetInertiaTensor(float mass) = 0;
	};
}


#endif

