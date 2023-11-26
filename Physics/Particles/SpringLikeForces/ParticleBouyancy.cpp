#include "ParticleBouyancy.h"

using namespace physics;

void ParticleBouyancy::UpdateForce(Particle2D* particle, float deltaTime)
{
	float depth = particle->GetPosition().y;

	if(depth <= waterHeight - maxDepth) { return; }

	Vector2D force = Vector2D();

	if(depth >= waterHeight + maxDepth)
	{
		force.y = -liquidDensity * volume;
		particle->AddForce(force);
		return;
	}

	force.y = liquidDensity * volume * (waterHeight - depth + maxDepth) / (2 * maxDepth);
	particle->AddForce(force);
}