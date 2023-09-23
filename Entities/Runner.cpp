#include "Runner.h"

using namespace entity;

Runner::Runner(Vector3D initialPosition, Vector3D initialVelocity, Vector3D initialAcceleration) 
: sf::CircleShape()
{
	this->particle.SetPosition(initialPosition);
	this->particle.SetVelocity(initialVelocity);
	this->particle.SetAcceleration(initialAcceleration);
	this->particle.SetMass(1.0f);
	this->particle.SetDamping(0.99f);

	this->setRadius(25.0f);
	this->setOrigin(50.0f, 25.0f);
	this->isFinished = false;
}

void Runner::PhysicsUpdate(float deltaTime)
{
	this->particle.Integrate(deltaTime);
	this->setPosition(this->particle.GetPosition().x, this->particle.GetPosition().y);
}

void Runner::IsFinished(bool state)
{
	this->isFinished = state;
}

bool Runner::IsFinished()
{
	return this->isFinished;
}

void Runner::SetName(std::string name)
{
	this->name = name;
}

std::string Runner::GetName()
{
	return this->name;
}