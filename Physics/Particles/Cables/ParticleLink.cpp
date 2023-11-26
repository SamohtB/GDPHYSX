#include "ParticleLink.h"

using namespace physics;

float ParticleLink::CurrentLength()
{
	Vector2D relativePos = particles[0]->GetPosition() - particles[1]->GetPosition();
	return relativePos.GetMagnitude();
}
