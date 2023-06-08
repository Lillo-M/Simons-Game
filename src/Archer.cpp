#include "../include/Entities/Characters/Enemies/Archer.h"

#define SIZEX 30.f
#define SIZEY 60.f
#define ESPEED 0.1
#define ARROWS 5
#define A_VELOCITY 20
#define MAX_ARROW_VELOCITY 20
#define KNOCKBACK -11.f

#define IDLEPATH "Assets/Archer/Archer-Idle.png"
#define WALKPATH "Assets/Archer/Archer-Walk.png"
#define MELEEATTACKPATH "Assets/Archer/Archer-Attack.png"
#define ATTACKPATH "Assets/Archer/Shot_1.png"

#define dEnemy Entities::Characters::Enemies
#define dPlayer Entities::Characters::Player *

dEnemy::Archer::Archer(const sf::Vector2f pos) : Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::archer, 7),
	shootCount(0),
	faceRight(false),
	attackcd(0.f),
	attackcooled(false),
	meele(false),
	meeletimer(0.f),
	shooting(false),
	shoottimer(0),
	aiming(false)
{
	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(7, 0), 0.2f);
	animation.pushAnimation(GraphicElements::Animation_ID::meleeattack, MELEEATTACKPATH, sf::Vector2u(4, 0), 0.08f);
	animation.pushAnimation(GraphicElements::Animation_ID::attack, ATTACKPATH, sf::Vector2u(15, 0), 0.067f);
	
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
	this->Move();
	this->Damage();
	if (getNearest()->getPosition().x - Position.x >= 0)
		faceRight = true;
	else
		faceRight = false;
	if (meele)
	{
		meeletimer += dt;
		if (meeletimer >= 0.32f)
		{
			meeletimer = 0;
			meele = false;
		}
		animation.Update(GraphicElements::Animation_ID::meleeattack,
						 Position, faceRight);
	}
	else if (aiming)
	{
		shoottimer += dt;
		if (shoottimer >= 1.0f)
		{
			shoottimer = 0.f;
			shooting = false;
		}
		animation.Update(GraphicElements::Animation_ID::attack,
						 Position, faceRight);
	}
	else
	{
		animation.Update(GraphicElements::Animation_ID::idle,
						 Position, faceRight);
		attackcd = 0.f;
		attackcooled = false;
		shoottimer = 0.f;
		shooting = false;
	}
	if (!attackcooled)
	{
		attackcd += dt;
		if (attackcd >= 1.f)
		{
			attackcd -= 1.f;
			attackcooled = true;
		}
	}
	if ((abs(getNearest()->getPosition().x - Position.x) <= DISTANCE_ARCHER_ATTACK && (getNearest()->getPosition().y - Position.y) <= 100 ) || aiming)
		Attack(true);
}

std::vector<Entities::Arrow *> *Entities::Characters::Enemies::Archer::getShots()
{
	return &aShots;
}

void dEnemy::Archer::Move()
{
	Position.x += Velocity.x * dt * MULT;
	Position.y += Velocity.y * dt * MULT;
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
	savefile << attackcd << std::endl;
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
	// std::cout << " Archer " << std::endl;
	savefile >> iread;
	savefile >> iread;
	this->setLives(iread);
	// std::cout << iread << " : iread" << std::endl;
	savefile >> iread;
	this->setAlive(static_cast<bool>(iread));
	// std::cout << iread << " : iread" << std::endl;
	savefile >> x;
	savefile >> y;
	// std::cout << x << "," << y <<std::endl;
	this->setPosition(x, y);
	savefile >> x;
	savefile >> y;
	this->setVelocity(x, y);
	savefile >> attackcd;
	// std::cout << x << "," << y <<std::endl;
	for (int j = 0; j < ARROWS; j++)
	{
		aShots[j]->Load(savefile);
	}
}

void dEnemy::Archer::setPlayer(Player *pPlayer)
{
	p1 = pPlayer;
	std::cout << p1 << std::endl;
}

void dEnemy::Archer::setPlayer2(Player *pPlayer2)
{
	p2 = pPlayer2;
	std::cout << pPlayer2 << std::endl;
}

dPlayer dEnemy::Archer::getNearest()
{
	if (p2->getAlive() && p1->getAlive())
	{
		if (abs(p1->getPosition().x - Position.x) > abs(p2->getPosition().x - Position.x))
			return p2;
		else
			return p1;
	}
	else if(p2->getAlive())
		return p2;
	else/**/
		return p1;
}

void dEnemy::Archer::Attack(const bool b)
{
	aiming = true;
	if (!shooting && attackcooled)
	{
		shoottimer += dt;
		if (shoottimer >= 0.86f) // tempo para passar 13
		{
			shooting = true;
		}
		animation.Update(GraphicElements::Animation_ID::attack,
						 Position, faceRight);
	}
	if (shooting && attackcooled)
	{
		animation.Update(GraphicElements::Animation_ID::attack,
						 Position, faceRight);
		attackcooled = false;
		aiming = false;
		int h = (getNearest()->getPosition().y - Position.y); // Altura
		float dist = abs(getNearest()->getPosition().x - Position.x);
		float time = dist / A_VELOCITY;
		float vy;
		float vx = A_VELOCITY;
		float posy = Position.y;
		float posx = (10 + SIZEX / 2 + aShots[shootCount]->getSize().x / 2);
		if(dist < SIZEX)
		{
			vx = 0;
			posy -= (10 + SIZEY / 2 + aShots[shootCount]->getSize().y / 2);
			posx = 0;
		}

		vy = (-(gravity * time) / 2) + h/time +\
			 (h >= 1 ? -40/time:(h <= -1 ? -h/(2*time):h/(2*time)) );

		if(vy <= -MAX_ARROW_VELOCITY)
		{
			vy = -MAX_ARROW_VELOCITY;
		}
		aShots[shootCount]->Shoot(sf::Vector2f(Position.x + posx * (faceRight ? 1 : -1),
							posy),
							sf::Vector2f((faceRight ? 1 : -1) * vx, vy));

		shootCount++;

		if (shootCount >= aShots.size())
			shootCount = 0;
	}
}

void dEnemy::Archer::OnCollision(Entities::Entity *ent)
{
	if (ent->getID() == ID::player)
	{
		animation.Update(GraphicElements::Animation_ID::meleeattack, Position, faceRight);
		meele = true;
		Entities::Characters::Player *pPlayer = static_cast<Entities::Characters::Player *>(ent);
		pPlayer->Damage(true);
		sf::Vector2f vel = sf::Vector2f(0, KNOCKBACK / 2);
		if (pPlayer->getPosition().x > Position.x)
			vel.x = -KNOCKBACK;
		else
			vel.x = KNOCKBACK;
		pPlayer->setVelocity(vel);
		pPlayer = NULL;
	}
}

dPlayer Entities::Characters::Enemies::Archer::p1(NULL);
dPlayer Entities::Characters::Enemies::Archer::p2(NULL);