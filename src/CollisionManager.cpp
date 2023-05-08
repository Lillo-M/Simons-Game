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

			dist_x = (*Dentities)[i]->getPosition().x - (*Dentities)[j]->getPosition().x;
			dist_y = (*Dentities)[i]->getPosition().y - (*Dentities)[j]->getPosition().y;
			if (dist_y < 0)
				dist_y = -dist_y;
			if (dist_x < 0)
				dist_x = -dist_x;
			dx = (*Dentities)[i]->getSize().x / 2 + (*Dentities)[j]->getSize().x / 2;
			dy = (*Dentities)[i]->getSize().y / 2 + (*Dentities)[j]->getSize().y / 2;
			if (dist_x < dx && dist_y < dy)
			{
					(*Dentities)[i]->OnCollision((*Dentities)[j]);
			}
		}
		for (int j = 0; j < Sentities->getSize(); j++)
		{

			dist_x = (*Dentities)[i]->getPosition().x - (*Sentities)[j]->getPosition().x;
			dist_y = (*Dentities)[i]->getPosition().y - (*Sentities)[j]->getPosition().y;
			if (dist_y < 0)
				dist_y = -dist_y;
			if (dist_x < 0)
				dist_x = -dist_x;
			dx = (*Dentities)[i]->getSize().x / 2 + (*Sentities)[j]->getSize().x / 2;
			dy = (*Dentities)[i]->getSize().y / 2 + (*Sentities)[j]->getSize().y / 2;
			if (dist_x < dx && dist_y < dy)
			{
				(*Dentities)[i]->OnCollision((*Sentities)[j]);
			}
		}

	}
}
