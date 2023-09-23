#include "Particles3D.h"

using namespace physics;

Particles3D::Particles3D()
{
	this->inverseMass = 0;
	this->damping = 0.99f;

	this->position = Vector3D();
	this->velocity = Vector3D();
	this->acceleration = Vector3D();
	this->forceAccumulator = Vector3D();
}

void Particles3D::Integrate(float deltaTime)
{
	this->position += this->velocity * deltaTime;

	Vector3D resultingAcceleration = this->acceleration;
	resultingAcceleration += forceAccumulator * inverseMass;
	this->velocity += this->acceleration + resultingAcceleration * deltaTime;

	this->velocity *= std::powf(damping, deltaTime);
	this->ClearAccumulator();
}

void Particles3D::AddForce(Vector3D force)
{
	this->forceAccumulator += force;
}

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

void Particles3D::ClearAccumulator()
{
	this->forceAccumulator.Zero();
}
