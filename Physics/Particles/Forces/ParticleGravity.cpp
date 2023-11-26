#include "ParticleGravity.h"

using namespace physics;

void ParticleGravity::UpdateForce(Particle2D* particle, float duration)
{
	particle->AddForce(gravity * particle->GetMass());
}