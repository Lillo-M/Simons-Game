#include "../include/Entities/Obstacles/Ice.h"
#define PATH "Assets/Obstacles/iceblock.png"

Entities::Obstacles::Ice::Ice(const sf::Vector2f pos):
    Obstacle(pos, sf::Vector2f(128.f,128.f), true, ID::ice)
{
    animation.Reset(PATH, pos, sf::Vector2f(128.f,128.f));
}

Entities::Obstacles::Ice::~Ice()
{
}

void Entities::Obstacles::Ice::Move()
{
	HitBox.setPosition(Position);
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
}

void Entities::Obstacles::Ice::Update()
{
    this->Move();
    animation.Update(Position);
    Position.y += Velocity.y;
}

void Entities::Obstacles::Ice::OnCollision(Entities::Entity* ent)
{
}