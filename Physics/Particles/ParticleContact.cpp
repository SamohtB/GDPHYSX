#include "ParticleContact.h"

using namespace physics;

float ParticleContact::CalculateSeparatingVelocity()
{
	Vector3D relativeVelocity = this->particles[0]->GetVelocity();

	if(particles[1]) 
	{
		relativeVelocity -= particles[1]->GetVelocity();
	}

	return relativeVelocity.DotProduct(this->contactNormal);
}

void ParticleContact::ResolveVelocity(float deltaTime)
{
	float separatingVelocity = CalculateSeparatingVelocity();

	if(separatingVelocity > 0)	{ return; }

	float newSeparatingVelocity = -restituion * separatingVelocity;

	float deltaVelocity = newSeparatingVelocity - separatingVelocity;

	float totalInverseMass = this->particles[0]->GetInverseMass();
	
	if(this->particles[1])
	{
		totalInverseMass +=	particles[1]->GetInverseMass();
	}

	if(totalInverseMass <= 0) { return; }


}