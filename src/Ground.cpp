#include "../include/Entities/Obstacles/Ground.h"
#define SIZEX 128.f
#define SIZEY 128.f
#define TEXTUREPATH "Assets/Obstacles/Ground2.png"

Entities::Obstacles::Ground::Ground(const sf::Vector2f pos):
	Obstacle(pos, sf::Vector2f(SIZEX, SIZEY), true, ID::ground)
{
	animation.Reset(TEXTUREPATH, pos, sf::Vector2f(128.f,128.f));
}

Entities::Obstacles::Ground::~Ground()
{
}

void Entities::Obstacles::Ground::OnCollision(Entities::Entity* ent)
{
}

void Entities::Obstacles::Ground::Move()
{
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
    Position.y += Velocity.y;
}

void Entities::Obstacles::Ground::Update()
{
	this->Move();
	animation.Update(Position);
}