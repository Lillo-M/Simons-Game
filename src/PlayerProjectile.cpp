#include "../include/Entities/PlayerProjectile.h"
Entities::PlayerProjectile::PlayerProjectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner){ }
Entities::PlayerProjectile::~PlayerProjectile(){ } 
void Entities::PlayerProjectile::Move()
{
    Gravity();
    velocity.y -= 1.f * gravity * dt * 60;
    Position.x += velocity.x * dt * 60;
    Position.y += velocity.y * dt * 60;
}