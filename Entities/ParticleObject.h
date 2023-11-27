#pragma once
#ifndef ENTITY_PARTICLE_OBJECT_H
#define ENTITY_PARTICLE_OBJECT_H

#include "../BaseClasses/GameObject.h"
#include "Components/Renderer/Renderer.h"
#include "../Physics/Particles/Particle2D.h"

namespace entity
{
	using namespace baseclass;
	using namespace physics;

	class ParticleObject : public GameObject
	{
	public:
		ParticleObject(std::string name);
		void Initialize() override;

		Vector2D GetPosition() override;
		void SetPosition(Vector2D position) override;
		void Move(Vector2D displacement) override;
		void PhysicsUpdate(sf::Time deltaTime) override;

		Particle2D* GetParticle();
		void SetParticleColor(sf::Color color);
		void SetEnabledStatus(bool status) override;
		void SetRenderedImage(sf::Texture& texture);
		void SetRadius(float radius);

		void Reset();

	private:
		sf::CircleShape* renderedObject;
		Particle2D* particle;
		bool hasSprite;

	};
}


#endif // !ENTITY_PARTICLE_OBJECT_H



