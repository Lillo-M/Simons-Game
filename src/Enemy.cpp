#include "../include/Entities/Characters/Enemies/Enemy.h"
#include "../Player.h"

#define dEnemy Entities::Characters::Enemies::Enemy
#define SIZEX 61.f
#define SIZEY 100.f
#define ESPEED 0.1
#define KNOCKBACK -11.f

dEnemy::Enemy(const sf::Vector2f pos, const sf::Vector2f size, ID id, int lves):
    Character(pos, size, id, lves),
	attackTimer(0)
{
}


dEnemy::Enemy::~Enemy()
{
}


