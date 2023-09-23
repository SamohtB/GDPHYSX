#include "ParticleDrag.h"

using namespace physics;

void ParticleDrag::UpdateForce(Particles3D* particle, float deltaTime)
{
	Vector3D velocity = particle->GetVelocity();

	float m = velocity.SquareMagnitude();
	float dragCoefficient = (k1 * k2 * m) / 2;

	Vector3D force = velocity.Normalize() * -dragCoefficient;
	particle->AddForce(force);
}