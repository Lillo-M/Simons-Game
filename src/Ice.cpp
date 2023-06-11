#include "../include/Entities/Obstacles/Ice.h"

#define PATH "Assets/Obstacles/Ice.png"

Entities::Obstacles::Ice::Ice(const sf::Vector2f pos):
    Obstacle(pos, sf::Vector2f(128.f,128.f), ID::ice)
{
    animation.Reset(PATH, pos, sf::Vector2f(128.f,128.f));
}

Entities::Obstacles::Ice::~Ice()
{
}

void Entities::Obstacles::Ice::Move()
{
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
    Position.y += Velocity.y;
}

void Entities::Obstacles::Ice::Update()
{
    this->Move();
    animation.Update(Position);
}

void Entities::Obstacles::Ice::OnCollision(Entities::Entity* ent)
{
    if(ent->getID() == ID::player)
        static_cast<Entities::Characters::Player*>(ent)->setFriction(friction);
}

const float Entities::Obstacles::Ice::forca_empuxo(gravity);
const float Entities::Obstacles::Ice::friction(0);