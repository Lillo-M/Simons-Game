#include "../include/Entities/Projectiles/Projectile.h"


Entities::Projectiles::Projectile::Projectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character* owner):
	Entity(pos, sf::Vector2f(20,20), false, ID::projectile),
    owner(owner),
    collided(false)
{
}

Entities::Projectiles::Projectile::~Projectile()
{
}

void Entities::Projectiles::Projectile::Shoot(sf::Vector2f pos, sf::Vector2f vel)
{
    Position = pos;
    Velocity = vel;
    collided = false;
}

void Entities::Projectiles::Projectile::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
    savefile << collided << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl; 
}

void Entities::Projectiles::Projectile::Load(std::ifstream& savefile)
{
    float x;
    float y;
    int iread;
    savefile >> iread;
    savefile >> iread;
    collided = static_cast<bool>(iread);
	savefile >> x;
	savefile >> y;
    this->setPosition(x,y);
    savefile >> x;
	savefile >> y;
    this->setVelocity(x,y);
}

Entities::Characters::Character* Entities::Projectiles::Projectile::getOwner() {return owner;}

const bool Entities::Projectiles::Projectile::getCollided() const { return collided;}
