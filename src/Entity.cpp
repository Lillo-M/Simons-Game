#include "../include/Entities/Entity.h"

using namespace Entities;

Entity::Entity(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, std::string id) : 
	Ente(size, id),
	Position(pos.x, pos.y),
	grounded(false),
	velocity(sf::Vector2f(0, 0)),
	isStatic(isS)
{
	HitBox.setFillColor(sf::Color(sf::Color::White)); // RGBA de Teste
	HitBox.setPosition(Position);
	Cont++;
}
Entity::~Entity()
{
	Cont--;
}

void Entity::Gravity()
{
	float mult = 60;
	velocity.y += gravity * dt * mult;
}

void Entity::setGrounded(bool b) { grounded = b; }

sf::Vector2f Entity::getPosition() const
{
	return Position;
}

sf::Vector2f Entity::getSize() const
{
	return HitBox.getSize();
}

bool Entity::getisStatic()
{
	return isStatic;
}

void Entity::normalCollision(Entity* ent)
{
	float size_y = ent->getSize().y / 2 + getSize().y / 2;
	float size_x = ent->getSize().x / 2 + getSize().x / 2;
	float dist_y = ent->getPosition().y - Position.y;
	float dist_x = ent->getPosition().x - Position.x;
	if (abs(dist_x) - size_x > abs(dist_y) - size_y) // retirar ABS
	{
		if (dist_x > 0)
		{
			Position.x += dist_x - size_x;
			if (velocity.x > 0)
				velocity.x = 0;
		}
		if (dist_x < 0)
		{
			Position.x += dist_x + size_x;
			if (velocity.x < 0)
				velocity.x = 0;
		}
	}
	else
	{
		if (dist_y > 0)
		{
			Position.y += dist_y - size_y;
			velocity.y = 0;
			grounded = true;
		}
		if (dist_y < 0)
		{
			Position.y += size_y + dist_y;
			velocity.y = 0;
		}
	}
}

void Entity::OnCollision(Entity *ent)
{
	normalCollision(ent);
}

void Entity::updateDeltaTime()
{
	dt = static_cast<float>(clock.getElapsedTime().asSeconds());
	if (dt > 0.3f)
	{
		std::cout << std::endl
				  << "STUTTER DETECTED!" << std::endl;
		dt = 0;
	}
	Entity::clock.restart();
}

unsigned int Entity::getContEntities()
{
	return Entity::Cont;
}
float Entities::Entity::getDt()
{
    return dt;
}

const bool Entity::getGrounded() const { return grounded; }

float Entity::dt = 0;
unsigned int Entity::Cont(0);
const float Entity::gravity(static_cast<float>(0.78)); // 8.166 valor de teste
sf::Clock Entity::clock;
