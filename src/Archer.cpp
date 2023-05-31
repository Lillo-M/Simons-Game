#include "../include/Entities/Characters/Enemies/Archer.h"

#define dEnemy Entities::Characters::Enemies
#define SIZEX 61.f
#define SIZEY 100.f
#define ESPEED 0.1

dEnemy::Archer::Archer(const sf::Vector2f pos):
    Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::archer, 7)
{
    HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	HitBox.setTexture(texture);
	animation.AnimationReset(texture, sf::Vector2u(5,1), static_cast<float>(0.2));
    for(int i = 0; i < 5; i++)
	{
		Arrow* pAux = new Arrow(sf::Vector2f(0,0), sf::Vector2f(0,0), this);
		if(!pAux)
		{
			std::cout << std::endl << "ERROR: Failed to Memory Allocate" << std::endl;
			exit(1);
		}
		aShots.push_back(pAux);
	}
}

dEnemy::Archer::~Archer()
{
    aShots.clear();
}

void dEnemy::Archer::Update()
{
    this->Gravity();
	this->Damage();
	HitBox.setPosition(Position);
	animation.update(Position);
	HitBox.setTextureRect(animation.uvRect);
}

void dEnemy::Archer::Attack(const bool b)
{
    if (b)
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	else
		HitBox.setFillColor(sf::Color(sf::Color::White));
}
std::vector<Arrow*> *Entities::Characters::Enemies::Archer::getShots()
{
    return &aShots;
}

sf::Texture* dEnemy::Archer::texture(Managers::GraphicManager::getInstance()->loadTexture("Assets/Archer-Idle.png"));