#include "Levels/Vulcano.h"

Levels::Vulcano::Vulcano(States::StateMachine* pSM, Managers::InputManager* pIM) : 
    Level(ID::vulcano, States::stateID::vulcano, pSM, pIM),
    pool(0),
    isLavaPool(false)
{
    CreateMap();
    pCManager->setDList(DentitiesList.getTList());
    pCManager->setSList(SentitiesList.getTList());
    texture = pGM->loadTexture("Assets/Vulcano.png");
    background.setTexture(*texture);
    background.setScale(1.25f, 0.75f);
    background.setOrigin(texture->getSize().x/(float)2, texture->getSize().y/(float)2);
}

Levels::Vulcano::~Vulcano()
{
}

void Levels::Vulcano::CreateMap()
{
    std::ifstream Map;
    std::string str;
    int j = 0;
    Map.open("Assets/Vulcano.txt");
    if (!Map.is_open())
    {
        std::cout << "ERROR: Failed to Open 'Vulcano.txt'" << std::endl;
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

void Levels::Vulcano::Draw()
{
    background.setPosition(pGM->getViewCenter());
    pGM->getWindow()->draw(background);
    DentitiesList.DrawEntities();
    SentitiesList.DrawEntities();
}

void Levels::Vulcano::Update()
{
    if(!isRunning)
    {
        if (previousState->getStateID() == States::stateID::alaska)
        {
            pPlayer->setPoints(static_cast<Levels::Level*>(previousState)->getPlayerScore());
            pPlayer2->setPoints(static_cast<Levels::Level*>(previousState)->getPlayer2Score());
        }
        Entities::Characters::Enemies::Archer::setPlayer(pPlayer);
        Entities::Characters::Enemies::Archer::setPlayer2(pPlayer2);
        Entities::Characters::Enemies::Horse::setPlayer(pPlayer);
        Entities::Characters::Enemies::Horse::setPlayer2(pPlayer2);

        pGM->setRightLimit(6 * WIDTH);
        pGM->setBottomLimit(3.41f * HEIGHT);
        
        if(!twoPlayers)
            pPlayer2->setAlive(false);
    }
    levelStarted = true;
    isRunning = true;
    DentitiesList.UpdateEntities();
    SentitiesList.UpdateEntities();

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
    
    if(!pPlayer->getAlive() && !pPlayer2->getAlive() || !Boss->getAlive())
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

void Levels::Vulcano::CreateHorse(const sf::Vector2f pos)
{
    Entities::Characters::Enemies::Horse *pAux = new Entities::Characters::Enemies::Horse(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    std::vector<Entities::Projectiles::Skull*>* shots = pAux->getSkulls();
    DentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
    for(int i = 0; i < 10; i++)
    {
        DentitiesList.Push_BackEntity(shots->operator[](i));
    }
    Boss = pAux;
    pAux = NULL;
    /* */
}

void Levels::Vulcano::CreateLava(const sf::Vector2f pos)
{
    Entities::Obstacles::Lava *pAux = new Entities::Obstacles::Lava(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    SentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
    pAux = NULL;
}

void Levels::Vulcano::CreateEntity(char id, sf::Vector2f pos)
{
    pos = sf::Vector2f( -64 + pos.x * 64, pos.y * 64);
    switch (id)
    {
    case 'P':
        CreatePlayer(pos);
        break;
    case 'G':
        CreateGround(pos);
        break;
    case 'L':
        CreateLava(pos);
        break;
    case 'C':
        CreateLava();
        CreateGround();
        srand(time(NULL) + rand());
        if(!pool)
            if(rand() % 2)
            {
                SentitiesList[SentitiesList.Size() - 2]\
                ->setPosition(pos);
                isLavaPool = true;
                pool = 1;
            }
            else
            {
                SentitiesList[SentitiesList.Size() - 1]\
                ->setPosition(pos);
                pool = 1;
                isLavaPool = false;
            }
        else
        {
            if(isLavaPool)
                SentitiesList[SentitiesList.Size() - 2]\
                ->setPosition(pos);
            else
                SentitiesList[SentitiesList.Size() - 1]\
                ->setPosition(pos);
            pool++;
            if (pool >= 3)
                pool = 0;
        }
        break;
    case 'A':
        CreateArcher(pos);
        break;
    case 'H':
        CreateArcher(pos, true);
        break;
    case 'N':
        CreateHorse(pos);
        break;
    }
}