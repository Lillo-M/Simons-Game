#include "../include/Entities/Projectiles/Arrow.h"

Entities::Projectiles::Arrow::Arrow(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) : 
    Projectile (pos, velocity, owner)
{ 
    animation.Reset("Assets/Archer/Arrow.png", pos, sf::Vector2f(30.f,100.f));
}

Entities::Projectiles::Arrow::~Arrow(){ } 


void Entities::Projectiles::Arrow::Move()
{
    Velocity.y -= 0.f * gravity * dt * 60;
   // Position.y += Velocity.y * dt * 60;
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
    Gravity();
}

void Entities::Projectiles::Arrow::OnCollision(Entities::Entity* ent)
{
    //std::cout << ent->getID() << std::endl;
    //std::cout << owner->getID() << std::endl;
    int targetID = ent->getID();
    if(targetID == ID::player)
    {
        //std::cout << "Character collided" << std::endl;
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
    }
    collided = true;
}

void Entities::Projectiles::Arrow::Update()
{
    Move();
    (Velocity.x > 0 ? animation.faceRight(true):animation.faceRight(false));
    animation.Update(Position);
}

void Entities::Projectiles::Arrow::Draw()
{
	animation.Draw();
}
