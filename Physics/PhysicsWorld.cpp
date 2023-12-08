#include "PhysicsWorld.h"

using namespace physics;

PhysicsWorld::PhysicsWorld(unsigned maxContacts, unsigned iterations) : maxContacts(maxContacts)
{
	calculateIterations = (iterations == 0);
}

PhysicsWorld::~PhysicsWorld()
{
	rigidbodyList.clear();
}

void PhysicsWorld::StartFrame()
{
	for(auto r = rigidbodyList.begin(); r != rigidbodyList.end(); r++)
	{
		(*r)->ClearAccumulator();
	}
}

void PhysicsWorld::Integrate(float deltaTime)
{
	for(auto r = rigidbodyList.begin(); r != rigidbodyList.end(); r++)
	{
		(*r)->Integrate(deltaTime);
	}
}

void PhysicsWorld::RunPhysics(float deltaTime)
{
	//StartFrame();
	registry.UpdateForces(deltaTime);	
	Integrate(deltaTime);
}
