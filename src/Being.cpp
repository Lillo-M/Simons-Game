#include "../include/Being.h"

Being::Being(ID _id) : 
	id(_id)
{
}

Being::~Being()
{
}

const ID Being::getID() const
{
	return id;
}

Managers::GraphicManager* Being::pGM(Managers::GraphicManager::getInstance());