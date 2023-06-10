#include "../include/Entities/Projectiles/Skull.h"

#define RCOEFICIENT 0.966f
#define LIFETIME 4.f

Entities::Projectiles::Skull::Skull(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner):
    Projectile(pos,velocity,owner),
    timeCont(0),
    restorationCoeficient(RCOEFICIENT)
{
    Size = sf::Vector2f(50,50);
    animation.pushAnimation(GraphicElements::Animation_ID::idle, "Assets/Horse/fire-skull.png", sf::Vector2u(8,0), 0.125f);
}


Entities::Projectiles::Skull::~Skull()
{
}

void Entities::Projectiles::Skull::Draw()
{
    animation.Draw();
}

void Entities::Projectiles::Skull::Move()
{
    Gravity();
    Position.x += Velocity.x * dt * MULT;
    Position.y += Velocity.y * dt * MULT;
}

void Entities::Projectiles::Skull::Update()
{
    this->Move();
    animation.Update(GraphicElements::Animation_ID::idle, Position, true);
    timeCont += dt;
    if(timeCont >= LIFETIME)
    {    
        collided = true;
        timeCont = 0;
    }
}

void Entities::Projectiles::Skull::OnCollision(Entities::Entity* ent)
{
    int targetID = ent->getID();
    if(targetID == ID::player)
    {
        //std::cout << "Character collided" << std::endl;
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
        collided = true;
        return;
    }
    if(targetID == ID::projectile)
    {
        collided = true;
        return;
    }
    sf::Vector2f dist = ent->getPosition() - Position;
    sf::Vector2f size = ent->getSize() + Size;
    size.x /= 2;
    size.y /= 2;
    if(absolute(dist.x) - size.x > absolute(dist.y) - size.y)
    {
		Velocity.x = -Velocity.x * restorationCoeficient;
        if(dist.x > 0)
            Position.x += dist.x - size.x;
        else
            Position.x += dist.x + size.x;
    }
    else
    {
        Velocity.y = -Velocity.y * restorationCoeficient;
        if(dist.y > 0)
            Position.y += dist.y - size.y;
        else
            Position.y += dist.y + size.y;

    }
}