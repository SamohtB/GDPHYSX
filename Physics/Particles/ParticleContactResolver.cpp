#include "ParticleContactResolver.h"

using namespace physics;

void ParticleContactResolver::ResolveContacts(ParticleContact* contactArray, unsigned numContacts, float duration)
{
	for(int i = 0; i < iterations; i++)
	{
		float max = 0.0f;
		unsigned maxIndex = numContacts;

		for(int i = 0; i < numContacts; i++)
		{
			float separationValue = contactArray[i].CalculateSeparatingVelocity();

			if(separationValue < max && (separationValue < 0 || contactArray[i].penetration > 0))
			{
				max = separationValue;
				maxIndex = i;
			}
		}

		contactArray[maxIndex].Resolve(duration);
	}
}