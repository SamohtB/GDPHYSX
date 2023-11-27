#pragma once
#ifndef ENTITY_BOX_2D_H
#define ENTITY_BOX_2D_H

#include "SFML/Graphics.hpp"
#include "../BaseClasses/GameObject.h"
#include "../Physics/Rigidbodies/Rigidbody2D.h"
#include "../Physics/Rigidbodies/RectShape2D.h"

namespace entity
{
	using namespace baseclass;
	using namespace physics;

	class Box2D : public GameObject
	{
	public:
		Rigidbody2D body;
		RectShape2D shape;
		sf::RectangleShape sfShape;

		Box2D(std::string name, float width, float height, float mass);
		void Initialize() override;
		void PhysicsUpdate(sf::Time deltaTime) override;
	};
}


#endif


