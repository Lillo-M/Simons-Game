#include "../include/Entities/Characters/Enemies/Archer.h"

#define SIZEX 30.f
#define SIZEY 60.f
#define ESPEED 0.1
#define ARROWS 5
#define dEnemy Entities::Characters::Enemies

dEnemy::Archer::Archer(const sf::Vector2f pos) : Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::archer, 7),
	shotcount(0),
	attackCD(true)
{
	HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	animation.pushAnimation(GraphicElements::Animation_ID::idle, "Assets/Archer-Idle.png", sf::Vector2u(7, 0), 0.2f);
	for (int i = 0; i < ARROWS; i++)
	{
		Arrow *pAux = new Arrow(sf::Vector2f(0, 0), sf::Vector2f(0, 0), this);
		if (!pAux)
		{
			std::cout << std::endl
					  << "ERROR: Failed to Memory Allocate" << std::endl;
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
	Attack(true);
	HitBox.setPosition(Position);
	animation.Update(GraphicElements::Animation_ID::idle,
	Position, false);
}

void dEnemy::Archer::Attack(const bool b)
{
	attackTimer += dt;
	if (attackTimer >= 1.5f)
	{
		attackCD = true;
		attackTimer = 0;
	}
	if (attackCD)
	{
		aShots[shotcount]->Shoot(sf::Vector2f(Position.x - (SIZEX / 2 + aShots[shotcount]->getSize().x / 2), Position.y), sf::Vector2f(-10, -15));
		attackCD = false;
	}
	shotcount++;
	if (shotcount >= ARROWS)
		shotcount = 0;
}
std::vector<Entities::Arrow *> *Entities::Characters::Enemies::Archer::getShots()
{
	return &aShots;
}

void dEnemy::Archer::Move()
{
	this->Gravity();
}

void dEnemy::Archer::Draw()
{
	animation.Draw();
}

void dEnemy::Archer::Save(std::ofstream &savefile)
{
	savefile << this->getID() << std::endl;
	savefile << lives << std::endl;
	savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl;
	savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
	savefile << attackTimer << std::endl;
	for (int i = 0; i < aShots.size(); i++)
	{
		aShots[i]->Save(savefile);
	}
}

void dEnemy::Archer::Load(std::ifstream &savefile)
{
	float x;
	float y;
	int iread;
	//std::cout << " Archer " << std::endl;
	savefile >> iread;
	savefile >> iread;
	this->setLives(iread);
	//std::cout << iread << " : iread" << std::endl;
	savefile >> iread;
	this->setAlive(static_cast<bool>(iread));
	//std::cout << iread << " : iread" << std::endl;
	savefile >> x;
	savefile >> y;
	//std::cout << x << "," << y <<std::endl;
	this->setPosition(x, y);
	savefile >> x;
	savefile >> y;
	this->setVelocity(x, y);
	savefile >> attackTimer;
	//std::cout << x << "," << y <<std::endl;
	for (int j = 0; j < ARROWS; j++)
	{
		aShots[j]->Load(savefile);
	}
}