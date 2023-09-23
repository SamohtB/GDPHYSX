#include "Particles3D.h"

using namespace physics;


void Particles3D::SetDamping(float damping)
{
	this->damping = damping;
}

float Particles3D::GetDamping()
{
	return this->damping;
}

void Particles3D::SetMass(float mass)
{
	assert(mass != 0);
	this->inverseMass = 1.0f / mass;
}

float Particles3D::GetMass()
{
	if(this->inverseMass == 0)
	{
		return FLT_MAX;
	}

	return 1.0f / this->inverseMass;
}
		
void Particles3D::SetVelocity(Vector3D velocity)
{
	this->velocity = velocity;
}

Vector3D Particles3D::GetVelocity()
{
	return this->velocity;
}

void Particles3D::SetAcceleration(Vector3D acceleration)
{
	this->acceleration = acceleration;
}

Vector3D Particles3D::GetAcceleration()
{
	return this->acceleration;
}

void Particles3D::SetPosition(Vector3D position)
{
	this->position = position;
}

Vector3D Particles3D::GetPosition()
{
	return this->position;
}

void Particles3D::Integrate(float deltaTime)
{
	this->position += this->velocity * deltaTime;
	this->velocity += this->acceleration * deltaTime;
	this->velocity *= std::powf(damping, deltaTime); 
}