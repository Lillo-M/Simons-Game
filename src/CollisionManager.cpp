#include "../include/Managers/CollisionManager.h"
#include <iostream>
Managers::CollisionManager::CollisionManager()
{
	Sentities = NULL;
	Dentities = NULL;
}

Managers::CollisionManager::~CollisionManager()
{
	Sentities = NULL;
	Dentities = NULL;
}

void Managers::CollisionManager::getSList(Math::List<Entities::Entity>& ents)
{
	Sentities = &ents;
}

void Managers::CollisionManager::getDList(Math::List<Entities::Entity>& ents)
{
	Dentities = &ents;
}

void Managers::CollisionManager::normalCollision(Entities::Entity* ent, float dist_x, float dist_y, float size_x, float size_y)
{
	/*float size_y = ent->getSize().y / 2 + getSize().y / 2;
	float size_x = ent->getSize().x / 2 + getSize().x / 2;
	float dist_y = ent->getPosition().y - Position.y;
	float dist_x = ent->getPosition().x - Position.x;*/
	if (abs(dist_x) - size_x > abs(dist_y) - size_y) // retirar ABS
	{
		if (dist_x > 0)
		{
			ent->setPosition( ent->getPosition().x + dist_x - size_x , ent->getPosition().y);
			if (ent->getVelocity().x > 0)
				ent->setVelocity( 0, ent->getVelocity().y);
		}
		if (dist_x < 0)
		{
			ent->setPosition( ent->getPosition().x + dist_x + size_x , ent->getPosition().y);
			if (ent->getVelocity().x < 0)
				ent->setVelocity( 0, ent->getVelocity().y);
		}
	}
	else
	{
		if (dist_y > 0)
		{
			ent->setPosition( ent->getPosition().x, ent->getPosition().y + dist_y - size_y);
			ent->setVelocity(ent->getVelocity().x,  0);
			ent->setGrounded(true);
		}
		if (dist_y < 0)
		{
			ent->setPosition( ent->getPosition().x, ent->getPosition().y + size_y + dist_y);
			ent->setVelocity(ent->getVelocity().x,  0);
		}
	}
}


void Managers::CollisionManager::Manage()
{
	float dist_x = 0;
	float dist_y = 0;
	float dx = 0;
	float dy = 0;
	for (int i = 0; i < Dentities->getSize(); i++)
	{
		for (int j = i + 1; j < Dentities->getSize(); j++)
		{
			dist_x = (*Dentities)[j]->getPosition().x - (*Dentities)[i]->getPosition().x;
			dist_y = (*Dentities)[j]->getPosition().y - (*Dentities)[i]->getPosition().y;
			dx = (*Dentities)[i]->getSize().x / 2 + (*Dentities)[j]->getSize().x / 2;
			dy = (*Dentities)[i]->getSize().y / 2 + (*Dentities)[j]->getSize().y / 2;

			
			if (abs(dist_x) < dx && abs(dist_y) < dy)
			{
				normalCollision((*Dentities)[i], dist_x, dist_y, dx, dy);
				(*Dentities)[i]->OnCollision((*Dentities)[j]);
				(*Dentities)[j]->OnCollision((*Dentities)[i]);
			}
		}
		for (int j = 0; j < Sentities->getSize(); j++)
		{

			dist_x = (*Sentities)[j]->getPosition().x - (*Dentities)[i]->getPosition().x;
			dist_y = (*Sentities)[j]->getPosition().y - (*Dentities)[i]->getPosition().y;
			dx = (*Dentities)[i]->getSize().x / 2 + (*Sentities)[j]->getSize().x / 2;
			dy = (*Dentities)[i]->getSize().y / 2 + (*Sentities)[j]->getSize().y / 2;
			if (abs(dist_x) < dx && abs(dist_y) < dy)
			{
				normalCollision((*Dentities)[i], dist_x, dist_y, dx, dy);
				(*Dentities)[i]->OnCollision((*Sentities)[j]);
			}
		}

	}
}
