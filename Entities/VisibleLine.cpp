#include "VisibleLine.h"

using namespace entity;

VisibleLine::VisibleLine(Vector3D* startPoint, Vector3D* endPoint, std::string name) : GameObject(name)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

void VisibleLine::Initialize() 
{
	this->objectType = ObjectType::LINE;
}

void VisibleLine::Draw(sf::RenderWindow* renderWindow, sf::RenderStates renderStates)
{
	sf::Vertex vertices[2] 
	{
		sf::Vector2f(startPoint->x, startPoint->y),
		sf::Vector2f(endPoint->x, endPoint->y)
	};

	renderWindow->draw(vertices, 2, sf::Lines, renderStates);
}