#include "ParticleGravity.h"

using namespace physics;

void ParticleGravity::UpdateForce(Particles3D* particle, float duration)
{
	particle->AddForce(gravity * particle->GetMass());
}