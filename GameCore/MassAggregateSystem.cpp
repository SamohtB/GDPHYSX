#include "MassAggregateSystem.h"

using namespace gamecore;

MassAggregateSystem::MassAggregateSystem(Vector3D gravity, int maxContacts, float restitution)
{
	this->particleWorld = new ParticleWorld(maxContacts);
	this->gravity = new ParticleGravity(gravity);
	this->overlapContact = new ParticleOverlapContact(restitution);

	this->particleWorld->particleContactGeneratorList.push_back(overlapContact);
}

MassAggregateSystem::~MassAggregateSystem()
{
	delete this->particleWorld;
	delete this->gravity;
	delete this->overlapContact;
}


void MassAggregateSystem::Update(float deltaTime)
{
	this->particleWorld->RunPhysics(deltaTime);
}


void MassAggregateSystem::AddParticle(Particle3D* particle, bool hasGravity, bool hasOverlap)
{
	if (std::find(this->particleWorld->particleList.begin(), this->particleWorld->particleList.end(), particle) 
		!= this->particleWorld->particleList.end())
    {
        return;
    }

	this->particleWorld->particleList.push_back(particle);

	if(hasOverlap)
	{
		this->overlapContact->AddParticle(particle);
	}

	if(hasGravity)
	{
		this->particleWorld->registry.Add(particle, this->gravity);
	}
}

void MassAggregateSystem::AttachParticleToParticleSpring(Particle3D* particle1, Particle3D* particle2, float springConstant, float restLength, bool hasGravity)
{
	this->AddParticle(particle1, hasGravity, true);
	this->AddParticle(particle2, hasGravity, true);

	ParticleSpring* particleSpring1 = new ParticleSpring(particle2, springConstant, restLength);
	this->particleWorld->registry.Add(particle1, particleSpring1);

	ParticleSpring* particleSpring2 = new ParticleSpring(particle1, springConstant, restLength);
	this->particleWorld->registry.Add(particle2, particleSpring2);
}

void MassAggregateSystem::AttachParticleToParticleRod(Particle3D* particle, Particle3D* particle2, float maxLength, bool hasGravity)
{
	this->AddParticle(particle, hasGravity, true);
	this->AddParticle(particle2, hasGravity, true);

	ParticleRod* particleRod = new ParticleRod();

	particleRod->length = maxLength;
	particleRod->particles[0] = particle;
	particleRod->particles[1] = particle2;

	this->particleWorld->particleContactGeneratorList.push_back(particleRod);
}

void MassAggregateSystem::AttachParticleToAnchoredSpring(Particle3D* particle, Vector3D* anchor, float springConstant, float restLength, bool hasGravity)
{
	this->AddParticle(particle, hasGravity, true);

	ParticleAnchoredSpring* anchoredSpring = new ParticleAnchoredSpring(anchor, springConstant, restLength);
	this->particleWorld->registry.Add(particle, anchoredSpring);
}

void MassAggregateSystem::AttachParticleToAnchoredCable(Particle3D* particle, Vector3D* anchor, float maxLength, float restitution, bool hasGravity)
{
	this->AddParticle(particle, hasGravity, true);
	
	ParticleAnchoredCable* anchoredCable = new ParticleAnchoredCable(maxLength, restitution, anchor);
	anchoredCable->particles[0] = particle;

	this->particleWorld->particleContactGeneratorList.push_back(anchoredCable);
}