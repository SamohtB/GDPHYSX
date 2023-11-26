#include "ParticleGroundContact.h"

using namespace physics;

ParticleGroundContact::ParticleGroundContact(float yLimit, float restitution) : yLimit(yLimit), restitution(restitution) {}

unsigned ParticleGroundContact::FillContact(ParticleContact* contact, unsigned limit)
{
	unsigned count = 0;
	for(auto p = particleList.begin(); p != particleList.end(); p++)
	{
		float deltaY = yLimit - (*p)->GetPosition().y - (*p)->GetRadius();
		if(deltaY < 0.0f)
		{
			contact->contactNormal = Vector2D(0, -1.0f);
			contact->particles[0] = *p;
			contact->particles[1] = nullptr;
			contact->penetration = -deltaY;
			contact->restitution = restitution;
			contact++;
			count++;
		}

		if(count >= limit)
		{
			return count;
		}
	}

	return count;
}

void ParticleGroundContact::AddParticle(Particle2D* particle)
{
	this->particleList.push_back(particle);
}

