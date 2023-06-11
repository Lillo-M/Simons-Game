#include "../include/Levels/Alaska.h"

Levels::Alaska::Alaska(States::StateMachine* pSM, Managers::InputManager* pIM) : 
    Level(ID::alaska, States::stateID::alaska, pSM, pIM),
    isIcePool(false),
    pool(0)
{
    CreateMap();
    pCManager->setDList(DentitiesList.getTList());
    pCManager->setSList(SentitiesList.getTList());
    texture = pGM->loadTexture("Assets/Alaska.png");
    background.setTexture(*texture);
    background.setScale(1.25f, 0.75f);
    background.setOrigin(texture->getSize().x/(float)2, texture->getSize().y/(float)2);
}

Levels::Alaska::~Alaska()
{
}

void Levels::Alaska::CreateMap()
{
    std::ifstream Map;
    std::string str;
    int j = 0;
    Map.open("Assets/Alaska.txt");
    if (!Map.is_open())
    {
        std::cout << "ERROR: Failed to Open 'Alaska.txt'" << std::endl;
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

void Levels::Alaska::Draw()
{
    background.setPosition(pGM->getViewCenter());
    pGM->getWindow()->draw(background);
    DentitiesList.DrawEntities();
    SentitiesList.DrawEntities();
}

void Levels::Alaska::Update()
{
    if(!isRunning)
    {
        Entities::Characters::Enemies::Archer::setPlayer(pPlayer);
        Entities::Characters::Enemies::Archer::setPlayer2(pPlayer2);
        pGM->setRightLimit(6 * WIDTH);
        pGM->setBottomLimit(4 * HEIGHT);
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
    if(pPlayer->getPosition().x >= 6 * WIDTH + WIDTH/2 - 64.f || (twoPlayers && pPlayer2->getPosition().x >= 6 * WIDTH + WIDTH/2 - 64.f) )
        changeState(States::stateID::vulcano);
}

void Levels::Alaska::CreateIce(const sf::Vector2f pos)
{
    Entities::Obstacles::Ice *pAux = new Entities::Obstacles::Ice(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    SentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
}

void Levels::Alaska::CreateWarrior(const sf::Vector2f pos, bool isRandom)
{
    Entities::Characters::Enemies::Warrior *pAux = new Entities::Characters::Enemies::Warrior(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    DentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
    srand(time(NULL) + rand());
    if(isRandom && rand() % 2)
        pAux->setAlive(false);
    pAux = NULL;
}

void Levels::Alaska::CreateEntity(char id, sf::Vector2f pos)
{
    pos = sf::Vector2f( -64 + pos.x * 64, pos.y * 64);
    switch (id)
    {
    case 'P':
        CreatePlayer(pos);
        break;

    case 'W':
        CreateWarrior(pos);
        break;

    case 'R':
        CreateWarrior(pos, true);
        break;

    case 'C':
        CreateIce();
        CreateGround();
        srand(time(NULL) + rand());
        if(!pool)
            if(rand() % 2)
            {
                SentitiesList[SentitiesList.Size() - 2]\
                ->setPosition(pos);
                isIcePool = true;
                pool = 1;
            }
            else
            {
                SentitiesList[SentitiesList.Size() - 1]\
                ->setPosition(pos);
                pool = 1;
                isIcePool = false;
            }
        else
        {
            if(isIcePool)
                SentitiesList[SentitiesList.Size() - 2]\
                ->setPosition(pos);
            else
                SentitiesList[SentitiesList.Size() - 1]\
                ->setPosition(pos);
            pool++;
            if (pool >= 4)
                pool = 0;
        }
        break;

    case 'G':
        CreateGround(pos);
        break;

    case 'A':
        CreateArcher(pos);
        break;

    case 'H':
        CreateArcher(pos, true);
        break;

    case 'I':
        CreateIce(pos);
        break;

    }
}