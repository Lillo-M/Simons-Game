#include "../include/Entities/Obstacles/Ground.h"
#define SIZEX 128.f
#define SIZEY 128.f
Entities::Obstacles::Ground::Ground(const sf::Vector2f pos):
	Obstacle(pos, sf::Vector2f(SIZEX, SIZEY), true, ID::obstacle)
{
	HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
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