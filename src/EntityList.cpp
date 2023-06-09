#include "../include/Math/EntityList.h"

Math::EntityList::EntityList() : entity_list(),
	listIt(entity_list.begin())
{
}

Math::EntityList::~EntityList()
{
	this->Clear();
}

void Math::EntityList::UpdateEntities()
{
	for (listIt = entity_list.begin();
		 listIt != entity_list.end(); listIt++)
	{
		int id = listIt->getID();
		if (id != ID::lava && id != ID::ground && id != ID::ice)
		{
			if (id != ID::projectile)
			{
				if (!static_cast<Entities::Characters::Character *>(*listIt)->getAlive())
					continue;
			}
			else if (static_cast<Entities::Projectile *>(*listIt)->getCollided())
				continue;
		}
		listIt->Update();
	}
}

void Math::EntityList::DrawEntities()
{
	for (listIt = entity_list.begin();
		 listIt != entity_list.end(); listIt++)
	{
		int id = listIt->getID();
		if (id == ID::projectile)
		{
			if (static_cast<Entities::Projectile *>(*listIt)->getCollided())
				continue;
		}
		else if ((id == ID::player || id == ID::archer || id == ID::horse || id == ID::warrior)\
		&& !static_cast<Entities::Characters::Character *>(*listIt)->getAlive())
			continue;
		
		listIt->Draw();
	}
}

void Math::EntityList::Push_BackEntity(Entities::Entity *ent)
{
	if (!ent)
	{
		std::cout << "Error: NULL Pointer at EntityList Push!" << std::endl;
		exit(1);
	}
	entity_list.insert_back(ent);
}

void Math::EntityList::Push_FrontEntity(Entities::Entity *ent)
{
	if (!ent)
	{
		std::cout << "Error: NULL Pointer at EntityList Push!" << std::endl;
		exit(1);
	}
	entity_list.insert_front(ent);
}

void Math::EntityList::Clear()
{
	entity_list.clear();
}

void Math::EntityList::DeleteEntities()
{
	for (listIt = entity_list.begin();
		 listIt != entity_list.end(); listIt++)
	{
		if (*listIt)
		{
			delete *listIt;
		}
	}
	this->Clear();
}

void Math::EntityList::Save(std::ofstream &savefile)
{
	for (listIt = entity_list.begin();
		 listIt != entity_list.end(); listIt++)
	{
		if (listIt->getID() != ID::projectile)
		{
			listIt->Save(savefile);
		}
	}
}

void Math::EntityList::Load(std::ifstream& savefile)
{
	for (listIt = entity_list.begin();
		 listIt != entity_list.end(); listIt++)
	{
		if (listIt->getID() != ID::projectile)
		{
			listIt->Load(savefile);
		}
	}
}

int Math::EntityList::Size() {return entity_list.getSize();}

Math::List<Entities::Entity> &Math::EntityList::getTList()
{
	return entity_list;
}

Entities::Entity *Math::EntityList::operator[](int idx)
{
	if (idx < 0 || idx >  entity_list.getSize())
	{
		std::cout << "ERROR: List Segmentation Fault" << std::endl;
		exit(1);
	}
	listIt = entity_list.begin();
	for (int i = 0; i < idx; i++)
	{
		listIt++;
	}
	return *listIt;
}