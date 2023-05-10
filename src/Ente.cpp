#include "../include/Ente.h"
#include <iostream>

Ente::Ente(ID _id) : 
	id(_id)
{
}

Ente::~Ente()
{
}

const ID Ente::getID() const
{
	return id;
}

Managers::GraphicManager* Ente::pGM(Managers::GraphicManager::getInstance());