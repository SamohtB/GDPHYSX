#include "Game.h"

using namespace gamecore;

Game::Game() : renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Thomas Banatin", sf::Style::Titlebar | sf::Style::Close)
{
	this->renderWindow.setFramerateLimit(FRAME_RATE_LIMIT);
	this->screenCenter = new Vector3D(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
	this->IsSimulating = true;
	this->timeElapsed = 0.0f;

    massAggregateSystem = new MassAggregateSystem(Vector3D(), 30, 0.6f);
	
    CreateParticles();
	CreateRodConnections();

	massAggregateSystem->AttachParticleToAnchoredCable(particleList[0]->GetParticle(), this->screenCenter, 40.0f, 0.6f);

	this->particleList[4]->GetParticle()->AddForce(Vector3D(1.0f, 0.f, 0.0f) * 20000);

	this->spinner = new FidgetSpinner("Fidget Spinner", particleList[0], particleList[4]);
	GameObjectManager::GetInstance()->AddInFront(spinner);

	distanceTracker = new DistanceTracker("Distance Tracker", particleList[4]->GetPosition());
	particleList[4]->AttachComponent(distanceTracker);
}

void Game::CreateParticles()
{
	ParticleObject* particle = new ParticleObject("Center_Particle");
	GameObjectManager::GetInstance()->AddObject(particle);

	particle->GetParticle()->SetMass(50.0f);
	particle->SetRadius(10.0f);
	particle->GetParticle()->SetDamping(1.0f);
	particle->SetParticleColor(sf::Color::White);
	particle->SetPosition(Vector3D(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f));
	this->particleList.push_back(particle);

	for (int i = 0; i < 4; i++)
	{
		particle = new ParticleObject("Outside_Particle_" + std::to_string(i + 1));
		GameObjectManager::GetInstance()->AddObject(particle);

		particle->GetParticle()->SetMass(0.1f);
		particle->SetRadius(7.5f);
		particle->GetParticle()->SetDamping(0.8f);
		particle->SetParticleColor(sf::Color::Blue);

		Vector3D offset;
		switch (i)
		{
		case 0: // Right
			offset = Vector3D(100.0f, 0.0f, 0.0f);
			break;

		case 1: // Left
			offset = Vector3D(-100.0f, 0.0f, 0.0f);

			break;

		case 2: // Down
			offset = Vector3D(0.0f, 100.0f, 0.0f);
			break;

		case 3: // Up
			offset = Vector3D(0.0f, -100.0f, 0.0f);
			break;

		default:
			std::cout << "OFFSET ERROR" << std::endl;
			break;
		}

		particle->SetPosition(Vector3D(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f) + offset);
		this->particleList.push_back(particle);
	}
}

void Game::CreateRodConnections()
{
	// 0 = center, 1-4 = edges
	for (int i = 0; i < 4; i++)
	{
		massAggregateSystem->AttachParticleToParticleRod(this->particleList[0]->GetParticle(),
			this->particleList[i + 1]->GetParticle(), 
			(particleList[0]->GetParticle()->GetPosition() - particleList[i + 1]->GetParticle()->GetPosition()).GetMagnitude());

		/*VisibleLine* rod = new VisibleLine("Rod_Line", this->particleList[0]->GetParticle()->GetPositionReference(),
			this->particleList[i + 1]->GetParticle()->GetPositionReference());
		GameObjectManager::GetInstance()->AddObject(rod);*/
	}

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[1]->GetParticle(),
		this->particleList[4]->GetParticle(), 
		(particleList[1]->GetParticle()->GetPosition() - particleList[4]->GetParticle()->GetPosition()).GetMagnitude());

	/*VisibleLine* rod = new VisibleLine("Rod_Line", this->particleList[1]->GetParticle()->GetPositionReference(),
		this->particleList[4]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);*/

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[1]->GetParticle(),
		this->particleList[3]->GetParticle(), 
		(particleList[1]->GetParticle()->GetPosition() - particleList[3]->GetParticle()->GetPosition()).GetMagnitude());

	/*rod = new VisibleLine("Rod_Line", this->particleList[1]->GetParticle()->GetPositionReference(),
		this->particleList[3]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);*/

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[2]->GetParticle(),
		this->particleList[4]->GetParticle(), 
		(particleList[2]->GetParticle()->GetPosition() - particleList[4]->GetParticle()->GetPosition()).GetMagnitude());

	/*rod = new VisibleLine("Rod_Line", this->particleList[2]->GetParticle()->GetPositionReference(),
		this->particleList[4]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);*/

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[2]->GetParticle(),
		this->particleList[3]->GetParticle(), 
		(particleList[2]->GetParticle()->GetPosition() - particleList[3]->GetParticle()->GetPosition()).GetMagnitude());

	/*rod = new VisibleLine("Rod_Line", this->particleList[2]->GetParticle()->GetPositionReference(),
		this->particleList[3]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);*/
}

void Game::Run()
{
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);
	bool IsDisplaying = false;

    while(this->renderWindow.isOpen()) 
    {
        this->ProcessInput();
        tLastUpdate += CClock.restart();

        while(tLastUpdate > tTimePerFrame && this->IsSimulating) 
        {
            tLastUpdate -= tTimePerFrame;
            this->Update(tTimePerFrame);
        }

        this->Render();

		if(!this->IsSimulating && IsDisplaying == false)
		{
			IsDisplaying = true;
			DisplayResults();
		}
    }
}

void Game::ProcessInput()
{
    sf::Event eEvent;

    while(this->renderWindow.pollEvent(eEvent)) 
    {
        switch(eEvent.type) 
        {
            case sf::Event::Closed:
                this->renderWindow.close();
                break;

            default:
                GameObjectManager::GetInstance()->ProcessInput(eEvent);
                break;
        }
    }
}

void Game::Update(sf::Time deltaTime)
{
	spinner->SetPosition(this->particleList[0]->GetPosition());
    GameObjectManager::GetInstance()->PhysicsUpdate(deltaTime);
	massAggregateSystem->Update(deltaTime.asSeconds());
	GameObjectManager::GetInstance()->Update(deltaTime);

	this->IsSimulating = CheckSpeed();
	this->timeElapsed += deltaTime.asSeconds();
}

void Game::Render()
{
    this->renderWindow.clear();

    GameObjectManager::GetInstance()->Draw(&this->renderWindow);

    this->renderWindow.display();
}

void Game::DisplayResults()
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Spinner has completed : " << this->distanceTracker->GetNumberOfRevolutions(100.0f) << " revolutions" << std::endl;
	std::cout << "Spinner took " << this->timeElapsed << " secs to reach minimum speed" << std::endl;
}

bool Game::CheckSpeed()
{
	if(this->particleList[4]->GetParticle()->GetVelocity().GetMagnitude() <= 10.0f)
	{
		return false;
	}

	return true;
}

