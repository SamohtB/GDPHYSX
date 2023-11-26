#include "ParticleAnchoredSpring.h"

using namespace physics;

void ParticleAnchoredSpring::UpdateForce(Particle2D* particle, float deltaTime)
{
	Vector2D d = particle->GetPosition() - *anchor;
	float magnitude = d.GetMagnitude();

	magnitude = -springConstant * (magnitude - restLength);

	d = d.Normalize();
	d *= magnitude;

	particle->AddForce(d);
}