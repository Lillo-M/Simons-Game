#pragma once
#include <SFML/Graphics.hpp>
#include "Managers/GraphicManager.h"
#include <string>

enum ID
{
    empty       = -1,
    player      = 0,
    player2     = 1,
    enemy     = 2,
    obstacle        = 3
};


class Ente
{
public:
    Ente(ID id_ = empty);
    virtual ~Ente();
    virtual void Draw() = 0;
    const ID getID() const; 

private:
    const ID id;
protected:
    static Managers::GraphicManager* pGM;
};