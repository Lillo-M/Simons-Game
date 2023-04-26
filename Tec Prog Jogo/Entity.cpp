#include "Entity.h"
#include <iostream>

Entity::Entity(const sf::Vector2f pos , const sf::Vector2f size ):
	Position(pos.x, pos.y),
	HitBox(size)
{
	HitBox.setFillColor(sf::Color( 255, 255, 255, 255));// RGBA setados em 255 para testes
	HitBox.setPosition(Position);
	Cont++;
}
Entity::~Entity()
{
	Cont--;
}
void Entity::Draw()
{
	window->draw(HitBox);
}
void Entity::setWindow(sf::RenderWindow& wds)
{
	if (!&wds)
	{
		std::cout << std::endl << "ERROR: NULL Window pointer" << std::endl;
		exit(1);
	}
	Entity::window = &wds;
}

unsigned int Entity::Cont(0);

sf::RenderWindow* Entity::window(NULL);
