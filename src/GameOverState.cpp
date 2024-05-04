#include "../include/States/GameOverState.h"
#include "../Observers/TextInputObserver.h"
#include <iostream>
States::GameOverState::GameOverState(States::StateMachine* pSMachine, Managers::InputManager* pIM):
    State(pSMachine, States::stateID::gameOverState),
    pGM(Managers::GraphicManager::getInstance()),
    pIM(pIM)
{
    try{tIObserver = new Observers::TextInputObserver(this);}
    catch(int error){
    if(!error){   
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);}}
    
    font.loadFromFile(std::string(THE_WIZARD_PATH) + std::string("/Assets/arial.ttf"));
    gameOver.setFont(font);
    gameOver.setCharacterSize(30);
    gameOver.setStyle(sf::Text::Bold);
    gameOver.setFillColor(sf::Color::White);
    gameOver.setPosition(sf::Vector2f(WIDTH/2 - 120,-340));
    gameOver.setString("Game Over");
    Score.setFont(font);
    Score.setCharacterSize(30);
    Score.setStyle(sf::Text::Bold);
    Score.setFillColor(sf::Color::White);
    Score.setPosition(sf::Vector2f(WIDTH/2 - 120 ,-310));
    writingName.setFont(font);
    writingName.setCharacterSize(30);
    writingName.setStyle(sf::Text::Bold);
    writingName.setFillColor(sf::Color::White);
    writingName.setPosition(sf::Vector2f(WIDTH/2 - 90, 30));
    pIM->addObserver(tIObserver);
}

States::GameOverState::~GameOverState()
{
    //std::cout << "GameOverState Destructor" << std::endl;
    pIM->removeObserver(tIObserver);
    if(tIObserver)
        delete tIObserver;
    tIObserver = NULL;
}

void States::GameOverState::Update()
{
    isRunning = true;
    Score.setString("Score: " + std::to_string(static_cast<Levels::Level*>(previousState)->getScore()));
    writingName.setString(name);
}

void States::GameOverState::Draw()
{
    pGM->CenterView(sf::Vector2f(0,0));
    pGM->Draw(Score);
    pGM->Draw(writingName);
    pGM->Draw(gameOver);
}

void States::GameOverState::inputKey(std::string key)
{
    if(!this->getIsRunning())
        return;
    if(key == "Space")
        name.push_back(' ');
    else if (key == "BackSpace" && name.size() > 0)
        name.pop_back();
    else if (key.size() == 1)
        name += key;
    else if (key == "Enter")
    {
        this->SaveData();
    }
}

void States::GameOverState::SaveData()
{
    int leadersCount = 1;
    std::vector<std::string> names;
    std::vector<int> points;

    names.push_back(name);
    points.push_back(static_cast<Levels::Level*>(previousState)->getScore());

    std::ifstream ileadersArchive;
    std::string str;
    ileadersArchive.open("Assets/leaderboard.txt");
    if (!ileadersArchive.is_open())
    {
        std::cout << "ERROR: Failed to Open 'leaderboard.txt'" << std::endl;
        exit(1);
    }
    
    while (std::getline(ileadersArchive, str))
    {
        names.push_back(str);
        std::getline(ileadersArchive, str);
        points.push_back(stoi(str));
        leadersCount++;
    }
    ileadersArchive.close();
    std::ofstream oleadersArchive;
    oleadersArchive.open("Assets/leaderboard.txt");
    if (!oleadersArchive.is_open())
    {
        std::cout << "ERROR: Failed to Open 'leaderboard.txt'" << std::endl;
        exit(1);
    }
    int min = 0;
    selection_sort(points, leadersCount, names);
    if(leadersCount >= 7)
        min = leadersCount - 7;
    for(int i = leadersCount - 1; i >= min; i--)
    {
        oleadersArchive << names[i] << std::endl;
        oleadersArchive << points[i] << std::endl;
    }

    oleadersArchive.close();
    
    this->changeState(States::stateID::mainMenu);
    name.clear();
}

void States::GameOverState::selection_sort (std::vector<int> &A, int n, std::vector<std::string> &B) {
  if(n <= 1)
    return;
  int key = 0;
  int i = 0, j = 0;
  for(i = 0;i < n; i++)
  {
    key = i;
    for(j = i + 1; j < n; j++)
    {
      if(A[key] > A[j])
      {
        key = j;
      }
    }
    swap(A,i,key, B);
  }
}

void States::GameOverState::swap(std::vector<int> &A, int i, int j, std::vector<std::string> &B)
{
    std::string temp = B[i];
    int k = A[i];
    A[i] = A[j];
    A[j] = k;
    B[i] = B[j];
    B[j] = temp;
}