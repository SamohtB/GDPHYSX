#include "NarrowPhase.h"

using namespace physics;

static float TransformToAxis(CollisionBox& box, Vector2D& axis)
{
	return
		box.halfSize.x * std::abs(axis.Dot(box.GetAxisVector(0))) +
		box.halfSize.y * std::abs(axis.Dot(box.GetAxisVector(1)));
}

Vector2D CollisionPrimitive::GetAxisVector(int i)
{
	auto matrix = this->body->transformMatrix.getMatrix();
	return Vector2D(matrix[i*4], matrix[i*4+1]);
}

bool IntersectionTests::BoxAndHalfSpace(CollisionBox& box, CollisionFloor& floor)
{
	float projectedRadius = TransformToAxis(box, floor.direction);

	float boxDistance = floor.direction.Dot(box.GetAxisVector(3)) - projectedRadius;

	return boxDistance <= floor.offset;
}

unsigned CollisionDetector::BoxAndHalfSpace(CollisionBox& box, CollisionFloor& floor, CollisionData* data)
{
	if(data->contactsLeft <= 0) { return 0; }

	if(!IntersectionTests::BoxAndHalfSpace(box, floor)) { return 0;}

	Vector2D corners[4] = {
		Vector2D(-box.halfSize.x, -box.halfSize.y),	//upper left
		Vector2D(box.halfSize.x, -box.halfSize.y),		//upper right
		Vector2D(box.halfSize.x, box.halfSize.y),		//lower right
		Vector2D(-box.halfSize.x, box.halfSize.y)		//lower left
	};

	RigidbodyContact* contact = data->contacts;
	unsigned contactsUsed = 0;

	for(unsigned i = 0; i < 4; i++)
	{
		Vector2D vertexPos = corners[i];
		sf::Vector2f tempPos = box.body->transformMatrix.transformPoint(sf::Vector2f(vertexPos.x, vertexPos.y));

		vertexPos.x = tempPos.x;
		vertexPos.y = tempPos.y;

		float vertexDistance = vertexPos.Dot(floor.direction);

		if(vertexDistance <= floor.offset)
		{
			contact->contactPoint = floor.direction * (vertexDistance - floor.offset);
			contact->contactPoint += vertexPos;
			contact->contactNormal = floor.direction;
			contact->penetration = floor.offset - vertexDistance;

			contact->restitution = data->restitution;
			contact->body[0] = box.body;
			contact->body[1] = nullptr;

			contact++;
			contactsUsed++;

			if(contactsUsed == (unsigned)data->contactsLeft) { return contactsUsed; }
		}
	}

	return contactsUsed;
}


