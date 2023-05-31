#include "../include/Entities/Projectile.h"


Entities::Projectile::Projectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character* owner):
	Entity(pos, sf::Vector2f(20,20), false, ID::projectile),
    owner(owner),
    collided(false)
{
    HitBox.setOrigin(sf::Vector2f(10,10));
	HitBox.setFillColor(sf::Color::Blue);
}

Entities::Projectile::~Projectile()
{
}

void Entities::Projectile::Update()
{
    Move();
    HitBox.setPosition(Position);
}

void Entities::Projectile::OnCollision(Entities::Entity* ent)
{
    if(ent->getID() != owner->getID() && ent->getID() != ID::obstacle)
    {
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);	    
    }
    collided = true;
}

void Entities::Projectile::Shoot(sf::Vector2f pos, sf::Vector2f vel)
{
    Position = pos;
    velocity = vel;
    collided = false;
}

const bool Entities::Projectile::getCollided() const { return collided;}
