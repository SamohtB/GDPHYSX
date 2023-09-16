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
			Vector3D operator+(Vector3D other);
			Vector3D& operator+=(Vector3D other);
			Vector3D operator-(Vector3D other);
			Vector3D& operator-=(Vector3D other);
			Vector3D operator*(float multiplier);
			Vector3D& operator*=(float multiplier);

			float DotProduct(Vector3D vectorB);
			Vector3D CrossProduct(Vector3D vectorB);

			Vector3D Normalize();
			float GetMagnitude();
	
			float GetX();
			float GetY();
			float GetZ();

		private:
			float _x;
			float _y;
			float _z;
	};
}

#endif





