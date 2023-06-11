#include "../include/Entities/Characters/Enemies/Horse.h"

#define SIZEX 100
#define SIZEY 46
#define DISTANCE_NM_ATTACK 1000.f
#define dPlayer Entities::Characters::Player *
#define MAXVELOCITY 40
#define NMSPEED 10
#define DAMAGE 2
#define ACCELERATION 1.f
#define SHOTCOUNT 10
#define LIVES 40
#define KNOCKBACK -11.f
#define IDLEPATH "Assets/Horse/nightmare-idle.png"
#define ATTACKPATH "Assets/Horse/nightmare-galloping.png"

Entities::Characters::Enemies::Horse::Horse(sf::Vector2f pos) : attacking(false), 
	dTime (0.f), 
	crash (false), 
	vulnerable(false),
	dashCharged(0.f), 
	faceRight(true),
	Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::horse, LIVES),
	fury(false),
	damage(DAMAGE),
	shotcount(0)
{
	balls.clear();
	for(int i = 0; i < SHOTCOUNT ; i++)
	{
		balls.push_back(new Entities::Projectiles::Skull(sf::Vector2f(0,0), sf::Vector2f(0,0), this));
	}
	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(4, 0), 0.25f);
	animation.pushAnimation(GraphicElements::Animation_ID::meleeattack, ATTACKPATH, sf::Vector2u(4, 0), 0.25f);
}

Entities::Characters::Enemies::Horse::~Horse()
{
}

void Entities::Characters::Enemies::Horse::Draw()
{
	animation.Draw();
}

void Entities::Characters::Enemies::Horse::Update()
{	
    if (attacking)
		animation.Update(GraphicElements::Animation_ID::meleeattack, Position, faceRight);
	else
		animation.Update(GraphicElements::Animation_ID::idle, Position, faceRight);

	this->Move();

}

void Entities::Characters::Enemies::Horse::Move()
{
	this->Gravity();

	dashCharged += dt;
	
	float absDist = (absolute(getNearest()->getPosition().x - Position.x));

	if ((absDist <= DISTANCE_NM_ATTACK || attacking || fury) && dashCharged >= 2.f) {
		if(!attacking) {
		if(Position.x > getNearest()->getPosition().x)
				faceRight = true;
			else
				faceRight = false;
		}
		attacking = true;
		if (faceRight){
			Velocity.x -= MULT * ACCELERATION * dt;
			if (Velocity.x < -MAXVELOCITY)
				Velocity.x = -MAXVELOCITY;
		}
		else if (!faceRight){
			Velocity.x += MULT * ACCELERATION * dt;
			if (Velocity.x > MAXVELOCITY)
				Velocity.x = MAXVELOCITY;
		}
		
		
		
		dTime += dt;
		vulnerable = false;
		this->Attack(true);
	}

	Position.x += Velocity.x * dt * MULT;
	Position.y += Velocity.y * dt * MULT;
}

void Entities::Characters::Enemies::Horse::Attack(const bool b)
{
	fury = true;
	if (dTime >= 1.f)
	{
		if (!crash)
			vulnerable = true;
		attacking = false;
		dashCharged = 0;
		dTime = 0;
		crash = false;
		if(Position.x > getNearest()->getPosition().x)
			faceRight = true;
		else
			faceRight = false;
		Velocity.x = 0;
		balls[shotcount]->Shoot(sf::Vector2f(Position.x +\
		(Size.x/2 + balls[shotcount]->getSize().x/2) * ( faceRight ? -1:1)\
		,Position.y - Size.y/2), sf::Vector2f(5 * ( faceRight ? -1:1), -20));
		shotcount++;
		if(shotcount >= SHOTCOUNT)
			shotcount = 0;
	}
}
dPlayer Entities::Characters::Enemies::Horse::getNearest()
{
	if (p2->getAlive() && p1->getAlive())
	{
		if (absolute(p1->getPosition().x - Position.x) > absolute(p2->getPosition().x - Position.x))
			return p2;
		else
			return p1;
	}
	else if(p2->getAlive())
		return p2;
	else /*  */
		return p1;
}

void Entities::Characters::Enemies::Horse::setPlayer(Player *player1)
{
	p1 = player1;
}
void Entities::Characters::Enemies::Horse::setPlayer2(Player *player2)
{
	p2 = player2;
}
void Entities::Characters::Enemies::Horse::Load(std::ifstream &savefile)
{

	float x;
	float y;
	int iread;
	// std::cout << " Horse " << std::endl;
	savefile >> iread;
	// std::cout << iread << " : iread" << std::endl;
	savefile >> iread;
	this->setLives(iread);
	// std::cout << iread << " : iread" << std::endl;
	savefile >> iread;
	this->setAlive(static_cast<bool>(iread));
	// std::cout << iread << " : iread" << std::endl;
	savefile >> x;
	savefile >> y;
	// std::cout << x << "," << y <<std::endl;
	this->setPosition(x, y);
	savefile >> x;
	savefile >> y;
	// std::cout << x << "," << y <<std::endl;
	this->setVelocity(x, y);
	savefile >> iread;
	this->faceRight = static_cast<bool>(iread);
	savefile >> x;
	this->dashCharged = x;
	savefile >> y;
	this->dTime = y;
	savefile >> iread;
	this->vulnerable = static_cast<bool>(iread);
	savefile >> iread;
	this->crash = static_cast<bool>(iread);
	savefile >> iread;
	this->attacking = static_cast<bool>(iread);
}
void Entities::Characters::Enemies::Horse::Save(std::ofstream &savefile)
{
	savefile << this->getID() << std::endl;
	savefile << lives << std::endl;
	savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl;
	savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
	savefile << faceRight << std::endl;
	savefile << dashCharged << std::endl;
	savefile << vulnerable << std::endl;
	savefile << crash << std::endl;
	savefile << attacking << std::endl;
	savefile << dTime << std::endl;
}

void Entities::Characters::Enemies::Horse::OnCollision(Entities::Entity *ent)
{
	//animation.Update(GraphicElements::Animation_ID::meleeattack, Position, faceRight); descobrir como fzr funcionar isso
	if (ent->getID() == ID::player)
	{
		crash = true;
		this->Attack(true);
		Entities::Characters::Player *pPlayer = static_cast<Entities::Characters::Player *>(ent);
		pPlayer->Damage(damage);
		sf::Vector2f vel = sf::Vector2f(0, KNOCKBACK / 2);
		if (pPlayer->getPosition().x > Position.x)
			vel.x = -KNOCKBACK;
		else
			vel.x = KNOCKBACK;
		pPlayer->setVelocity(vel);
		if(!pPlayer->getAlive())
			fury = false;
		pPlayer = NULL;
		return;
	}
	sf::Vector2f pos = ent->getPosition() -  Position;
	sf::Vector2f size = ent->getSize() -  Size;
	size.x /= 2;
	size.y /= 2;
	if((ent->getID() == ID::ground || ent->getID() == ID::lava) && attacking && Velocity.x == 0)
	{
		Velocity.y = -5;
	}
}

void Entities::Characters::Enemies::Horse::Damage(bool b)
{
	if (vulnerable)
		this->operator--();
	std::cout << "life :" << this->lives << std::endl;
}

std::vector<Entities::Projectiles::Skull*>* Entities::Characters::Enemies::Horse::getShots()
{
	return &balls;
}


dPlayer Entities::Characters::Enemies::Horse::p1(NULL);
dPlayer Entities::Characters::Enemies::Horse::p2(NULL);