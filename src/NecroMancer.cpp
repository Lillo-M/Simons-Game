#include "../include/Entities/Characters/Enemies/NecroMancer.h"

#define SIZEX 100
#define SIZEY 46
#define DISTANCE_NM_ATTACK 1000.f
#define dPlayer Entities::Characters::Player *
#define MAXVELOCITY 40
#define NMSPEED 10
#define ACCELERATION 1.f
#define IDLEPATH "Assets/NecroMancer/nightmare-idle.png"
#define ATTACKPATH "Assets/NecroMancer/nightmare-galloping.png"

Entities::Characters::Enemies::NecroMancer::NecroMancer(sf::Vector2f pos) : attacking(false), 
dTime (0.f), 
crash (false), 
vulnerable(false),
dashCharged(0.f), 
faceLeft(true),
 
Enemy(pos, sf::Vector2f(SIZEX, SIZEY), false, ID::necromancer, 40)
{
	animation.pushAnimation(GraphicElements::Animation_ID::idle, IDLEPATH, sf::Vector2u(4, 0), 0.25f);
	animation.pushAnimation(GraphicElements::Animation_ID::meleeattack, ATTACKPATH, sf::Vector2u(4, 0), 0.25f);
}

Entities::Characters::Enemies::NecroMancer::~NecroMancer()
{
}

void Entities::Characters::Enemies::NecroMancer::Draw()
{
	animation.Draw();
	sf::RectangleShape shape(sf::Vector2f(5.f, 5.f));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(Position.x, Position.y - this->getSize().y / 2 );
	pGM->Draw(shape);
}

void Entities::Characters::Enemies::NecroMancer::Update()
{
	float absDist = (abs(getNearest()->getPosition().x - Position.x));
	
    if (attacking)
		animation.Update(GraphicElements::Animation_ID::meleeattack, Position, faceLeft);
	else
		animation.Update(GraphicElements::Animation_ID::idle, Position, faceLeft);

	if (absDist <= DISTANCE_NM_ATTACK || attacking)
		this->Move();

}

void Entities::Characters::Enemies::NecroMancer::Move()
{
	dashCharged += dt;
	
	if (dashCharged >= 2.f) {
		attacking = true;
		if (faceLeft){
			Velocity.x -= MULT * ACCELERATION * dt;
			if (Velocity.x < -MAXVELOCITY)
				Velocity.x = -MAXVELOCITY;
		}
		else if (!faceLeft){
			Velocity.x += MULT * ACCELERATION * dt;
			if (Velocity.x > MAXVELOCITY)
				Velocity.x = MAXVELOCITY;
		}
		
		Position.x += Velocity.x * dt * MULT;
		Position.y += Velocity.y * dt * MULT;
		
		
		this->Gravity();
		dTime += dt;
		vulnerable = false;
		this->Attack(true);
	}
}

void Entities::Characters::Enemies::NecroMancer::Attack(const bool b)
{
	if (dTime >= 1.f)
	{
		if (!crash)
			vulnerable = true;
		attacking = false;
		dashCharged = 0;
		dTime = 0;
		crash = false;
		faceLeft = !faceLeft;
		Velocity.x = 0;
	}
}
dPlayer Entities::Characters::Enemies::NecroMancer::getNearest()
{
	if (p2)
	{
		if (abs(p1->getPosition().x - Position.x) > abs(p2->getPosition().x - Position.x))
			return p2;
		else
			return p1;
	}
	else
		return p1;
}

void Entities::Characters::Enemies::NecroMancer::NMsetPlayer(Player *player1)
{
	p1 = player1;
}
void Entities::Characters::Enemies::NecroMancer::NMsetPlayer2(Player *player2)
{
	p2 = player2;
}
void Entities::Characters::Enemies::NecroMancer::Load(std::ifstream &savefile)
{

	float x;
	float y;
	int iread;
	// std::cout << " NecroMancer " << std::endl;
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
	this->faceLeft = static_cast<bool>(iread);
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
void Entities::Characters::Enemies::NecroMancer::Save(std::ofstream &savefile)
{
	savefile << this->getID() << std::endl;
	savefile << lives << std::endl;
	savefile << alive << std::endl;
	savefile << Position.x << std::endl;
	savefile << Position.y << std::endl;
	savefile << Velocity.x << std::endl;
	savefile << Velocity.y << std::endl;
	savefile << faceLeft << std::endl;
	savefile << dashCharged << std::endl;
	savefile << vulnerable << std::endl;
	savefile << crash << std::endl;
	savefile << attacking << std::endl;
	savefile << dTime << std::endl;
}

void Entities::Characters::Enemies::NecroMancer::OnCollision(Entities::Entity *ent)
{
	//animation.Update(GraphicElements::Animation_ID::meleeattack, Position, faceLeft); descobrir como fzr funcionar isso
	if (ent->getID() == ID::player)
	{
		crash = true;
		this->Attack(true);
		Entities::Characters::Player *pPlayer = static_cast<Entities::Characters::Player *>(ent);
		pPlayer->Damage(true);
		pPlayer->Damage(true);
		pPlayer = NULL;
	}
}

void Entities::Characters::Enemies::NecroMancer::Damage()
{
	if (vulnerable)
		this->operator--();
	std::cout << "life :" << this->lives << std::endl;
}


dPlayer Entities::Characters::Enemies::NecroMancer::p1(NULL);
dPlayer Entities::Characters::Enemies::NecroMancer::p2(NULL);