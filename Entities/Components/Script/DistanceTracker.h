#pragma once
#ifndef COMPONENT_DISTANCE_TRACKER_H
#define COMPONENT_DISTANCE_TRACKER_H

#include "../../../BaseClasses/Component.h"
#include "../../../BaseClasses/Vector2D.h"

namespace component
{
	using namespace baseclass;

	class DistanceTracker : public Component
	{
	public:
		DistanceTracker(std::string name, Vector2D initialPosition);
		void Perform() override;
		float GetDistanceTraveled();
		float GetNumberOfRevolutions(float radius);

	private:
		float GetDistance(Vector2D vectorA, Vector2D vectorB);
	private:
		Vector2D previousPosition;
		float distanceTraveled;
	};
}


#endif
