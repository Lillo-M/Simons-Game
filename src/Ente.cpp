#include "../include/Ente.h"
#include <iostream>

Ente::Ente(std::string id) : 
	ID(id)
{
}

Ente::~Ente()
{
}

const std::string Ente::getID() const
{
	return ID;
}

Managers::GraphicManager* Ente::pGM(Managers::GraphicManager::getInstance());