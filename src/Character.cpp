#include "../include/Entities/Character.h"

Entities::Characters::Character::Character(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, std::string id):
    Entity(pos, size, false, id),
    alive(true)
{
}

Entities::Characters::Character::~Character()
{
}

void Entities::Characters::Character::OnCollision(Entities::Entity* ent)
{
}

void Entities::Characters::Character::operator--() { lives--; if(lives < 1) alive = false; }

const bool Entities::Characters::Character::getAlive() const { return alive; }