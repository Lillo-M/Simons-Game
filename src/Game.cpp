#include "../include/Game.h"

Game::Game():
    pGM(Managers::GraphicManager::getInstance()),
    eManager(new Managers::EventsManager()),
    iManager(new Managers::InputManager())
{
    eManager->setpInputManager(iManager);
    try{statesMap[States::stateID::mainMenu] = static_cast<States::State*>(new Menus::MainMenu(static_cast<States::StateMachine*>(this), iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}
    
    try{statesMap[States::stateID::pauseMenu] = static_cast<States::State*>(new Menus::PauseMenu(static_cast<States::StateMachine*>(this), iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}
    /* */
    try{statesMap[States::stateID::level1] = static_cast<States::State*>(new Levels::Level1(static_cast<States::StateMachine*>(this), iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    try{statesMap[States::stateID::level2] = static_cast<States::State*>(new Levels::Level2(static_cast<States::StateMachine*>(this), iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    try{statesMap[States::stateID::loadGameState] = static_cast<States::State*>(new States::LoadGameState(static_cast<States::StateMachine*>(this)));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    try{statesMap[States::stateID::newGameMenu] = static_cast<States::State*>(new Menus::NewGameMenu(static_cast<States::StateMachine*>(this),iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    try{statesMap[States::stateID::leaderBoard] = static_cast<States::State*>(new Menus::LeaderBoard(static_cast<States::StateMachine*>(this),iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    try{statesMap[States::stateID::gameOverState] = static_cast<States::State*>(new States::GameOverState(static_cast<States::StateMachine*>(this),iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}

    static_cast<States::LoadGameState*>(statesMap[States::stateID::loadGameState])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::level1]));

    static_cast<States::LoadGameState*>(statesMap[States::stateID::loadGameState])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::level2]));

    static_cast<Menus::NewGameMenu*>(statesMap[States::stateID::newGameMenu])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::level1]));

    static_cast<Menus::NewGameMenu*>(statesMap[States::stateID::newGameMenu])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::level2]));
    
    currentState = States::stateID::mainMenu;
    Run();
}

Game::~Game()
{
    std::map<States::stateID ,States::State*>::iterator it;
    for(it = statesMap.begin(); it != statesMap.end(); it++)
        delete it->second;
    delete iManager;
    delete eManager;
}


void Game::Run()
{
    while(pGM->isWindowOpen())
    {
        pGM->Clear();
        this->runCurrentState();
        pGM->Display();
        this->eManager->Manage();
    }
}

