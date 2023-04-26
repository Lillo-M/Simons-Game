#include "Player.h"
#define LIVES 5
Player::Player( const sf::Vector2f pos , const sf::Vector2f size ):
	Entity(pos, size),
	velocity(sf::Vector2f(0,0)),
	lives(LIVES),
	alive(true)
{
}

Player::~Player()
{
}

const bool Player::getAlive() const { return alive; }

void Player::setDead() { alive = false; }

void Player::Move()
{
	Position.x += velocity.x;
	Position.y += velocity.y;
}

