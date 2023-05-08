#include "../include/Entities/Character.h"

Character::Character(const sf::Vector2f pos, const sf::Vector2f size, const bool isG, std::string id):
    Entity(pos, size, false, id)
{
}

Character::~Character()
{
}

void Character::operator--() { lives--; }

const bool Character::getAlive() const { return alive; }