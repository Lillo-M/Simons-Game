#include "../include/Math/EntityList.h"

Math::EntityList::EntityList():
	entity_list(),
	listIt(entity_list.begin())
{
}

Math::EntityList::~EntityList()
{
	this->Clear();	
}

void Math::EntityList::UpdateEntities()
{
	for(listIt = entity_list.begin();\
	   listIt != entity_list.end(); listIt++)
	{
    		if(listIt->getID() != ID::obstacle)
        	{
        		if(listIt->getID() == ID::player || listIt->getID() == ID::enemy)
       			{	
       				if(!static_cast<Entities::Characters::Character*>(*listIt)->getAlive())
    					continue;
	       		}
       			else
       				if(static_cast<Projectile*>(*listIt)->getCollided())
       					continue;
	       	}
        	listIt->Update();
    	}
}

void Math::EntityList::DrawEntities()
{
	for(listIt = entity_list.begin();\
	   listIt != entity_list.end(); listIt++)
	{
    		if(listIt->getID() != ID::obstacle)
        	{
        		if(listIt->getID() == ID::player || listIt->getID() == ID::enemy)
       			{	
       				if(!static_cast<Entities::Characters::Character*>(*listIt)->getAlive())
    					continue;
	       		}
       			else
       				if(static_cast<Projectile*>(*listIt)->getCollided())
       					continue;
	       	}
        	listIt->Draw();
    	}
}

void Math::EntityList::PushEntity(Entities::Entity* ent)
{
	if(!ent)
	{
		std::cout << "Error: NULL Pointer at EntityList Push!" << std::endl;
		exit(1);
	}
	entity_list.insert_back(ent);
}

void Math::EntityList::Clear()
{
	entity_list.clear();
}

void Math::EntityList::DeleteEntities()
{
	for(listIt = entity_list.begin();\
	   listIt != entity_list.end(); listIt++)
	{
		if(*listIt)
		{
			delete *listIt;
		}
	}
	this->Clear();
}

Math::List<Entities::Entity>& Math::EntityList::getTList()
{
	return entity_list;
}
