#include "Box2D.h"

#include <corecrt_math_defines.h>

using namespace entity;

Box2D::Box2D(std::string name, float width, float height, float mass) : GameObject(name)
{
	this->sfShape = sf::RectangleShape(sf::Vector2f(width, height));
	this->sfShape.setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));
	this->shape = RectShape2D(width, height);

	this->body.SetMass(mass);
	this->body.shape = &this->shape;
}

void Box2D::Initialize()
{
	Renderer* renderer = new Renderer(this->GetName() + "renderer");
	renderer->AssignDrawable(&this->sfShape);
	this->AttachComponent(renderer);
}


void Box2D::PhysicsUpdate(sf::Time deltaTime)
{
	GameObject::PhysicsUpdate(deltaTime);

	Vector2D pos = this->body.GetPosition();
	this->sfShape.setPosition(sf::Vector2f(pos.x, pos.y));
	this->sfShape.setRotation(this->body.rotation * (float)(180.0 / M_PI));
}




