#include "../include/Entities/Ground.h"

Entities::Ground::Ground(const sf::Vector2f pos, const sf::Vector2f size):
	Entity(pos, size, true, "Obstacle")
{
	HitBox.setOrigin(size.x / 2, size.y / 2);
	if(!textureLoaded)
		if (!texture.loadFromFile("Assets/Ground2.png"))
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
	HitBox.setTexture(&texture);
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


sf::Texture Entities::Ground::texture;
bool Entities::Ground::textureLoaded = false;