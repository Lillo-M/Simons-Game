#include "../include/Levels/Level.h"

Levels::Level::Level(const ID id, Managers::EventsManager *pEM, States::StateMachine* pSM) : 
    State(pSM, States::stateID::playing),
    Being(id),
    pEManager(pEM),
    pPlayer(NULL),
    pPlayer2(NULL)
{
    try{
        pCManager = new Managers::CollisionManager;
    }
    catch (int error){
        if(!error){
            std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
            exit(1);
        }
    }
    try{
        pPIM = new Observers::PlayerInputManager;
    }
    catch (int error){
        if(!error){
            std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
            exit(1);
        }
    }
    try{
        pIM = new Managers::InputManager;
    }
    catch (int error){
        if(!error){
            std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
            exit(1);
        }
    }
    pIM->addObserver(static_cast<Observers::Observer*>(pPIM));
    pEM->setpInputManager(pIM);
    /*if (!pCManager)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }*/
}

Levels::Level::~Level()
{
    if(pPIM)
        delete pPIM;
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
        pPIM->setpPlayer(pAux);
    }
    else
    {
        pPlayer2 = pAux;
        pPIM->setpPlayer2(pAux);
    }
    DentitiesList.insert_back(static_cast<Entities::Entity *>(pAux));
    std::vector<Projectile*>::iterator it;
    for(it = pAux->getShots()->begin(); it != pAux->getShots()->end(); it++)
    {
	    DentitiesList.insert_back(static_cast<Entities::Entity *>(*it));
    }
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

void Levels::Level::Update()
{
    for (int i = 0; i < DentitiesList.getSize(); i++)
    {
    	if(DentitiesList[i]->getID() != ID::obstacle)
        {
        	if(DentitiesList[i]->getID() == ID::player || DentitiesList[i]->getID() == ID::enemy)
       		{	
       			if(!static_cast<Entities::Characters::Character*>(DentitiesList[i])->getAlive())
       				continue;
       		}
       		else
       			if(static_cast<Projectile*>(DentitiesList[i])->getCollided())
       				continue;
       	}
        DentitiesList[i]->Update();
    }
    for (int i = 0; i < SentitiesList.getSize(); i++)
    {
        SentitiesList[i]->Update();
    }
    Entities::Entity::updateDeltaTime(pGM->getDeltaTime());
    pGM->updateDeltaTime();
    pCManager->Manage();
    pGM->CenterView(pPlayer->getPosition());
}

void Levels::Level::Draw()
{
    for (int i = 0; i < DentitiesList.getSize(); i++)
    {
    	if(DentitiesList[i]->getID() != ID::obstacle)
    	{
    		if(DentitiesList[i]->getID() == ID::player || DentitiesList[i]->getID() == ID::enemy)
    		{	if(!static_cast<Entities::Characters::Character*>(DentitiesList[i])->getAlive())
    				continue;
    		}
    		else
    			if(static_cast<Projectile*>(DentitiesList[i])->getCollided())
    				continue;
    	}
        DentitiesList[i]->Draw();
    }
    for (int i = 0; i < SentitiesList.getSize(); i++)
    {
        SentitiesList[i]->Draw();
    }
}

Observers::PlayerInputManager* Levels::Level::getPlayerInputManager() const { return pPIM;}