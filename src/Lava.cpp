#include "../include/Entities/Obstacles/Lava.h"

#define TEXTUREPATH "Assets/Obstacles/Lava.png"


Entities::Obstacles::Lava::Lava(const sf::Vector2f pos):
    Obstacle(pos, sf::Vector2f(128.f,128.f), true, ID::lava)
{
    animation.Reset(TEXTUREPATH, pos, sf::Vector2f(128.f,128.f));
}

Entities::Obstacles::Lava::~Lava()
{
}

void Entities::Obstacles::Lava::Move()
{
	HitBox.setPosition(Position);
    Gravity();
    Velocity.y -= forca_empuxo * dt * MULT;
}

void Entities::Obstacles::Lava::Update()
{
    this->Move();
    animation.Update(Position);
    Position.y += Velocity.y;
}
#define JUMPHEIGHT -15
void Entities::Obstacles::Lava::OnCollision(Entities::Entity* ent)
{
    Entities::Characters::Character* pChar = static_cast<Entities::Characters::Character*>(ent);
	pChar->Damage(true);
	sf::Vector2f vel = sf::Vector2f( 0, JUMPHEIGHT/2);
	if(pChar->getPosition().x > Position.x)
		vel.x = -JUMPHEIGHT;
	else
		vel.x = JUMPHEIGHT;
	pChar->setVelocity(vel);
	pChar = NULL;
}
