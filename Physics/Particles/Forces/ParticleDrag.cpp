#include "ParticleDrag.h"

using namespace physics;

void ParticleDrag::UpdateForce(Particle2D* particle, float deltaTime)
{
	Vector2D velocity = particle->GetVelocity();
	float m = velocity.SquareMagnitude();

	if (m > 0.0f)
    {
        float dragCoefficient = (k1 * k2 * m) / 2;

        Vector2D force = velocity.Normalize() * -dragCoefficient;
        particle->AddForce(force);
    }
}