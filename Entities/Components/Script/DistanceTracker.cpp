#include "DistanceTracker.h"

#include <corecrt_math_defines.h>

#include "../../../BaseClasses/GameObject.h"

using namespace component;

DistanceTracker::DistanceTracker(std::string name, Vector3D initialPosition) : Component(name, ComponentType::SCRIPT)
{
	this->previousPosition = initialPosition;
	this->distanceTraveled = 0.0f;
}

void DistanceTracker::Perform()
{
	Vector3D currentPosition = this->GetOwner()->GetPosition();

	if(this->previousPosition != currentPosition)
	{
		this->distanceTraveled += GetDistance(previousPosition, currentPosition);
	}
}

float DistanceTracker::GetDistance(Vector3D vectorA, Vector3D vectorB)
{
	float deltaX = vectorB.x - vectorA.x;
    float deltaY = vectorB.y - vectorA.y;
    float deltaZ = vectorB.z - vectorA.z;

    float distanceSquared = deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ;
    float distance = std::sqrt(distanceSquared);

    return distance;
}

float DistanceTracker::GetDistanceTraveled()
{
	return this->distanceTraveled;
}

float DistanceTracker::GetNumberOfRevolutions(float radius)
{
	float circumference = 2 * static_cast<float>(M_PI) * radius;
	return this->distanceTraveled / circumference;
}






