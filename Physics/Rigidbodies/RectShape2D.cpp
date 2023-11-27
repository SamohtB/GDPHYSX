#include "RectShape2D.h"

using namespace physics;

RectShape2D::RectShape2D(float width, float height) : width(width), height(height) {}

float RectShape2D::GetInertiaTensor(float mass)
{
	return (mass * (this->width * this->width + this->height * this->height)) / 12.0f;
}