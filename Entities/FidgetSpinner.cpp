#include "FidgetSpinner.h"

#include <corecrt_math_defines.h>

using namespace entity;

FidgetSpinner::FidgetSpinner(std::string name, ParticleObject* center, ParticleObject* top) : GameObject(name), center(center), top(top)
{
	this->isEnabled = true;
}

void FidgetSpinner::Initialize()
{
	if (!texture.loadFromFile("Assets/shuriken.png")) 
	{
		std::cout << "Error loading texture!" << std::endl;
	}

	this->sprite = new sf::Sprite();
	sprite->setTexture(texture);
	sprite->setScale(0.5f, 0.5f);
	sprite->setOrigin(sprite->getLocalBounds().width / 2.0f, sprite->getLocalBounds().height / 2.0f);

	Renderer* renderer = new Renderer(this->name + " Renderer");
	renderer->AssignDrawable(this->sprite);
	this->AttachComponent(renderer);
}

void FidgetSpinner::Update(sf::Time deltaTime)
{
	GameObject::Update(deltaTime);

	Vector3D up = this->center->GetPosition() + Vector3D(0.0f, -100.0f, 0.0f);

	float deltaX = top->GetPosition().x - center->GetPosition().x;
	float deltaY = top->GetPosition().y - center->GetPosition().y;

	float theta = atan2(deltaY, deltaX);
	theta *= 57.3f;

	this->sprite->setRotation(theta);
}



