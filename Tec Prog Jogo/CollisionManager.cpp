#include "CollisionManager.h"

Managers::CollisionManager::CollisionManager()
{
	entities = NULL;
}

Managers::CollisionManager::~CollisionManager()
{
	entities = NULL;
}

void Managers::CollisionManager::getList(Math::List<Entities::Entity>& ents)
{
	entities = &ents;
}

void Managers::CollisionManager::Manage()
{
	float dist_x = 0;
	float dist_y = 0;
	float dx = 0;
	float dy = 0;
	for (int i = 0; i < entities->getSize(); i++)
	{
		for (int j = i + 1; j < entities->getSize(); j++)
		{

			dist_x = (*entities)[i]->getPosition().x - (*entities)[j]->getPosition().x;
			dist_y = (*entities)[i]->getPosition().y - (*entities)[j]->getPosition().y;
			if (dist_y < 0)
				dist_y = -dist_y;
			if (dist_x < 0)
				dist_x = -dist_x;
			dx = (*entities)[i]->getSize().x / 2 + (*entities)[j]->getSize().x / 2;
			dy = (*entities)[i]->getSize().y / 2 + (*entities)[j]->getSize().y / 2;
			if (dist_x < dx && dist_y < dy)
			{
				if (!(*entities)[i]->getIsGround())
				{
					(*entities)[i]->OnCollision((*entities)[j]);
				}
				else if (!(*entities)[j]->getIsGround())
				{
					(*entities)[j]->OnCollision((*entities)[i]);
				}
			}
		}
	}
}
