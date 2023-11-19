#pragma once
#ifndef COMPONENT_DISTANCE_TRACKER_H
#define COMPONENT_DISTANCE_TRACKER_H

#include "../../../BaseClasses/Component.h"
#include "../../../BaseClasses/Vector3D.h"

namespace component
{
	using namespace baseclass;

	class DistanceTracker : public Component
	{
	public:
		DistanceTracker(std::string name, Vector3D initialPosition);
		void Perform() override;
		float GetDistanceTraveled();
		float GetNumberOfRevolutions(float radius);

	private:
		float GetDistance(Vector3D vectorA, Vector3D vectorB);
	private:
		Vector3D previousPosition;
		float distanceTraveled;
	};
}


#endif