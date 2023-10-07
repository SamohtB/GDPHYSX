#include "Game.h"

using namespace gamecore;

Game::Game() : renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Thomas Banatin", sf::Style::Titlebar | sf::Style::Close)
{
	this->renderWindow.setFramerateLimit(FRAME_RATE_LIMIT);
    
    this->registry = new ParticleForceRegistry();
    this->isSpacePressed = false;
    this->currentMousePos = Vector3D(450.0f, 450.0f, 0);
    this->previousMousePos = Vector3D(450.0f, 450.0f, 0);

    registry = new ParticleForceRegistry();

    AddParticles();
    AddSprings();
    AddAttachedLines();
    AddDrag();
}

void Game::AddParticles()
{
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j <= 2; j++)
        {
            PhysicsParticle* particle = new PhysicsParticle("Particle_" + std::to_string(i) + "_" + std::to_string(j));
            GameObjectManager::GetInstance()->AddObject(particle);
            particle->SetPosition(i * 300.0f, j * 300.0f, 0.0f);
            particleList.push_back(particle);

            std::cout << particle->GetName() << " Spawned At " << std::to_string(i * 300) 
                << ", " << std::to_string(j * 300) << std::endl;
        }
    }
    
    std::swap(particleList[particleList.size() - 1], particleList[particleList.size() - 2]);
}

void Game::AddSprings()
{
    for(int i = 0; i < 4; i++)
    {
        int nextIndex = (i + 1) % 4;
        ParticleSpring* spring = new ParticleSpring(&this->particleList[nextIndex]->particle, 10.0f, 300.0f);
        this->springList.push_back(spring);
        this->registry->Add(&this->particleList[i]->particle, spring);

        spring = new ParticleSpring(&this->particleList[i]->particle, 10.0f, 300.0f);
        this->springList.push_back(spring);
        this->registry->Add(&this->particleList[nextIndex]->particle, spring);
        
        std::string name = std::to_string(i) + std::to_string(nextIndex);
        VisibleLine* line = new VisibleLine(this->particleList[i]->particle.GetPositionReference(), 
                                        this->particleList[nextIndex]->particle.GetPositionReference(),
                                        name);
        GameObjectManager::GetInstance()->AddObject(line);
    }
}

void Game::AddAttachedLines()
{
    for(PhysicsParticle* particle : this->particleList)
    {
        ParticleAnchoredSpring* spring = new ParticleAnchoredSpring(&this->previousMousePos, 50.0f, 220.0f);
        this->registry->Add(&particle->particle, spring);

        VisibleLine* line = new VisibleLine(particle->particle.GetPositionReference(), 
            &this->previousMousePos, "line_to_center");

        GameObjectManager::GetInstance()->AddObject(line);
    }
}

void Game::AddDrag()
{
    ParticleDrag* drag = new ParticleDrag(0.5f, 0.1f);
    for(PhysicsParticle* particle : particleList)
    {
        this->registry->Add(&particle->particle, drag);
    }
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
            
            case sf::Event::KeyPressed:
                this->ProcessKeyBoardInput(eEvent.key.code, true);
                break;

            case sf::Event::KeyReleased:
                this->ProcessKeyBoardInput(eEvent.key.code, false);
                break;

            default:
                break;
        }
    }
}

void Game::ProcessKeyBoardInput(sf::Keyboard::Key key, bool keyState)
{
    if(key == sf::Keyboard::Space)
    {
        this->isSpacePressed = keyState;
    }
}

void Game::Update(sf::Time deltaTime)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(this->renderWindow);
    this->currentMousePos = Vector3D((float)mousePos.x, (float)mousePos.y, 0);

    if(isSpacePressed)
    {
        Vector3D centerPos = currentMousePos;
        Vector3D force;

        for(PhysicsParticle* particle : particleList)
        {
            Vector3D currentPos = particle->particle.GetPosition();
            force = centerPos - currentPos;
            particle->particle.AddForce(force * 10);
        }

        this->previousMousePos = this->currentMousePos;
    }

    registry->UpdateForces(deltaTime.asSeconds());
    GameObjectManager::GetInstance()->PhysicsUpdate(deltaTime);

    
}

void Game::Render()
{
    this->renderWindow.clear();

    GameObjectManager::GetInstance()->Draw(&this->renderWindow);

    this->renderWindow.display();
}