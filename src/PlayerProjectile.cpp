#include "../include/Entities/PlayerProjectile.h"
Entities::PlayerProjectile::PlayerProjectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) 
: Projectile (pos, velocity, owner)
{ 
    HitBox.setFillColor(sf::Color::Blue);
}

Entities::PlayerProjectile::~PlayerProjectile(){ } 

void Entities::PlayerProjectile::Move()
{
    Gravity();
    Velocity.y -= 1.f * gravity * dt * 60;
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
}
void Entities::PlayerProjectile::OnCollision(Entities::Entity* ent)
{
    //std::cout << ent->getID() << std::endl;
    //std::cout << owner->getID() << std::endl;
    if(ent->getID() != owner->getID() && ent->getID() != ID::obstacle && ent->getID() != ID::lava && ent->getID() != ID::ice && ent->getID() != ID::ground)
    {
        //std::cout << "Character collided" << std::endl;
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
    }
    collided = true;
}

