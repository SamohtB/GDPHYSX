#include "Rigidbody2D.h"

using namespace physics;

void Rigidbody2D::AddForceOnPoint(Vector2D point, Vector2D force)
{
	this->forceAccumulator += force;
	this->torqueAccumulator += point.Cross(force);
}

void Rigidbody2D::Integrate(float deltaTime)
{
	Particle2D::Integrate(deltaTime);

	this->rotation += this->angularVelocity * deltaTime;

	float intertiaTensor = this->shape->GetInertiaTensor(this->GetMass());

	this->angularVelocity += this->torqueAccumulator * (1.0f / intertiaTensor) * deltaTime;

	this->angularVelocity *= std::pow(this->angularDamping, deltaTime);

	this->ClearTorqueAccumulator();
}

void Rigidbody2D::ClearTorqueAccumulator()
{
	this->torqueAccumulator = 0.0f;	
}


