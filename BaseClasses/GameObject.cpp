#include "GameObject.h"

using namespace baseclass;

GameObject::GameObject(std::string name)
{
    this->name = name;
}

void GameObject::ProcessInput(sf::Event event)
{
	
}

void GameObject::Update(sf::Time deltaTime)
{

}

void GameObject::PhysicsUpdate(sf::Time deltaTime)
{

}

void GameObject::Draw(sf::RenderWindow* window, sf::RenderStates renderStates)
{

}

std::string GameObject::GetName()
{
	return this->name;
}

ObjectType GameObject::GetObjectType()
{
	return this->objectType;
}