#pragma once
#include <SFML/Graphics.hpp>
#include "Managers/GraphicManager.h"
#include <string>

enum ID
{
    empty           = -1,
    player          = 0,
    enemy           = 2,
    obstacle        = 3,
    level           = 4
};


class Being
{
public:
    Being(ID id_ = empty);
    virtual ~Being();
    virtual void Draw() = 0;
    const ID getID() const; 
    //virtual void Run() = 0;
private:
    const ID id;
protected:
    static Managers::GraphicManager* pGM;
};