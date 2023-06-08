#include "../include/Menus/LeaderBoard.h"

Menus::LeaderBoard::LeaderBoard(States::StateMachine* pSM, Managers::InputManager* pIM):
    Menu(),
    State(pSM, States::stateID::leaderBoard),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this))),
    pIM(pIM),
    textCount(0)
{
    font.loadFromFile("Assets/arial.ttf");
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,340), 30, "Go Back"));
    buttons[currentButtom]->Selected();
    std::ifstream leadersArchive;
    std::string str;
    leadersArchive.open("Assets/leaderboard.txt");
    if (!leadersArchive.is_open())
    {
        std::cout << "ERROR: Failed to Open 'leaderboard.txt'" << std::endl;
        exit(1);
    }
    
    while (std::getline(leadersArchive, str))
    {
        std::cout << str << std::endl;
        names.push_back(str);
        std::getline(leadersArchive, str);
        points.push_back(stoi(str));
        textCount++;
    }

    std::cout << "Chegou até aqui" << std::endl;
    leadersArchive.close();
    for(int i = 0; i < textCount; i++)
    {
        sf::Text* pAux = new sf::Text(std::to_string(i + 1) + "- " + names[i] + " - " + std::to_string(points[i]), font, 30);
        pAux->setPosition(sf::Vector2f(WIDTH/2 - 90,-340 + i * 30));
        Leaders.push_back(pAux);
    }
    std::cout << "Chegou até aqui" << std::endl;
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));
}

Menus::LeaderBoard::~LeaderBoard()
{
    pIM->removeObserver(pMObserver);
    if(pMObserver)
        delete pMObserver;
    pMObserver = NULL;
    for(int i = 0; i < buttomCont; i++)
    {
        if(buttons[i])
            delete buttons[i];
    }
    buttons.clear();
    for(int i = 0; i < textCount; i++)
    {
        if(Leaders[i])
            delete Leaders[i];
    }
    Leaders.clear();
}

void Menus::LeaderBoard::MoveUp()
{
}

void Menus::LeaderBoard::MoveDown()
{
}

void Menus::LeaderBoard::Select()
{
    if(!this->getIsRunning())
        return;
    this->changeState(States::stateID::mainMenu);
}

void Menus::LeaderBoard::Update()
{
    if(!isRunning)
    {
        std::cout << "resetou" << std::endl;
        this->Reset();
    }
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::LeaderBoard::Draw()
{
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Draw();
    }
    for(int i = 0; i < textCount; i++)
    {
        pGM->Draw(*Leaders[i]);
    }
}

void Menus::LeaderBoard::Reset()
{
    for(int i = 0; i < textCount; i++)
    {
        if(Leaders[i])
            delete Leaders[i];
    }
    Leaders.clear();
    names.clear();
    points.clear();
    textCount = 0;
    std::ifstream leadersArchive;
    std::string str;
    leadersArchive.open("Assets/leaderboard.txt");
    if (!leadersArchive.is_open())
    {
        std::cout << "ERROR: Failed to Open 'leaderboard.txt'" << std::endl;
        exit(1);
    }
    
    while (std::getline(leadersArchive, str))
    {
        names.push_back(str);
        std::getline(leadersArchive, str);
        points.push_back(stoi(str));
        textCount++;
    }

    leadersArchive.close();
    for(int i = 0; i < textCount; i++)
    {
        sf::Text* pAux = new sf::Text(std::to_string(i + 1) + "- " + names[i] + " - " + std::to_string(points[i]), font, 30);
        pAux->setPosition(sf::Vector2f(20,-384 + i * 30));
        Leaders.push_back(pAux);
    }
}