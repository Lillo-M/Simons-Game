#include "Entity.h"
#include <iostream>
namespace Entities
{
	Entity::Entity(const sf::Vector2f pos, const sf::Vector2f size) :
		Position(pos.x, pos.y),
		HitBox(size),
		grounded(false),
		velocity(sf::Vector2f(0,0))
	{
		HitBox.setFillColor(sf::Color(sf::Color::White));// RGBA setados em 255 para testes
		HitBox.setPosition(Position);
		Cont++;
	}
	Entity::~Entity()
	{
		Cont--;
	}
	void Entity::Draw()
	{
		if (Position.y + HitBox.getSize().y / 2 > HEIGHT)
		{
			Position.y = HEIGHT - HitBox.getSize().y / 2;
			grounded = true;
			if (velocity.y < 0.f) velocity.y = 0;
		}
		HitBox.setPosition(Position);
		window->draw(HitBox);
	}

	void Entity::setGrounded(bool b) { grounded = b; }

	void Entity::restartClock()
	{
		Entity::clock.restart();
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

	const bool Entity::getGrounded() const { return grounded; }

	unsigned int Entity::Cont(0);
	const float Entity::gravity(static_cast<float>(98.f)); // 8.166
	sf::RenderWindow* Entity::window(NULL);
	sf::Clock Entity::clock;
}