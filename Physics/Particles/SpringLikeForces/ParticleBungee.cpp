#include "ParticleBungee.h"

using namespace physics;

void ParticleBungee::UpdateForce(Particle2D* particle, float deltaTime)
{
	Vector2D d = particle->GetPosition() - this->other->GetPosition();

	float magnitude = d.GetMagnitude();
	if(magnitude <= this->restLength) { return; }
	magnitude = -springConstant * (magnitude - restLength);

	d = d.Normalize();
	d *= magnitude;
	particle->AddForce(d);
}