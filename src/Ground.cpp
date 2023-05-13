#include "../include/Entities/Obstacles/Ground.h"

Entities::Obstacles::Ground::Ground(const sf::Vector2f pos, const sf::Vector2f size):
	Obstacle(pos, size, true, ID::obstacle)
{
	HitBox.setOrigin(size.x / 2, size.y / 2);
	if(!textureLoaded)
		if (!texture.loadFromFile("Assets/Ground2.png"))
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;
	HitBox.setTexture(&texture);
}

Entities::Obstacles::Ground::~Ground()
{
}

void Entities::Obstacles::Ground::OnCollision(Entities::Entity* ent)
{
}

sf::Texture Entities::Obstacles::Ground::texture;
bool Entities::Obstacles::Ground::textureLoaded = false;