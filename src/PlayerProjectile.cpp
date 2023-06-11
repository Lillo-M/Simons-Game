#include "../include/Entities/Projectiles/PlayerProjectile.h"
#include "../include/Entities/Characters/Player.h"

#define ATTACKPATH "Assets/Player/Charge_1.png"
#define IDLEPATH "Assets/Player/Charge_2.png"

Entities::Projectiles::PlasmaBall::PlasmaBall(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner): 
    Projectile (pos, velocity, owner)
{
    animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(6,0), 0.16f);
    animation.pushAnimation(GraphicElements::Animation_ID::attack, ATTACKPATH, sf::Vector2u(6,0), 0.16f);
}

Entities::Projectiles::PlasmaBall::~PlasmaBall(){ } 

void Entities::Projectiles::PlasmaBall::Move()
{
    Gravity();
    Velocity.y -= 1.f * gravity * dt * 60;
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
}
void Entities::Projectiles::PlasmaBall::OnCollision(Entities::Entity* ent)
{
    int targetID = ent->getID();
    if(targetID == ID::warrior || targetID == ID::archer || targetID == ID::horse )
    {
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);

        if(!static_cast<Entities::Characters::Character*>(ent)->getAlive())
            static_cast<Entities::Characters::Player*>(owner)->Score(static_cast<Entities::Characters::Character*>(ent)->getID());
    }
    collided = true;
}

void Entities::Projectiles::PlasmaBall::Update()
{
    Move();
    animation.Update(GraphicElements::Animation_ID::idle, Position, (Velocity.x > 0 ? true:false));
}

void Entities::Projectiles::PlasmaBall::Draw()
{
    animation.Draw();
}

void Entities::Projectiles::PlasmaBall::Shoot(sf::Vector2f pos, sf::Vector2f vel)
{
    Position = pos;
    Velocity = vel;
    collided = false;
    animation.Update(GraphicElements::Animation_ID::attack, Position, (Velocity.x > 0 ? true:false));
}
