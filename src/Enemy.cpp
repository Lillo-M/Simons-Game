#include "../include/Entities/Characters/Enemies/Enemy.h"
#define dEnemy Entities::Characters::Enemies::Enemy




dEnemy::Enemy(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, ID id, int lves):
    Character(pos, size, isS, id, lves)
{
}


dEnemy::Enemy::~Enemy()
{
}

void dEnemy::Enemy::OnCollision(Entities::Entity* ent)
{
}

void dEnemy::Enemy::operator--() { lives--; }

const bool dEnemy::Enemy::getAlive() const {return alive;}