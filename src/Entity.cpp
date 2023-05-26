#include "../include/Entities/Entity.h"

using namespace Entities;

Entity::Entity(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, ID id) : 
	Being(id),
	HitBox(size),
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

void Entity::Draw()
{
	pGM->Draw(HitBox);
}


void Entity::Gravity()
{
	float mult = 60;
	velocity.y += gravity * dt * mult;
}

void Entity::setGrounded(bool b) { grounded = b; }

void Entity::setPosition(sf::Vector2f pos)
{
	Position = pos;
}

void Entity::setPosition(float x, float y)
{
	Position.x = x;
	Position.y = y;
}

void Entity::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

void Entity::setVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
	return velocity;
}

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

void Entity::OnCollision(Entity *ent)
{
}

void Entity::updateDeltaTime(float dt)
{
	Entity::dt = dt; 
}

unsigned int Entity::getContEntities()
{
	return Entity::Cont;
}

float Entities::Entity::getDt()
{
    return dt;
}

void Entities::Entity::Save()
{
	std::ofstream savefile("Assets/savefile.txt", std::ofstream::binary);
	std::string line;
	savefile << this->getID() << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
	savefile.close();
}

const bool Entity::getGrounded() const { return grounded; }

float Entity::dt = 0;
unsigned int Entity::Cont(0);
const float Entity::gravity(static_cast<float>(0.78)); // 8.166 valor de teste

