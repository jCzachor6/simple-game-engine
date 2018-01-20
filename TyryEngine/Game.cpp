#include "Game.h"


Game::Game(std::string name, int screenWidth, int screenHeight, long gameDetails)
{
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), name, sf::Style::Default);
	window->setFramerateLimit(60);
}

void Game::Run(StatePtr state)
{
	gsm.AddState(std::move(state));
	Loop();
}

Game::~Game()
{
	delete this->window;
}

void Game::Loop()
{
	while (window->isOpen()) {
		gsm.ProcessChanges();
		gsm.CurrentState()->HandleEvents();
		gsm.CurrentState()->Update(1.0f);

		window->clear();
		gsm.CurrentState()->Render(window);
		window->display();
	}
}