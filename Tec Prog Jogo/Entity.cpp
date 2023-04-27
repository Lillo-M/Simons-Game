#include "Entity.h"
#include <iostream>

Entity::Entity(const sf::Vector2f pos , const sf::Vector2f size ):
	Position(pos.x, pos.y),
	HitBox(size),
	grounded(false)
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
	if (Position.y + HitBox.getSize().y > HEIGHT)
	{
		Position.y = HEIGHT - HitBox.getSize().y;
		grounded = true;
	}
	else
	{
		grounded = false;
	}
		HitBox.setPosition(Position);
	window->draw(HitBox);
}

void Entity::setGrounded(bool b) { grounded = b; }

void Entity::setWindow(sf::RenderWindow& wds)
{
	if (!&wds)
	{
		std::cout << std::endl << "ERROR: NULL Window pointer" << std::endl;
		exit(1);
	}
	Entity::window = &wds;
}

const bool Entity::getGrounded() const { return grounded; }

unsigned int Entity::Cont(0);
const float Entity::gravity(8.166);
sf::RenderWindow* Entity::window(NULL);
