#pragma once
#ifndef ENTITY_VISIBLE_LINE_H
#define ENTITY_VISIBLE_LINE_H

#include "../BaseClasses/Vector3D.h"
#include "../BaseClasses/GameObject.h"

namespace entity
{
	using namespace baseclass;

	class VisibleLine : public GameObject
	{
	public:
		VisibleLine(Vector3D* startPoint, Vector3D* endPoint, std::string name);
		void Initialize();
		void Draw(sf::RenderWindow* renderWindow, sf::RenderStates renderStates) override;
		

	private:
		Vector3D* startPoint;
		Vector3D* endPoint;
	};
}


#endif // !ENTITY_VISIBLE_LINE_H



