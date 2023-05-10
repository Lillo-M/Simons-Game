#pragma once
#include <SFML/Graphics.hpp>
#include "Managers/GraphicManager.h"
#include <string>

class Ente
{
public:
    Ente(std::string id = "BackStageEnte");
    virtual ~Ente();
    virtual void Draw() = 0;
    const std::string getID() const; 

private:
    const std::string ID;
protected:
    static Managers::GraphicManager* pGM;
};