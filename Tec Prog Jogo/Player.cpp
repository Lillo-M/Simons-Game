#include "Player.h"

namespace Entities
{
	Player::Player(const sf::Vector2f pos, const sf::Vector2f size) :
		Entity(pos, size),
		velocity(sf::Vector2f(0, 0)),
		lives(LIVES),
		alive(true),
		maxVelocity(MAXV),
		boolMoveLeft(false),
		BoolMoveRight(false),
		secondJump(false)
	{
		HitBox.setOrigin(size.x / 2, size.y / 2);
		if (texture.loadFromFile("Assets/Idle.png"))
		{
			HitBox.setTexture(&texture);
		}
		else
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
	}

	Player::~Player()
	{
	}

	const bool Player::getAlive() const { return alive; }

	void Player::setDead() { alive = false; }

	void Player::operator--() { lives--; }

	sf::Vector2f Player::getPosition()
	{
		return Position;
	}

	const sf::Vector2f Player::getVelocity() const { return velocity; }

	void Player::addVelocity(sf::Vector2f vel)
	{
		//if ( velocity.x < maxVelocity && vel.x > 0 || velocity.x > -maxVelocity && vel.x < 0) velocity.x += vel.x;
		//if (velocity.y < maxVelocity && vel.y > 0 || velocity.y > -maxVelocity && vel.y < 0) velocity.y += vel.y;
		//velocity.x += vel.x;
		//velocity.y += vel.y;
		//if ( velocity.x > maxVelocity ) velocity.x = maxVelocity;
		//if ( velocity.x < -maxVelocity ) velocity.x = -maxVelocity;

	}

	void Player::Gravity()
	{
		if (!grounded)
			velocity.y += gravity;
	}

	void Player::Move()
	{
		if (boolMoveLeft)
		{
			if (velocity.x > -20)velocity.x -= 5; // Velocidade De Teste
			else
				velocity.x = -20; // Velocidade De Teste
		}
		if (BoolMoveRight)
		{
			if (velocity.x < 20)velocity.x += 5; // Velocidade De Teste
			else
				velocity.x = 20; // Velocidade De Teste
		}

		Position.x += velocity.x;
		Position.y += velocity.y;
		if (velocity.x < 0) velocity.x += 0.5;// Atrito
		if (velocity.x > 0) velocity.x -= 0.5;// Atrito
		Gravity();
	}

	void Player::Jump()
	{
		if (grounded)
		{
			secondJump = true;
			velocity.y = -50;// Valor De Teste
		}
		else
			if (secondJump)
			{
				secondJump = false;
				velocity.y = -50;
			}
	}

	void Player::MoveRight(const bool b)
	{
		HitBox.setScale(sf::Vector2f(-1, 1));
		BoolMoveRight = b;
	}

	void Player::MoveLeft(const bool b)
	{
		HitBox.setScale(sf::Vector2f(1, 1));
		boolMoveLeft = b;
	}

	void Player::Fall()
	{
		velocity.y += 30;
	}
}