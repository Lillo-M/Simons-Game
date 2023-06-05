#include "../include/Entities/PlayerProjectile.h"
#include "../include/Entities/Characters/Player.h"

Entities::PlayerProjectile::PlayerProjectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner): 
    Projectile (pos, velocity, owner)
{ 
    HitBox.setFillColor(sf::Color::Blue);
    animation.pushAnimation(GraphicElements::Animation_ID::idle, "Assets/Player/Charge_2.png", sf::Vector2u(6,0), 0.16f);
    animation.pushAnimation(GraphicElements::Animation_ID::attack, "Assets/Player/Charge_1.png", sf::Vector2u(6,0), 0.16f);
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
    //std::cout << targetID << std::endl;
    //std::cout << owner->getID() << std::endl;
    int targetID = ent->getID();
    if(targetID != ID::player && targetID != ID::obstacle && targetID != ID::lava && targetID != ID::ice && targetID != ID::ground)
    {
        //std::cout << "Character collided" << std::endl;
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
        if(!static_cast<Entities::Characters::Character*>(ent)->getAlive())
            static_cast<Entities::Characters::Player*>(owner)->Score(static_cast<Entities::Characters::Character*>(ent)->getID());
    }
    collided = true;
}

void Entities::PlayerProjectile::Update()
{
    Move();
    animation.Update(GraphicElements::Animation_ID::idle, Position, (Velocity.x > 0 ? true:false));
    //HitBox.setPosition(Position);
}

void Entities::PlayerProjectile::Draw()
{
    animation.Draw();
}

void Entities::PlayerProjectile::Shoot(sf::Vector2f pos, sf::Vector2f vel)
{
    Position = pos;
    Velocity = vel;
    collided = false;
    animation.Update(GraphicElements::Animation_ID::attack, Position, (Velocity.x > 0 ? true:false));
}
