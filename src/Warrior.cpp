#include "../include/Entities/Characters/Enemies/Warrior.h"
#define SIZEX 35.f
#define SIZEY 50.f
#define ESPEED 0.1
#define MAXV 10
#define KNOCKBACK -11.f
#define IDLEPATH "Assets/Warrior/Warrior-Idle.png"
#define WALKPATH "Assets/Warrior/Warrior-Walk.png"
#define MELEEATTACKPATH "Assets/Warrior/Warrior-Attack.png"

#define dEnemy Entities::Characters::Enemies

dEnemy::Warrior::Warrior(const sf::Vector2f pos):
    Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::warrior, 3),
	directiontimer(0),
	directionright(static_cast<bool>(rand()%2)),
	isAttacking(false)
{

	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(5,0), 0.2f);
	animation.pushAnimation(GraphicElements::Animation_ID::walk, WALKPATH, sf::Vector2u(7,0), 0.143f);
	animation.pushAnimation(GraphicElements::Animation_ID::meleeattack, MELEEATTACKPATH, sf::Vector2u(4,0), 0.1f);	
}

dEnemy::Warrior::~Warrior()
{
}

void dEnemy::Warrior::Move()
{
	directiontimer += dt;
	//
	if(directiontimer >= 2)
	{
		directionright = !directionright;
		directiontimer -= 2;
		Velocity.x = 0;
	}
	if(directionright)
	{
		if (Velocity.x < MAXV)
			Velocity.x += ESPEED * dt * MULT; // Velocidade De Teste
		if (Velocity.x > MAXV)
			Velocity.x = MAXV;
	}
	else if(!directionright)
	{
		if (Velocity.x > -MAXV)
			Velocity.x -= ESPEED * dt * MULT; // Velocidade De Teste
		if (Velocity.x < -MAXV)
			Velocity.x = -MAXV;
	}
	Position.x += Velocity.x * dt * MULT;
	Position.y += Velocity.y * dt * MULT;
	this->Gravity();
}

void dEnemy::Warrior::Update()
{
	if(isAttacking)
	{
		attackTimer += pGM->getDeltaTime();
		if( attackTimer >= 0.4f)
		{
			isAttacking = false;
			attackTimer = 0;
		}
		animation.Update(GraphicElements::Animation_ID::meleeattack, Position, directionright);
	}
	else
		animation.Update(GraphicElements::Animation_ID::walk, Position, directionright);
	this->Move();
	this->Damage();
	HitBox.setPosition(Position);
}

void dEnemy::Warrior::Draw()
{
	animation.Draw();
}


void dEnemy::Warrior::Attack(const bool b)
{
	if(b && !isAttacking)
	{
		attackTimer = 0;
		isAttacking = b;	
	}
}

void dEnemy::Warrior::OnCollision(Entities::Entity* ent)
{
	if(ent->getID() == ID::player)
	{
		Attack(true);
		Entities::Characters::Player* pPlayer = static_cast<Entities::Characters::Player*>(ent);
		pPlayer->Damage(true);
		sf::Vector2f vel = sf::Vector2f( 0, KNOCKBACK/2);
		if(pPlayer->getPosition().x > Position.x)
			vel.x = -KNOCKBACK;
		else
			vel.x = KNOCKBACK;
		pPlayer->setVelocity(vel);
		pPlayer = NULL;
	}
	else
	{
		Attack(false);
	}
}

void dEnemy::Warrior::Load(std::ifstream& savefile)
{
	float x;
    float y;
    int iread;
	//std::cout << " Warrior " << std::endl;
    savefile >> iread;
	//std::cout << iread << " : iread"<< std::endl;
    savefile >> iread;
	//std::cout << iread << " : iread"<< std::endl;
	this->setLives(iread);
	savefile >> iread;
	//std::cout << iread << " : iread"<< std::endl;
    this->setAlive(static_cast<bool>(iread));
	savefile >> x;
	savefile >> y;
	//std::cout << x << "," << y <<std::endl;
    this->setPosition(x,y);
    savefile >> x;
	savefile >> y;
	//std::cout << x << "," << y <<std::endl;
    this->setVelocity(x,y);
	savefile >> x;
	this->directiontimer = x;
	savefile >> iread;
	this->directionright = static_cast<bool>(iread);
}

void dEnemy::Warrior::Save(std::ofstream& savefile)
{
    savefile << this->getID() << std::endl;
    savefile << lives << std::endl;
    savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl; 
    savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
	savefile << directiontimer << std::endl;
	savefile << directionright << std::endl;
}