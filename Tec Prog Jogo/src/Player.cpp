#include "../include/Player.h"

namespace Entities
{
	Player::Player(const sf::Vector2f pos, const sf::Vector2f size) :
		Entity(pos, size, false),
		lives(LIVES),
		alive(true),
		maxVelocity(MAXV),
		boolMoveLeft(false),
		BoolMoveRight(false),
		secondJump(false),
		fall(false)
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

	void Player::Move()
	{
		if (boolMoveLeft)
		{
			if (velocity.x > -maxVelocity)velocity.x -= PSPEED * dt * MULT; // Velocidade De Teste
			else velocity.x = -maxVelocity; // Velocidade De Teste
			if (velocity.x < -maxVelocity) velocity.x = -maxVelocity;
		}
		if (BoolMoveRight)
		{
			if (velocity.x < maxVelocity)velocity.x += PSPEED * dt * MULT; // Velocidade De Teste
			else velocity.x = maxVelocity; // Velocidade De Teste
			if (velocity.x > maxVelocity) velocity.x = maxVelocity;
		}
		if (fall)
		{
			if (!grounded) velocity.y -= JUMPHEIGHT/8 * dt * MULT;//Valores de Teste
			else
				fall = false;
		}

		if (velocity.x < 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
		{
			velocity.x += ATRITO * dt * MULT;
			if (velocity.x > 0)
				velocity.x = 0;
		}
		else if (velocity.x > 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
		{
			velocity.x -= ATRITO * dt * MULT;
			if (velocity.x < 0)
				velocity.x = 0;
		}
		Position.x += velocity.x * dt * MULT;
		Position.y += velocity.y * dt * MULT;
		Gravity();
	}

	void Player::Jump()
	{
		if (grounded)
		{
			grounded = false;
			secondJump = true;
			fall = false;
			velocity.y = JUMPHEIGHT;// Valor De Teste
		}
		else
			if (secondJump)
			{
				fall = false;
				secondJump = false;
				velocity.y = JUMPHEIGHT;// Valor De Teste
			}
	}

	void Player::MoveRight(const bool b)
	{
		if(b)
			HitBox.setScale(sf::Vector2f(-1, 1));
		else if(boolMoveLeft)
			HitBox.setScale(sf::Vector2f(1, 1));
		BoolMoveRight = b;
	}

	void Player::MoveLeft(const bool b)
	{
		if(b)
			HitBox.setScale(sf::Vector2f(1, 1));
		else if(BoolMoveRight)
			HitBox.setScale(sf::Vector2f(-1, 1));
		boolMoveLeft = b;
	}

	void Player::Fall()
	{
		fall = true;
		std::cout << std::endl << "Fall!" << std::endl;
	}
	void Player::Attack(const bool b)
	{
		if(b)
			HitBox.setFillColor(sf::Color(sf::Color::Red));
		else
			HitBox.setFillColor(sf::Color(sf::Color::White));

	}
}