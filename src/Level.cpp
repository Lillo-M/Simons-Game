#include "../include/Levels/Level.h"

Levels::Level::Level(const ID id, Managers::EventsManager *pEM) : Being(id),
    pEManager(pEM),
    pCManager(new Managers::CollisionManager),
    pPlayer(NULL),
    pPlayer2(NULL)
{
    if (!pCManager)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
}

Levels::Level::~Level()
{
    for (int i = 0; i < DentitiesList.getSize(); i++)
    {
        if (DentitiesList[i])
            delete DentitiesList[i];
    }
    DentitiesList.clear();
    for (int i = 0; i < SentitiesList.getSize(); i++)
    {
        if (SentitiesList[i])
            delete SentitiesList[i];
    }
    if(pCManager)
        delete pCManager;
    SentitiesList.clear();
    if (pCManager)
        delete pCManager;
    }

void Levels::Level::CreatePlayer(const sf::Vector2f pos)
{
    Entities::Characters::Player *pAux = new Entities::Characters::Player(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    if(!pPlayer)
    {
        pPlayer = pAux;
        pEManager->setpPlayer(pAux);
    }
    else
    {
        pPlayer2 = pAux;
        pEManager->setpPlayer2(pAux);
    }
    DentitiesList.insert_back(static_cast<Entities::Entity *>(pAux));
}

void Levels::Level::CreateWarrior(const sf::Vector2f pos)
{
    Entities::Characters::Enemies::Warrior *pAux = new Entities::Characters::Enemies::Warrior(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    DentitiesList.insert_back(static_cast<Entities::Entity *>(pAux));
}

void Levels::Level::CreateGround(const sf::Vector2f pos)
{
    Entities::Obstacles::Ground *pAux = new Entities::Obstacles::Ground(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    SentitiesList.insert_back(static_cast<Entities::Entity *>(pAux));
}

void Levels::Level::Draw()
{
    for (int i = 0; i < DentitiesList.getSize(); i++)
    {
        DentitiesList[i]->Draw();
    }
    for (int i = 0; i < SentitiesList.getSize(); i++)
    {
        SentitiesList[i]->Draw();
    }
}

void Levels::Level::CreateEntity(char id, sf::Vector2f pos)
{
    pos = sf::Vector2f( 64 + pos.x * 64, pos.y * 64);
    switch (id)
    {
    case 'P':
        CreatePlayer(pos);
        break;
    case 'W':
        CreateWarrior(pos);
        break;
    case 'G':
        CreateGround(pos);
        break;
    }
}

void Levels::Level::Run()
{
    for (int i = 0; i < DentitiesList.getSize(); i++)
    {
        DentitiesList[i]->Move();
    }
    for (int i = 0; i < SentitiesList.getSize(); i++)
    {
        SentitiesList[i]->Move();
    }
    Entities::Entity::updateDeltaTime();
    pCManager->Manage();
    pGM->CenterView(pPlayer->getPosition());
}