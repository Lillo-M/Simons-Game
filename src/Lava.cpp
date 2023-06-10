#include "../include/Entities/Obstacles/Lava.h"

#define TEXTUREPATH "Assets/Obstacles/Lava.png"

#define SIZEY 112.f
#define SIZEX 128.f

Entities::Obstacles::Lava::Lava(const sf::Vector2f pos):
    Obstacle(pos, sf::Vector2f(SIZEX,SIZEY), true, ID::lava),
	Damage(1)
{
    animation.Reset(TEXTUREPATH, pos, sf::Vector2f(SIZEX,SIZEY));
}

Entities::Obstacles::Lava::~Lava()
{
}

void Entities::Obstacles::Lava::Move()
{
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
	Position.y += Velocity.y;
}

void Entities::Obstacles::Lava::Update()
{
    this->Move();
    animation.Update(Position);
}

#define JUMPHEIGHT -15

void Entities::Obstacles::Lava::OnCollision(Entities::Entity* ent)
{
	if(ent->getID() != ID::player)
		return;
    Entities::Characters::Character* pChar = static_cast<Entities::Characters::Character*>(ent);
	pChar->Damage(Damage);
	sf::Vector2f vel = sf::Vector2f( 0, JUMPHEIGHT/2);
	if(pChar->getPosition().x > Position.x)
		vel.x = -JUMPHEIGHT;
	else
		vel.x = JUMPHEIGHT;
	pChar->setVelocity(vel);
	pChar = NULL;
}

const float Entities::Obstacles::Lava::forca_empuxo(gravity);