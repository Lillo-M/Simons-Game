#include "../include/Ente.h"
#include <iostream>

void Ente::setWindow(sf::RenderWindow &wds)
{
    if (!&wds)
	{
		std::cout << std::endl
				  << "ERROR: NULL Window pointer" << std::endl;
		exit(1);
	}
	Ente::window = &wds;
}
const std::string Ente::getID() const
{
    return ID;
}

Ente::Ente(const sf::Vector2f size, std::string id):
    HitBox(size),
    ID(id)
{
}

Ente::~Ente()
{
}

void Ente::Draw()
{
	window->draw(HitBox);
}

sf::RenderWindow *Ente::window(NULL);