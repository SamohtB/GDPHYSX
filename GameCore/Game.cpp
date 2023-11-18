#include "Game.h"

using namespace gamecore;

Game::Game() : renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Thomas Banatin", sf::Style::Titlebar | sf::Style::Close)
{
	this->renderWindow.setFramerateLimit(FRAME_RATE_LIMIT);
	this->fidgetCenter = new Vector3D(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

    massAggregateSystem = new MassAggregateSystem(Vector3D(), 30, 0.6f);
	
    CreateParticles();
	CreateRodConnections();

	this->particleList[4]->GetParticle()->AddForce(Vector3D(1.0f, 0.0f, 0.0f) * 20000.0f);
}

void Game::CreateParticles()
{
	ParticleObject* particle = new ParticleObject("Center_Particle");
	GameObjectManager::GetInstance()->AddObject(particle);

	particle->GetParticle()->SetMass(50.0f);
	particle->SetRadius(20.0f);
	particle->GetParticle()->SetDamping(1.0f);
	particle->SetParticleColor(sf::Color::White);
	particle->SetPosition(Vector3D(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f));
	this->particleList.push_back(particle);

	for (int i = 0; i < 4; i++)
	{
		particle = new ParticleObject("Outside_Particle_" + std::to_string(i + 1));
		GameObjectManager::GetInstance()->AddObject(particle);

		particle->GetParticle()->SetMass(0.01f);
		particle->SetRadius(15.0f);
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
			this->particleList[i + 1]->GetParticle(), 100.0f);
		VisibleLine* rod = new VisibleLine("Rod_Line", this->particleList[0]->GetParticle()->GetPositionReference(),
			this->particleList[i + 1]->GetParticle()->GetPositionReference());
		GameObjectManager::GetInstance()->AddObject(rod);
	}

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[1]->GetParticle(),
		this->particleList[4]->GetParticle(), 141.5f);
	VisibleLine* rod = new VisibleLine("Rod_Line", this->particleList[1]->GetParticle()->GetPositionReference(),
		this->particleList[4]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[1]->GetParticle(),
		this->particleList[3]->GetParticle(), 141.5f);
	 rod = new VisibleLine("Rod_Line", this->particleList[1]->GetParticle()->GetPositionReference(),
		this->particleList[3]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[2]->GetParticle(),
		this->particleList[4]->GetParticle(), 141.5f);
	rod = new VisibleLine("Rod_Line", this->particleList[2]->GetParticle()->GetPositionReference(),
		this->particleList[4]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);

	massAggregateSystem->AttachParticleToParticleRod(this->particleList[2]->GetParticle(),
		this->particleList[3]->GetParticle(), 141.5f);
	rod = new VisibleLine("Rod_Line", this->particleList[2]->GetParticle()->GetPositionReference(),
		this->particleList[3]->GetParticle()->GetPositionReference());
	GameObjectManager::GetInstance()->AddObject(rod);
}

void Game::Run()
{
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);

    while(this->renderWindow.isOpen()) 
    {
        this->ProcessInput();
        tLastUpdate += CClock.restart();

        while(tLastUpdate > tTimePerFrame) 
        {
            tLastUpdate -= tTimePerFrame;
            this->Update(tTimePerFrame);
        }

        this->Render();
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
    GameObjectManager::GetInstance()->PhysicsUpdate(deltaTime);
	GameObjectManager::GetInstance()->Update(deltaTime);
    massAggregateSystem->Update(deltaTime.asSeconds());
}

void Game::Render()
{
    this->renderWindow.clear();

    GameObjectManager::GetInstance()->Draw(&this->renderWindow);

    this->renderWindow.display();
}