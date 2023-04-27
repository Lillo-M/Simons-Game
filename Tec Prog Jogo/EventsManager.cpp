#include "EventsManager.h"
#define VVV 10
#include <iostream>
EventsManager::~EventsManager()
{
}
EventsManager::EventsManager(sf::RenderWindow& wds, Player& pP):
	kb(),
	window(&wds),
	player(&pP)
{
}

void EventsManager::Manage()
{
	sf::Event evente;
	//window->waitEvent(evente);
	while (window->pollEvent(evente))
	{
		if (evente.type == sf::Event::KeyPressed)
		{
			if (evente.key.code == sf::Keyboard::W && player->getGrounded())
			{
				player->addVelocity(sf::Vector2f(0, -30 * VVV));
				player->setGrounded(false);
			}
			if (evente.key.code == sf::Keyboard::A)
			{
				player->addVelocity(sf::Vector2f(-VVV, 0));
			}
			if (evente.key.code == sf::Keyboard::S)
			{
				player->addVelocity(sf::Vector2f(0, VVV));
			}
			if (evente.key.code == sf::Keyboard::D)
			{
				player->addVelocity(sf::Vector2f(VVV, 0));
			}
		}
		if (evente.type == sf::Event::KeyReleased)
		{
			if (evente.key.code == sf::Keyboard::A)
			{
				player->addVelocity(sf::Vector2f(-VVV, 0));
			}
			if (evente.key.code == sf::Keyboard::S)
			{
				player->addVelocity(sf::Vector2f(0, VVV));
			}
			if (evente.key.code == sf::Keyboard::D)
			{
				player->addVelocity(sf::Vector2f(VVV, 0));
			}
		}
		if (evente.type == sf::Event::Closed)
			window->close();
		
		/*if (kb.isKeyPressed(sf::Keyboard::W) && player->getGrounded())
		{
			player->addVelocity(sf::Vector2f(0, -15 * VVV));
			player->setGrounded(false);
		}

		if (kb.isKeyPressed(sf::Keyboard::A))
			player->addVelocity(sf::Vector2f(-VVV, 0));
		if (kb.isKeyPressed(sf::Keyboard::S))
			player->addVelocity(sf::Vector2f(0, VVV));
		if (kb.isKeyPressed(sf::Keyboard::D))
			player->addVelocity(sf::Vector2f(VVV, 0));*/
	}
}


