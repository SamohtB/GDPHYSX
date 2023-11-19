#pragma once
#ifndef ENTITY_FIDGET_SPINNER_H
#define ENTITY_FIDGET_SPINNER_H

#include "ParticleObject.h"
#include "Components/Renderer/Renderer.h"

namespace entity
{
	using namespace baseclass;
	using namespace component;

	class FidgetSpinner : public GameObject
	{
	public:
		FidgetSpinner(std::string name, ParticleObject* center, ParticleObject* top);
		void Initialize() override;
		void Update(sf::Time deltaTime) override;

	private:
		sf::Texture texture;
		ParticleObject* center;
		ParticleObject* top;
	};
}


#endif


