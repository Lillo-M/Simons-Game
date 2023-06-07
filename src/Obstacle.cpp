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
}

void Entities::Obstacles::Obstacle::Load(std::ifstream& savefile)
{
}

void Entities::Obstacles::Obstacle::Draw()
{
	animation.Draw();
}