#include "../include/Levels/Level1.h"

Levels::Level1::Level1(States::StateMachine* pSM, Managers::InputManager* pIM) : 
    Level(ID::level1, States::stateID::level1, pSM, pIM)
{
    CreateMap();
    pCManager->setDList(DentitiesList.getTList());
    pCManager->setSList(SentitiesList);
    texture = pGM->loadTexture("Assets/Alaska.png");
    background.setTexture(*texture);
    background.setScale(0.45f, 0.47f);
    background.setOrigin(texture->getSize().x/(float)2, texture->getSize().y/(float)2);
}

Levels::Level1::~Level1()
{
}

void Levels::Level1::CreateMap()
{
    std::ifstream Map;
    std::string str;
    int j = 0;
    Map.open("Assets/Level1.txt");
    if (!Map.is_open())
    {
        std::cout << "ERROR: Failed to Open 'Level1.txt'" << std::endl;
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

void Levels::Level1::Draw()
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

void Levels::Level1::Update()
{
    if(!isRunning)
    {
        Entities::Characters::Enemies::Archer::setPlayer(pPlayer);
        Entities::Characters::Enemies::Archer::setPlayer2(pPlayer2);
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
    if(pPlayer->getPosition().x >= 6 * WIDTH + WIDTH/2 - 64.f || twoPlayers && pPlayer2->getPosition().x >= 6 * WIDTH + WIDTH/2 - 64.f )
        changeState(States::stateID::level2);
}