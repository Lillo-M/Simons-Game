#include "../include/Entities/Ground.h"

Entities::Ground::Ground(const sf::Vector2f pos, const sf::Vector2f size):
	Entity(pos,size,true)
{
	HitBox.setOrigin(size.x / 2, size.y / 2);
	if (texture.loadFromFile("Assets/Ground2.png"))
	{
		HitBox.setTexture(&texture);
	}
	else
		std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
}

Entities::Ground::~Ground()
{
}

void Entities::Ground::Move()
{
	Gravity();
	velocity.y -= velocity.y;
	HitBox.setPosition(Position);
}
