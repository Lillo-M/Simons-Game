#include "../include/Entities/Characters/Enemies/Warrior.h"

Entities::Characters::Enemies::Warrior::Warrior(const sf::Vector2f pos, const sf::Vector2f size):
    Enemy(pos, size, false, "Enemy")
{
    HitBox.setOrigin(size.x / 2, size.y / 2);
	if(!textureLoaded)
		if (!texture.loadFromFile("Assets/Enemy-Warrior-Idle.png"))
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
	HitBox.setTexture(&texture);
}

Entities::Characters::Enemies::Warrior::~Warrior()
{
}
void Entities::Characters::Enemies::Warrior::Move()
{
	Position.x += velocity.x * dt * MULT;
	Position.y += velocity.y * dt * MULT;
	Gravity();
	HitBox.setPosition(Position);
}

void Entities::Characters::Enemies::Warrior::Attack(const bool b)
{
    if (b)
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	else
		HitBox.setFillColor(sf::Color(sf::Color::White));
}

void Entities::Characters::Enemies::Warrior::OnCollision(Entities::Entity* ent)
{
	if(ent->getID() == "Player")
	{
		Attack(true);
		Entities::Characters::Player* pPlayer = static_cast<Entities::Characters::Player*>(ent);
		pPlayer->operator--();
		pPlayer = NULL;
	}
	else
	{
		normalCollision(ent);
		Attack(false);
	}
}

sf::Texture Entities::Characters::Enemies::Warrior::texture;
bool Entities::Characters::Enemies::Warrior::textureLoaded = false;