#include "../include/Entities/Characters/Enemies/Archer.h"

#define SIZEX 30.f
#define SIZEY 60.f
#define ESPEED 0.1
#define ARROWS 5
#define A_VELOCITY 20
#define dEnemy Entities::Characters::Enemies
#define dPlayer Entities::Characters::Player* 

dEnemy::Archer::Archer(const sf::Vector2f pos):
Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::archer, 7),
	count (0),
	faceRight(false),
	attackcd (0.f),
	attackcooled (true)
{
	HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	animation.pushAnimation(GraphicElements::Animation_ID::idle, "Assets/Archer-Idle.png", sf::Vector2u(7, 0), 0.2f);
	for (int i = 0; i < ARROWS; i++)
	{
		Arrow *pAux = new Arrow(sf::Vector2f(0, 0), sf::Vector2f(0, 0), static_cast<Entities::Characters::Character*>(this));
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
	HitBox.setPosition(Position);
	animation.Update(GraphicElements::Animation_ID::idle,
	Position, false);
	if (!attackcooled){
		attackcd += dt;
		if(attackcd >= 1.f)
		{
			attackcd -= 1.f;
			attackcooled = true;
		}
	}
	if ( abs(getNearest()->getPosition().x - Position.x) <= DISTANCE_ARCHER_ATTACK && (getNearest()->getPosition().y - Position.y) <= 50)
		Attack (true);
}

std::vector<Entities::Arrow*>* Entities::Characters::Enemies::Archer::getShots()
{
	return &aShots;
}

void dEnemy::Archer::Move()
{
	std::cout << Velocity.x << std::endl;
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
	savefile >> attackcd;
	//std::cout << x << "," << y <<std::endl;
	for (int j = 0; j < ARROWS; j++)
	{
		aShots[j]->Load(savefile);
	}
}

void dEnemy::Archer::setPlayer (Player* pPlayer){
	p1 = pPlayer;
	std::cout << p1 << std::endl;
}
void dEnemy::Archer::setPlayer2 (Player* pPlayer2){
	p2 = pPlayer2;
	std::cout << p2 << std::endl;
}
Entities::Characters::Player* dEnemy::Archer::getNearest(){
	if (p2){
		if (abs (p1->getPosition().x - Position.x) > abs (p2->getPosition().x - Position.x))
			return p2;
		else 
			return p1;
	}
	else 
		return p1;
}

void dEnemy::Archer::Attack(const bool b)
{	
	if (attackcooled)
	{
		//animation.Update(GraphicElements::Animation_ID::attack, Position, faceRight);
		attackcooled = false;
		int h = (getNearest()->getPosition().y - Position.y); // Altura 
		float time = abs (getNearest()->getPosition().x - Position.x)/A_VELOCITY;
		int vy;
		int hf = h + (time*time/2);

		if (h < 0)
		{
			vy = -hf/time; // Velocidade em Y
		}
		else
			vy = (-hf)/time;

		aShots[count]->Shoot(sf::Vector2f(Position.x + \
		( SIZEX / 2 + aShots[count]->getSize().x / 2 ) * (-1), Position.y), \
	        sf::Vector2f((-1) * A_VELOCITY, vy));	
		
		count++;
	
		if(count >= aShots.size())
			count = 0;
	}
}

dPlayer Entities::Characters::Enemies::Archer::p1(NULL);
dPlayer Entities::Characters::Enemies::Archer::p2(NULL);
