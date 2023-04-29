#include "CollisionManager.h"

Managers::CollisionManager::CollisionManager()
{
	entities = NULL;
}

Managers::CollisionManager::~CollisionManager()
{
	entities = NULL;
}

void Managers::CollisionManager::getList(std::list<Entities::Entity*>& ents)
{
	entities = &ents;
}

void Managers::CollisionManager::Manage()
{
	float dist_x = 0;
	float dist_y = 0;
	float dx = 0;
	float dy = 0;
	entIt = entities->begin();
	std::list<Entities::Entity*>::iterator It;
	for (entIt; entIt != entities->end(); entIt++)
	{
		It = entIt;
		It++;
		for (It; It != entities->end(); It++)
		{

			dist_x = (*entIt)->getPosition().x - (*It)->getPosition().x;
			dist_y = (*entIt)->getPosition().y - (*It)->getPosition().y;
			if (dist_y < 0)
				dist_y = -dist_y;
			if (dist_x < 0)
				dist_x = -dist_x;
			dx = (*entIt)->getSize().x / 2 + (*It)->getSize().x / 2;
			dy = (*entIt)->getSize().y / 2 + (*It)->getSize().y / 2;
			if (dist_x < dx && dist_y < dy)
			{
				if (!(*entIt)->getIsGround())
				{
					(*entIt)->OnCollision((*It));
				}
				else if (!(*It)->getIsGround())
				{
					(*It)->OnCollision((*entIt));
				}
			}
		}
	}
}
