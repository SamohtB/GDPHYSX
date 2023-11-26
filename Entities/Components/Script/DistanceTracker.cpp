#include "DistanceTracker.h"

#include <corecrt_math_defines.h>

#include "../../../BaseClasses/GameObject.h"

using namespace component;

DistanceTracker::DistanceTracker(std::string name, Vector2D initialPosition) : Component(name, ComponentType::SCRIPT)
{
	this->previousPosition = initialPosition;
	this->distanceTraveled = 0.0f;
}

void DistanceTracker::Perform()
{
	Vector2D currentPosition = this->GetOwner()->GetPosition();

	if(this->previousPosition != currentPosition)
	{
		this->distanceTraveled += GetDistance(previousPosition, currentPosition);
	}
}

float DistanceTracker::GetDistance(Vector2D vectorA, Vector2D vectorB)
{
	float deltaX = vectorB.x - vectorA.x;
    float deltaY = vectorB.y - vectorA.y;

    float distanceSquared = deltaX * deltaX + deltaY * deltaY;
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






