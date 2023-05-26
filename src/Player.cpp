#include "../include/Entities/Characters/Player.h"

#define SIZEX 61.f
#define SIZEY 100.f
Entities::Characters::Player::Player(const sf::Vector2f pos) : 
	Character(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::player, LIVES),
	maxVelocity(MAXV),
	boolMoveLeft(false),
	BoolMoveRight(false),
	secondJump(false),
	fall(false),
	attackcd(0.f),
	attackcooled(true),
	shotcount(0)
{
	for(int i = 0; i < 10; i++)
	{
		Projectile* pAux = new Projectile(sf::Vector2f(0,0), sf::Vector2f(0,0), this);
		if(!pAux)
		{
			std::cout << std::endl << "ERROR: Failed to Memory Allocate" << std::endl;
			exit(1);
		}
		shots.push_back(pAux);
	}
	HitBox.setOrigin(SIZEX / 2, SIZEY / 2);
	/*if(!textureLoaded)
		if (texture.loadFromFile("Assets/Player-Idle.png"))
		{
			textureLoaded = true;
		}
		else
			std::cout << std::endl << "ERROR: FAIL TO LOAD PLAYER TEXTURE!" << std::endl;*/
	HitBox.setTexture(texture);
	animation.AnimationReset(texture, sf::Vector2u(4,1), static_cast<float>(0.25));
	HitBox.setTextureRect(animation.uvRect);
}

Entities::Characters::Player::~Player()
{
	/*std::vector<Projectile*>::iterator it = shots.begin();
	for(it; it != shots.end(); it++)
	{
		if(*it)
			delete *it;
	}*/
	shots.clear();
}

void Entities::Characters::Player::setDead() { alive = false; }

sf::Vector2f Entities::Characters::Player::getPosition() // botar na entidade
{
	return Position;
}

const sf::Vector2f Entities::Characters::Player::getVelocity() const { return velocity; } // botar na entidade

void Entities::Characters::Player::Move()
{
	if (boolMoveLeft)
	{
		if (velocity.x > -maxVelocity)
			velocity.x -= PSPEED * dt * MULT; // Velocidade De Teste
		else
			velocity.x = -maxVelocity; // Velocidade De Teste
		if (velocity.x < -maxVelocity)
			velocity.x = -maxVelocity;
	}
	if (BoolMoveRight)
	{
		if (velocity.x < maxVelocity)
			velocity.x += PSPEED * dt * MULT; // Velocidade De Teste
		else
			velocity.x = maxVelocity; // Velocidade De Teste
		if (velocity.x > maxVelocity)
			velocity.x = maxVelocity;
	}
	if (fall)
	{
		if (!grounded)
			velocity.y -= JUMPHEIGHT / 8 * dt * MULT; // Valores de Teste
		else
			fall = false;
	}

	if (velocity.x < 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
	{
		velocity.x += ATRITO * dt * MULT;
		if (velocity.x > 0)
			velocity.x = 0;
	}
	else if (velocity.x > 0 && !boolMoveLeft && !BoolMoveRight) // Atrito
	{
		velocity.x -= ATRITO * dt * MULT;
		if (velocity.x < 0)
			velocity.x = 0;
	}
	/*if(velocity.x > 0)
		HitBox.setScale(sf::Vector2f(-1, 1));
	else if(velocity.x < 0)
		HitBox.setScale(sf::Vector2f(1, 1));*/
	Position.x += velocity.x * dt * MULT;
	Position.y += velocity.y * dt * MULT;
	Gravity();
}

void Entities::Characters::Player::Update()
{
	this->Move();
	if(!attackcooled)
	{
		attackcd += dt;
		if(attackcd >= 0.34f)
		{
			attackcd -= 0.34f;
			attackcooled = true;
		}
	}
	Damage();
	HitBox.setPosition(Position);
	animation.update(Position);
	HitBox.setTextureRect(animation.uvRect);
}

void Entities::Characters::Player::Jump()
{
	if (grounded)
	{
		grounded = false;
		secondJump = true;
		fall = false;
		velocity.y = JUMPHEIGHT; // Valor De Teste
	}
	else if (secondJump)
	{
		fall = false;
		secondJump = false;
		velocity.y = JUMPHEIGHT; // Valor De Teste
	}
}

void Entities::Characters::Player::MoveRight(const bool b)
{
	if (b)
		HitBox.setScale(sf::Vector2f(-1, 1));
	else if (boolMoveLeft)
		HitBox.setScale(sf::Vector2f(1, 1));
	BoolMoveRight = b;
}

void Entities::Characters::Player::MoveLeft(const bool b)
{
	if (b)
		HitBox.setScale(sf::Vector2f(1, 1));
	else if (BoolMoveRight)
		HitBox.setScale(sf::Vector2f(-1, 1));
	boolMoveLeft = b;
}

void Entities::Characters::Player::Fall()
{
	fall = true;
}

void Entities::Characters::Player::Attack(const bool b)
{
	if (attackcooled && b)
	{
		attackcooled = false;
		shots[shotcount]->Shoot(sf::Vector2f(Position.x + \
		( SIZEX / 2 + shots[shotcount]->getSize().x / 2 ) * -HitBox.getScale().x, Position.y), \
	        sf::Vector2f(-HitBox.getScale().x * 15, 0));	
	
		shotcount++;
	
		if(shotcount >= shots.size())
			shotcount = 0;
	}
}
void Entities::Characters::Player::OnCollision(Entities::Entity *ent)
{
	/*if(ent->getID() == ID::enemy)
	{
		HitBox.setFillColor(sf::Color(sf::Color::Red));
	}
	else
	{
		HitBox.setFillColor(sf::Color(sf::Color::White));
		//normalCollision(ent);
	}*/
}

std::vector<Projectile*>* Entities::Characters::Player::getShots() {return &shots;}

sf::Texture* Entities::Characters::Player::texture(Managers::GraphicManager::getInstance()->loadTexture("Assets/Player-Idle.png"));
bool Entities::Characters::Player::textureLoaded = false;
