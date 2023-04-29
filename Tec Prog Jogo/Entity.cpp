#include "Entity.h"
#include <iostream>
namespace Entities
{
	Entity::Entity(const sf::Vector2f pos, const sf::Vector2f size, const bool isG) :
		Position(pos.x, pos.y),
		HitBox(size),
		grounded(false),
		velocity(sf::Vector2f(0,0)),
		isGround(isG)
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
		HitBox.setPosition(Position);
		window->draw(HitBox);
	}

	void Entity::Gravity()
	{
		float dt = static_cast<float>(clock.getElapsedTime().asMicroseconds()) / 1000000.f;
		if (!grounded)
			velocity.y += gravity * dt;
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
	sf::Vector2f Entity::getPosition() const
	{
		return Position;
	}

	sf::Vector2f Entity::getSize() const
	{
		return HitBox.getSize();
	}

	bool Entity::getIsGround()
	{
		return isGround;
	}

	void Entity::OnCollision(Entity* ent)
	{
		float dist = ent->getPosition().y - Position.y;
		if (dist < 0)
			dist = -dist;
		float dy = ent->getSize().y/2 + getSize().y/2;
		if (dy < 0)
			dy = -dy;
		if (dist < dy)Position.y -= dy - dist;
		grounded = true;
		std::cout << std::endl << "Colision!" << std::endl;
	}

	const bool Entity::getGrounded() const { return grounded; }

	unsigned int Entity::Cont(0);
	const float Entity::gravity(static_cast<float>(98.f)); // 8.166
	sf::RenderWindow* Entity::window(NULL);
	sf::Clock Entity::clock;
}