#include "../include/Entities/Arrow.h"
Entities::Arrow::Arrow(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner){
    HitBox.setFillColor(sf::Color::Red);
 }

Entities::Arrow::~Arrow(){ } 

void Entities::Arrow::Move()
{
    Position.x += Velocity.x * dt * 60;
    Velocity.y -= 0.f * gravity * dt * 60;
    Position.y += Velocity.y * dt * 60;
    Gravity();
}