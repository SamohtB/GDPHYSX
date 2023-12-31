#include "Game.h"

using namespace gamecore;

Game::Game() : renderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Thomas Banatin", sf::Style::Titlebar | sf::Style::Close)
{
	this->renderWindow.setFramerateLimit(FRAME_RATE_LIMIT);
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
}

void Game::Render()
{
    this->renderWindow.clear();

    GameObjectManager::GetInstance()->Draw(&this->renderWindow);

    this->renderWindow.display();
}