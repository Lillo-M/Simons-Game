#include "../include/Entities/Characters/Enemies/Warrior.h"
#define dEnemy Entities::Characters::Enemies
#define SIZEX 61.f
#define SIZEY 100.f
#define ESPEED 0.1

dEnemy::Warrior::Warrior(const sf::Vector2f pos):
    Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::warrior, 3),
	directiontimer(0),
	directionright(static_cast<bool>(rand()%2))
{
    HitBox.setOrigin(SIZEX / 2, SIZEY / 2);

	HitBox.setTexture(texture);
	animation.AnimationReset(texture, sf::Vector2u(5,1), static_cast<float>(0.2));
}

dEnemy::Warrior::~Warrior()
{
}

void dEnemy::Warrior::Move()
{
	directiontimer += dt;
	//
	if(directiontimer >= 2)
	{
		directionright = !directionright;
		directiontimer -= 2;
		velocity.x = 0;
	}
	if(directionright)
	{
		HitBox.setScale(sf::Vector2f(1, 1));
		if (velocity.x < MAXV)
			velocity.x += ESPEED * dt * MULT; // Velocidade De Teste
		if (velocity.x > MAXV)
			velocity.x = MAXV;
	}
	else if(!directionright)
	{
		HitBox.setScale(sf::Vector2f(-1, 1));
		if (velocity.x > -MAXV)
			velocity.x -= ESPEED * dt * MULT; // Velocidade De Teste
		if (velocity.x < -MAXV)
			velocity.x = -MAXV;
	}
	Position.x += velocity.x * dt * MULT;
	Position.y += velocity.y * dt * MULT;
	this->Gravity();
}

void dEnemy::Warrior::Update()
{
	this->Move();
	this->Damage();
	HitBox.setPosition(Position);
	animation.update(Position);
	HitBox.setTextureRect(animation.uvRect);
}

void dEnemy::Warrior::Attack(const bool b)
{
    if (b)
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	else
		HitBox.setFillColor(sf::Color(sf::Color::White));
}

sf::Texture* dEnemy::Warrior::texture(Managers::GraphicManager::getInstance()->loadTexture("Assets/Enemy-Warrior-Idle.png"));