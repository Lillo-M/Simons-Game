#include "../include/Entities/Characters/Player.h"

Entities::Characters::Player::Player(const sf::Vector2f pos, const sf::Vector2f size) : 
	Character(pos, size, false, ID::player),
	maxVelocity(MAXV),
	boolMoveLeft(false),
	BoolMoveRight(false),
	secondJump(false),
	fall(false)
{
	HitBox.setOrigin(size.x / 2, size.y / 2);
	if(!textureLoaded)
		if (!texture.loadFromFile("Assets/Player-Idle.png"))
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
	HitBox.setTexture(&texture);
}

Entities::Characters::Player::~Player()
{
}

void Entities::Characters::Player::setDead() { alive = false; }

sf::Vector2f Entities::Characters::Player::getPosition() // botar na entidade
{
	return Position;
}

const sf::Vector2f Entities::Characters::Player::getVelocity() const { return velocity; } // botar na entidade

void Entities::Characters::Player::Move()
{
	if (boolMoveLeft)
	{
		if (velocity.x > -maxVelocity)
			velocity.x -= PSPEED * dt * MULT; // Velocidade De Teste
		else
			velocity.x = -maxVelocity; // Velocidade De Teste
		if (velocity.x < -maxVelocity)
			velocity.x = -maxVelocity;
	}
	if (BoolMoveRight)
	{
		if (velocity.x < maxVelocity)
			velocity.x += PSPEED * dt * MULT; // Velocidade De Teste
		else
			velocity.x = maxVelocity; // Velocidade De Teste
		if (velocity.x > maxVelocity)
			velocity.x = maxVelocity;
	}
	if (fall)
	{
		if (!grounded)
			velocity.y -= JUMPHEIGHT / 8 * dt * MULT; // Valores de Teste
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
	HitBox.setPosition(Position);
}

void Entities::Characters::Player::Jump()
{
	if (grounded)
	{
		grounded = false;
		secondJump = true;
		fall = false;
		velocity.y = JUMPHEIGHT; // Valor De Teste
	}
	else if (secondJump)
	{
		fall = false;
		secondJump = false;
		velocity.y = JUMPHEIGHT; // Valor De Teste
	}
}

void Entities::Characters::Player::MoveRight(const bool b)
{
	if (b)
		HitBox.setScale(sf::Vector2f(-1, 1));
	else if (boolMoveLeft)
		HitBox.setScale(sf::Vector2f(1, 1));
	BoolMoveRight = b;
}

void Entities::Characters::Player::MoveLeft(const bool b)
{
	if (b)
		HitBox.setScale(sf::Vector2f(1, 1));
	else if (BoolMoveRight)
		HitBox.setScale(sf::Vector2f(-1, 1));
	boolMoveLeft = b;
}

void Entities::Characters::Player::Fall()
{
	fall = true;
	std::cout << std::endl
			  << "Fall!" << std::endl;
}

void Entities::Characters::Player::Attack(const bool b)
{
	if (b)
		HitBox.setFillColor(sf::Color(sf::Color::Blue));
	else
		HitBox.setFillColor(sf::Color(sf::Color::White));
}
void Entities::Characters::Player::OnCollision(Entities::Entity *ent)
{
	if(ent->getID() == ID::enemy)
	{
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	}
	else
	{
		HitBox.setFillColor(sf::Color(sf::Color::White));
		normalCollision(ent);
	}
}

sf::Texture Entities::Characters::Player::texture;
bool Entities::Characters::Player::textureLoaded = false;