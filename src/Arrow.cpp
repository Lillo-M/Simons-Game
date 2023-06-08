#include "../include/Entities/Arrow.h"

Entities::Arrow::Arrow(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character *owner) : 
    Projectile (pos, velocity, owner)
{ 
    HitBox.setFillColor(sf::Color::Red);
    animation.Reset("Assets/Archer/Arrow.png", pos, sf::Vector2f(30.f,100.f));
}

Entities::Arrow::~Arrow(){ } 


void Entities::Arrow::Move()
{
    Velocity.y -= 0.f * gravity * dt * 60;
    Position.y += Velocity.y * dt * 60;
    Position.x += Velocity.x * dt * 60;
    Position.y += Velocity.y * dt * 60;
    Gravity();
}

void Entities::Arrow::OnCollision(Entities::Entity* ent)
{
    //std::cout << ent->getID() << std::endl;
    //std::cout << owner->getID() << std::endl;
    if(ent->getID() != owner->getID() && ent->getID() != ID::obstacle && ent->getID() != ID::lava && ent->getID() != ID::ice && ent->getID() != ID::ground && ent->getID() != ID::warrior && ent->getID() != ID::necromancer && ent->getID() != ID::projectile)
    {
        //std::cout << "Character collided" << std::endl;
        static_cast<Entities::Characters::Character*>(ent)->Damage(true);
    }
    collided = true;
}

void Entities::Arrow::Update()
{
    Move();
    (Velocity.x > 0 ? animation.faceRight(true):animation.faceRight(false));
    animation.Update(Position);
}

void Entities::Arrow::Draw()
{
	animation.Draw();
}
