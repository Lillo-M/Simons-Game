#include "Player.h"

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
		std::cout << std::endl << dt << std::endl;
		if (boolMoveLeft)
		{
			//std::cout << std::endl << "MoveLeft" << std::endl;
			if (velocity.x > -maxVelocity)velocity.x -= PSPEED  * dt; // Velocidade De Teste
			else velocity.x = -maxVelocity; // Velocidade De Teste
			if (velocity.x < -maxVelocity) velocity.x = -maxVelocity;
		}
		if (BoolMoveRight)
		{
			//std::cout << std::endl << "MoveRight" << std::endl;
			if (velocity.x < maxVelocity)velocity.x += PSPEED * dt; // Velocidade De Teste
			else velocity.x = maxVelocity; // Velocidade De Teste
			if (velocity.x > maxVelocity) velocity.x = maxVelocity;
		}
		if (fall)
		{
			if (!grounded) velocity.y -= 5 * JUMPHEIGHT * dt;
			else
				fall = false;
		}

		//if (!boolMoveLeft && !BoolMoveRight) velocity.x = 0;

		if (velocity.x < 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
		{
			if (velocity.x + ATRITO * dt < 0)
				velocity.x += ATRITO * dt;
			else
				velocity.x = 0;
		}
		else if (velocity.x > 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
		{
			if (velocity.x - ATRITO * dt > 0)
				velocity.x -= ATRITO * dt;
			else
				velocity.x = 0;
		}
		//else if (!boolMoveLeft && !BoolMoveRight)velocity.x = 0;
		
		//std::cout << "y" << std::endl << velocity.y << std::endl;
		//std::cout << "x" << std::endl << velocity.x << std::endl;

		//std::cout << "y" << std::endl << Position.y << std::endl;
		//std::cout << "x" << std::endl << Position.x << std::endl;
		//std::cout << "a" << velocity.y << std::endl;

		Position.x += velocity.x;
		Position.y += velocity.y;
		//std::cout << Position.y << "bpy" << std::endl;
		//std::cout << "b" << velocity.y << std::endl;
		Gravity();
	}

	void Player::Jump()
	{
		if (grounded)
		{
			grounded = false;
			secondJump = true;
			fall = false;
			//std::cout << velocity.y << "vy" << std::endl;
			//std::cout << Position.y << "apy" << std::endl;
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