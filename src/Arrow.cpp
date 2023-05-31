#include "../include/Entities/Arrow.h"
Entities::Arrow::Arrow(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner){ }

Entities::Arrow::~Arrow(){ } 

void Entities::Arrow::Move()
{
    velocity.y -= 1.f * gravity * dt * 60;
    Position.y += velocity.y * dt * 60;
    Gravity();
    Position.x += velocity.x * dt * 60;
    Position.y += velocity.y * dt * 60;
}