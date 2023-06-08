#include "Levels/Level2.h"

Levels::Level2::Level2(States::StateMachine* pSM, Managers::InputManager* pIM) : 
    Level(ID::level2, States::stateID::level2, pSM, pIM)
{
    CreateMap();
    pCManager->setDList(DentitiesList.getTList());
    pCManager->setSList(SentitiesList);
    texture = pGM->loadTexture("Assets/Vulcano.png");
    background.setTexture(*texture);
    background.setScale(1.25f, 0.75f);
    background.setOrigin(texture->getSize().x/(float)2, texture->getSize().y/(float)2);
    /* */
}

Levels::Level2::~Level2()
{
}

void Levels::Level2::CreateMap()
{
    std::ifstream Map;
    std::string str;
    int j = 0;
    Map.open("Assets/Level2.txt");
    if (!Map.is_open())
    {
        std::cout << "ERROR: Failed to Open 'Level2.txt'" << std::endl;
        exit(1);
    }

    while (std::getline(Map, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                CreateEntity(str[i], sf::Vector2f(i, j));
            }
        }
        j++;
    }
    Map.close();
}

void Levels::Level2::Draw()
{
    Math::EntityTList::Iterator it;

    /* teste */
    background.setPosition(pGM->getViewCenter());
    pGM->getWindow()->draw(background);
    DentitiesList.DrawEntities();

    it = SentitiesList.begin();    
    for(it; it != SentitiesList.end(); it++)
    {
	    it->Draw();
    }
}

void Levels::Level2::Update()
{
    if(!isRunning)
    {
        if (previousState->getStateID() == States::stateID::level1)
        {
            pPlayer->setPoints(static_cast<Levels::Level*>(previousState)->getPlayerScore());
            pPlayer2->setPoints(static_cast<Levels::Level*>(previousState)->getPlayer2Score());
        }
        Entities::Characters::Enemies::Archer::setPlayer(pPlayer);
        Entities::Characters::Enemies::Archer::setPlayer2(pPlayer2);
        Entities::Characters::Enemies::NecroMancer::NMsetPlayer(pPlayer);
        Entities::Characters::Enemies::NecroMancer::NMsetPlayer2(pPlayer2);

        if(!twoPlayers)
            pPlayer2->setAlive(false);
    }
    levelStarted = true;
    isRunning = true;
    Math::EntityTList::Iterator it;
    DentitiesList.UpdateEntities();

    for (it = SentitiesList.begin(); it != SentitiesList.end(); it++)
    {
        it->Update();
    }

    Entities::Entity::updateDeltaTime(Managers::GraphicManager::getDeltaTime());
    Managers::GraphicManager::updateDeltaTime();
    pCManager->Manage();
    sf::Vector2f viewcenter = pPlayer->getPosition();
    if(twoPlayers && pPlayer2->getAlive()) 
    {
        viewcenter += pPlayer2->getPosition();
        viewcenter.x /= 2;
        viewcenter.y /= 2;
        if(!pPlayer->getAlive())
            viewcenter = pPlayer2->getPosition();
    }
    pGM->CenterView(viewcenter);
    
    if(!pPlayer->getAlive() && !pPlayer2->getAlive())
    {
        if(twoPlayers)
        {
            totalScore = pPlayer->getPoints() + pPlayer2->getPoints();
            changeState(States::stateID::gameOverState);    
        }
        else
        {
            totalScore = pPlayer->getPoints();
            changeState(States::stateID::gameOverState);   
        }
    }
}