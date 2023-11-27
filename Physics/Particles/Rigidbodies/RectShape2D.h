#pragma once
#ifndef PHYSICS_RECT_SHAPE_2D_H
#define PHYSICS_RECT_SHAPE_2D_H

#include "Shape2D.h"

namespace physics
{
	class RectShape2D : public Shape2D
	{
		public:
		RectShape2D(float width, float height) : width(width), height(height) {}
		float GetInertiaTensor(float mass) override;

	private:
		float width;
		float height;
	};
}


#endif


