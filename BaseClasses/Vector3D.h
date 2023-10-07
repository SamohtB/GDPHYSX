#pragma once
#ifndef VECTORS_3D_H
#define VECTORS_3D_H

#include <iostream>
#include <cmath>

namespace vectors
{
	class Vector3D
	{
		public:
			Vector3D();
			Vector3D(float x, float y, float z);
			~Vector3D() = default;

		public:
			Vector3D operator+(Vector3D vectorB) const;
			Vector3D operator+=(Vector3D vectorB);
			Vector3D operator-(Vector3D vectorB) const;
			Vector3D operator-=(Vector3D vectorB);
			Vector3D operator*(float scalar) const;
			Vector3D operator*=(float scalar);

			void Zero();

			float DotProduct(Vector3D vectorB);
			Vector3D CrossProduct(Vector3D vectorB);

			Vector3D Normalize();
			float GetMagnitude();
			float SquareMagnitude();

		public:
			float x;
			float y;
			float z;
	};
}

#endif




