#include "../include/Entities/Obstacles/Obstacle.h"

Entities::Obstacles::Obstacle::Obstacle(const sf::Vector2f pos, const sf::Vector2f size, const bool isS, ID id):
    Entity(pos, size, isS, id)
{
}

Entities::Obstacles::Obstacle::~Obstacle()
{
}

void Entities::Obstacles::Obstacle::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
}

void Entities::Obstacles::Obstacle::Load(std::ifstream& savefile)
{
    int iread;
    savefile >> iread;
	savefile >> Position.x;
	savefile >> Position.y; 
    savefile >> Velocity.x;
	savefile >> Velocity.y;
}

void Entities::Obstacles::Obstacle::Draw()
{
	animation.Draw();
}