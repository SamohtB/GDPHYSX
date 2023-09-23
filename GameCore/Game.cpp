#include "Game.h"

using namespace gamecore;

Game::Game() : renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Thomas Banatin", sf::Style::Titlebar | sf::Style::Close)
{
	this->renderWindow.setFramerateLimit(FRAME_RATE_LIMIT);
    SetRunners();

    this->isRaceEnd = false;
    this->timeElapsed = 0.0f;
}

void Game::SetRunners()
{
    this->runnerList.push_back(new Runner(
            Vector3D(50.0f, 200.0f, 0.0f),  // initial position
            Vector3D(35.0f, 0.0f, 0.0f),    // initial velocity
            Vector3D(8.0f, 0.0f, 0.0f))     // initial acceleration
    );

    this->runnerList.push_back(new Runner(
            Vector3D(50.0f, 350.0f, 0.0f),  // initial position
            Vector3D(26.0f, 0.0f, 0.0f),    // initial velocity
            Vector3D(11.0f, 0.0f, 0.0f))     // initial acceleration
    );

    this->runnerList.push_back(new Runner(
            Vector3D(50.0f, 500.0f, 0.0f),  // initial position
            Vector3D(55.0f, 0.0f, 0.0f),    // initial velocity
            Vector3D(3.0f, 0.0f, 0.0f))     // initial acceleration
    );
    
    this->runnerList[0]->SetName("Bourbon");
    this->runnerList[0]->setFillColor(sf::Color::White);

    this->runnerList[1]->SetName("Creek");
    this->runnerList[1]->setFillColor(sf::Color::Blue);
    
    this->runnerList[2]->SetName("Scarlet");
    this->runnerList[2]->setFillColor(sf::Color::Red);

    this->finishLine = new sf::RectangleShape(sf::Vector2f(5.0f, 720.0f));
    this->finishLine->setPosition(550.0f, 0.0f);
    this->finishLine->setFillColor(sf::Color::Green);
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
                break;
        }
    }
}

void Game::Update(sf::Time deltaTime)
{
    if(isRaceEnd) { return; }

    this->timeElapsed += deltaTime.asSeconds();

    for(Runner* runner : this->runnerList)
    {
        runner->PhysicsUpdate(deltaTime.asSeconds());

        if(runner->particle.GetPosition().x >= 550.0f && runner->IsFinished() == false)
        {
            runner->IsFinished(true);

            RaceMetrics metrics;
            metrics.name = runner->GetName();
            metrics.velocityMagnitude = runner->particle.GetVelocity().GetMagnitude();
            metrics.timeToComplete = this->timeElapsed;
            metrics.averageVelocity = 500.0f / this->timeElapsed;

            this->raceMetrics.push_back(metrics);
        }
    }

    if(this->raceMetrics.size() >= 3)
    {
        isRaceEnd = true;
        std::cout << std::setprecision(3);
        for(int i = 0; i < this->raceMetrics.size(); i++)
        {
            DisplayResults(this->raceMetrics[i], i + 1);
        }
    }
}

void Game::Render()
{
    this->renderWindow.clear();
    
    for(Runner* runner : this->runnerList)
    {
        this->renderWindow.draw(*runner);
    }

    this->renderWindow.draw(*this->finishLine);

    this->renderWindow.display();
}

void Game::DisplayResults(RaceMetrics metrics, int place)
{
    std::string podiumPlace;
    switch(place)
    {
        case 1:
            podiumPlace = "1st";
            break;
        case 2:
            podiumPlace = "2nd";
            break;
        case 3:
            podiumPlace = "3rd";
    }

    std::cout << metrics.name << " " << podiumPlace << std::endl;
    std::cout << "Mag. of velocity at finish line " << metrics.velocityMagnitude << "m/s" << std::endl;
    std::cout << "Ave. velocity in last 500m " << metrics.averageVelocity << "m/s" << std::endl;
    std::cout << "Sprint Time: " << metrics.timeToComplete << " secs" << std::endl << std::endl;
}