#include "PhysicsParticle.h"

using namespace entity;

PhysicsParticle::PhysicsParticle(std::string name) : GameObject(name), sf::CircleShape()
{

}

void PhysicsParticle::Initialize()
{
	this->setRadius(50.0f);
	this->setFillColor(sf::Color::Green);
	this->setOrigin(50.0f, 50.0f);
	this->particle.SetMass(1);
}

void PhysicsParticle::PhysicsUpdate(sf::Time deltaTime)
{
	this->particle.Integrate(deltaTime.asSeconds());
	this->setPosition(this->particle.GetPosition().x, this->particle.GetPosition().y);
}

void PhysicsParticle::Draw(sf::RenderWindow* renderWindow, sf::RenderStates renderStates)
{
	renderWindow->draw(*this, renderStates);
}

void PhysicsParticle::SetPosition(float x, float y, float z)
{
	this->particle.SetPosition(Vector3D(x, y, z));
	this->setPosition(x, y);
}