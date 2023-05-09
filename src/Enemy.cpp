#include "../include/Entities/Characters/Enemy.h"





Entities::Characters::Enemies::Enemy::Enemy(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, std::string id):
    Character(pos, size, isS, id)
{
}


Entities::Characters::Enemies::Enemy::~Enemy()
{
}

void Entities::Characters::Enemies::Enemy::OnCollision(Entities::Entity* ent)
{
}

void Entities::Characters::Enemies::Enemy::operator--() { lives--; }

const bool Entities::Characters::Enemies::Enemy::getAlive() const {return alive;}