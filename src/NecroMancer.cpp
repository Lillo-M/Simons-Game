#include "../include/Entities/Characters/Enemies/NecroMancer.h"

#define SIZEX 100
#define SIZEY 90
#define SKELETONS 10
#define ARCHERS 10

#define IDLEPATH "Assets/NecroMancer/demon-idle.png"
#define ATTACKPATH "Assets/NecroMancer/demon-attack.png"

Entities::Characters::Enemies::NecroMancer::NecroMancer(sf::Vector2f pos):
    Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::necromancer, 5)
{
	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(6,0), 0.166f);
}

Entities::Characters::Enemies::NecroMancer::~NecroMancer()
{
}

void Entities::Characters::Enemies::NecroMancer::Draw()
{
	animation.Draw();
}

void Entities::Characters::Enemies::NecroMancer::Move()
{
	Position.x += Velocity.x * dt * MULT;
	Position.y += Velocity.y * dt * MULT;
	this->Gravity();
}

void Entities::Characters::Enemies::NecroMancer::Update()
{
	this->Damage();
	this->Move();
	animation.Update(GraphicElements::Animation_ID::idle, Position, true);
}

void Entities::Characters::Enemies::NecroMancer::Attack(bool b)
{
}

void Entities::Characters::Enemies::NecroMancer::SpawnDeadEnemies()
{
}

void Entities::Characters::Enemies::NecroMancer::Load(std::ifstream& savefile)
{
	float x;
    float y;
    int iread;
	//std::cout << " NecroMancer " << std::endl;
    savefile >> iread;
	//std::cout << iread << " : iread" << std::endl;
    savefile >> iread;
	this->setLives(iread);
	//std::cout << iread << " : iread" << std::endl;
	savefile >> iread;
    this->setAlive(static_cast<bool>(iread));
	//std::cout << iread << " : iread" << std::endl;
	savefile >> x;
	savefile >> y;
	//std::cout << x << "," << y <<std::endl;
    this->setPosition(x,y);
    savefile >> x;
	savefile >> y;
	//std::cout << x << "," << y <<std::endl;
    this->setVelocity(x,y);
}
void Entities::Characters::Enemies::NecroMancer::Save(std::ofstream& savefile)
{
	savefile << this->getID() << std::endl;
    savefile << lives << std::endl;
    savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
}