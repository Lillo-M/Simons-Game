#include "../include/Levels/Level1.h"

Levels::Level1::Level1(Managers::EventsManager *pEM, States::StateMachine* pSM) : 
    Level(ID::level1, pEM, pSM)
{
    CreateMap();
    pCManager->setDList(DentitiesList);
    pCManager->setSList(SentitiesList);
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