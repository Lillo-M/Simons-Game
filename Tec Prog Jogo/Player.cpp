#include "Player.h"

Player::Player( const sf::Vector2f pos , const sf::Vector2f size ):
	Entity(pos, size),
	velocity(sf::Vector2f(0,0)),
	lives(LIVES),
	alive(true),
	maxVelocity(MAXV)
{
}

Player::~Player()
{
}

const bool Player::getAlive() const { return alive; }

void Player::setDead() { alive = false; }

void Player::operator--() { lives--; }

const sf::Vector2f Player::getVelocity() const { return velocity; }

void Player::addVelocity(sf::Vector2f vel)
{
	//if ( velocity.x < maxVelocity && vel.x > 0 || velocity.x > -maxVelocity && vel.x < 0) velocity.x += vel.x;
	//if (velocity.y < maxVelocity && vel.y > 0 || velocity.y > -maxVelocity && vel.y < 0) velocity.y += vel.y;
	velocity.x += vel.x;
	velocity.y += vel.y;
	if ( velocity.x > maxVelocity ) velocity.x = maxVelocity;
	if ( velocity.x < -maxVelocity ) velocity.x = -maxVelocity;

}

void Player::Gravity()
{
	if (!grounded)
		velocity.y += gravity;
}

void Player::Move()
{
	Gravity();
	Position.x += velocity.x;
	Position.y += velocity.y;
	if (velocity.x < 0) velocity.x += 0.5;
	if (velocity.x > 0) velocity.x -= 0.5;
}



