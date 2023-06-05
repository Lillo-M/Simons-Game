#include "../include/Entities/Characters/Player.h"

#define IDLEPATH "Assets/Player/Idle.png"
#define WALKPATH "Assets/Player/Walk.png"
#define JUMPPATH "Assets/Player/Jump.png"
#define ATTACKPATH "Assets/Player/Magic_arrow.png"
#define HURTPATH "Assets/Player/Hurt.png"

#define SIZEX 40.f
#define SIZEY 66.f
#define LIVES 3
#define MAXV 10
#define ATRITO 0.45
#define JUMPHEIGHT -11.f
#define PSPEED 1

Entities::Characters::Player::Player(const sf::Vector2f pos) : 
	Character(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::player, LIVES),
	maxVelocity(MAXV),
	BoolMoveLeft(false),
	BoolMoveRight(false),
	secondJump(false),
	fall(false),
	attackcd(0.f),
	attackcooled(true),
	shootCount(0),
	animation(),
	faceRight(false),
	isJumping(false),
	onIce(false),
	Points(0)
{
	for(int i = 0; i < 10; i++)
	{
		Entities::PlayerProjectile* pAux = new Entities::PlayerProjectile(sf::Vector2f(0,0), sf::Vector2f(0,0), this);
		if(!pAux)
		{
			std::cout << std::endl << "ERROR: Failed to Memory Allocate" << std::endl;
			exit(1);
		}
		shots.push_back(pAux);
	}
	HitBox.setOrigin(0, 0);
	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(8,0), 0.125f);
	animation.pushAnimation(GraphicElements::Animation_ID::walk, WALKPATH, sf::Vector2u(7,0), 0.143f);
	animation.pushAnimation(GraphicElements::Animation_ID::jump, JUMPPATH, sf::Vector2u(8,0), 0.125f);
	animation.pushAnimation(GraphicElements::Animation_ID::attack, ATTACKPATH, sf::Vector2u(6,0), 0.06f);
	animation.pushAnimation(GraphicElements::Animation_ID::hurt, HURTPATH, sf::Vector2u(4,0), 0.25f);
}

Entities::Characters::Player::~Player()
{
	shots.clear();
}

sf::Vector2f Entities::Characters::Player::getPosition() // botar na entidade
{
	return Position;
}

const sf::Vector2f Entities::Characters::Player::getVelocity() const { return Velocity; } // botar na entidade

void Entities::Characters::Player::Move()
{
	if(onIce)
	{
		maxVelocity = 2 * MAXV;
	}
	else
		maxVelocity = MAXV;

	if (BoolMoveLeft)
	{
		if (Velocity.x > -maxVelocity)
			Velocity.x -= PSPEED * dt * MULT; // Velocidade De Teste
		else
			Velocity.x = -maxVelocity; // Velocidade De Teste
		if (Velocity.x < -maxVelocity)
			Velocity.x = -maxVelocity;
	}
	if (BoolMoveRight)
	{
		if (Velocity.x < maxVelocity)
			Velocity.x += PSPEED * dt * MULT; // Velocidade De Teste
		else
			Velocity.x = maxVelocity; // Velocidade De Teste
		if (Velocity.x > maxVelocity)
			Velocity.x = maxVelocity;
	}
	if (fall)
	{
		if (!grounded)
			Velocity.y -= JUMPHEIGHT / 8 * dt * MULT; // Valores de Teste
		else
			fall = false;
	}

	if (Velocity.x < 0 && !BoolMoveLeft && !BoolMoveRight) // Atrito
	{
		Velocity.x += ATRITO * dt * MULT;
		if (Velocity.x > 0)
			Velocity.x = 0;
	}
	else if (Velocity.x > 0 && !BoolMoveLeft && !BoolMoveRight) // Atrito
	{
		Velocity.x -= ATRITO * dt * MULT;
		if (Velocity.x < 0)
			Velocity.x = 0;
	}
	if(Velocity.x > 0)
		faceRight = true;
	else if(Velocity.x < 0)
		faceRight = false;
	Position.x += Velocity.x * dt * MULT;
	Position.y += Velocity.y * dt * MULT;
	Gravity();
}

void Entities::Characters::Player::Update()
{
	//std::cout << "Pontos: " << Points << std::endl;
	this->Move();
	if(!attackcooled)
	{
		attackcd += dt;
		if(attackcd >= 0.4f)
		{
			attackcd -= 0.4f;
			attackcooled = true;
		}
	}
	Damage();

	if(grounded)
		isJumping = false;
	
	if(damaged)
	{
		animation.Update(GraphicElements::Animation_ID::hurt, Position, faceRight);
	}
	else if(!attackcooled)
	{
		animation.Update(GraphicElements::Animation_ID::attack, Position, faceRight);
	}
	else if(isJumping)
	{
		animation.Update( GraphicElements::Animation_ID::jump,\
	Position, faceRight);
	}
	else if(Velocity.x)
		animation.Update( GraphicElements::Animation_ID::walk,\
	Position, faceRight);
	else
		animation.Update( GraphicElements::Animation_ID::idle,\
	Position, faceRight);
}

void Entities::Characters::Player::Draw()
{
    animation.Draw();
}

void Entities::Characters::Player::Jump()
{
	if (grounded)
	{
		grounded = false;
		isJumping = true;
		secondJump = true;
		fall = false;
		Velocity.y = JUMPHEIGHT; // Valor De Teste
	}
	else if (secondJump)
	{
		isJumping = true;
		fall = false;
		secondJump = false;
		Velocity.y = JUMPHEIGHT; // Valor De Teste
	}
}

void Entities::Characters::Player::MoveRight(const bool b)
{
	BoolMoveRight = b;
}

void Entities::Characters::Player::MoveLeft(const bool b)
{
	BoolMoveLeft = b;
}

void Entities::Characters::Player::Fall()
{
	fall = true;
}

void Entities::Characters::Player::Attack(const bool b)
{
	if (attackcooled && b && !damaged)
	{
		animation.Update(GraphicElements::Animation_ID::attack, Position, faceRight);
		attackcooled = false;
		shots[shootCount]->Shoot(sf::Vector2f(Position.x + \
		( SIZEX / 2 + shots[shootCount]->getSize().x / 2 ) * (faceRight ? 1:-1), Position.y - 15.f), \
	        sf::Vector2f((faceRight ? 1:-1) * 15, 0));	
	
		shootCount++;
	
		if(shootCount >= shots.size())
			shootCount = 0;
	}
}

void Entities::Characters::Player::setFacing(int side)
{
	faceRight = static_cast<bool>(side);
}

void Entities::Characters::Player::OnCollision(Entities::Entity *ent)
{
	if(ent->getID() == ID::ice)
	{
		onIce = true;
	}
	else if( ent->getID() == ID::ground || ent->getID() == ID::lava)
	{
		onIce = false;
	}
}

void Entities::Characters::Player::Save(std::ofstream& savefile)
{
	savefile << this->getID() << std::endl;
    savefile << lives << std::endl;
    savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
	savefile << faceRight << std::endl;
	for(int i = 0; i < shots.size(); i++)
	{
		shots[i]->Save(savefile);
	}
}
void Entities::Characters::Player::Load(std::ifstream &savefile)
{
}

void Entities::Characters::Player::Score(ID id)
{
	switch (id)
	{
	case ID::archer:
		Points +=  5000;
		break;
	case ID::warrior:
		Points +=  3000;
		break;
	case ID::necromancer:
		Points += 15000;
		break;
	}
}

const int Entities::Characters::Player::getPoints() const {return Points;}

std::vector<Entities::PlayerProjectile*>* Entities::Characters::Player::getShots() {return &shots;}