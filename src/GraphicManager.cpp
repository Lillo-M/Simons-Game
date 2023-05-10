#include "../include/Managers/GraphicManager.h"
//#include "GraphicManager.h"
Managers::GraphicManager::GraphicManager() : 
    window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game")
{
}

Managers::GraphicManager::~GraphicManager()
{
    if(Instance)
        delete Instance;
}

Managers::GraphicManager* Managers::GraphicManager::getInstance()
{
    if (!Instance)
    {
        Instance = new GraphicManager;
        if (!Instance)
        {
            std::cout << std::endl << "ERROR: Failed to Allocate Memory" << std::endl;
            return NULL;
        }
    }
    return Instance;
}

void Managers::GraphicManager::Draw(sf::RectangleShape &hitbox)
{
    window.draw(hitbox);
}

void Managers::GraphicManager::Draw(sf::Text &text)
{
    window.draw(text);
}
void Managers::GraphicManager::Display()
{
    window.display();
}

void Managers::GraphicManager::Clear()
{
    window.clear();
}

void Managers::GraphicManager::Close()
{
    window.close();
}

sf::RenderWindow* Managers::GraphicManager::getWindow() { return &window;}

const bool Managers::GraphicManager::isWindowOpen() const { return window.isOpen(); }

Managers::GraphicManager *Managers::GraphicManager::Instance(NULL);