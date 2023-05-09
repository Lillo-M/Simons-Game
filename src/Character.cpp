#include "../include/Entities/Character.h"

Character::Character(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, std::string id):
    Entity(pos, size, false, id),
    alive(true)
{
}

Character::~Character()
{
}

void Character::OnCollision(Entities::Entity* ent)
{
}

void Character::operator--() { lives--; }

const bool Character::getAlive() const { return alive; }