#include "../include/Game.h"

Game::Game():
    pGM(Managers::GraphicManager::getInstance()),
    eManager(Managers::EventsManager::getInstance()),
    iManager(Managers::InputManager::getInstance())
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
    try{statesMap[States::stateID::alaska] = static_cast<States::State*>(new Levels::Alaska(static_cast<States::StateMachine*>(this), iManager));}
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }}
    /* */
    try{statesMap[States::stateID::vulcano] = static_cast<States::State*>(new Levels::Vulcano(static_cast<States::StateMachine*>(this), iManager));}
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

    static_cast<States::LoadGameState*>(statesMap[States::stateID::loadGameState])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::alaska]));

    static_cast<States::LoadGameState*>(statesMap[States::stateID::loadGameState])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::vulcano]));

    static_cast<Menus::NewGameMenu*>(statesMap[States::stateID::newGameMenu])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::alaska]));

    static_cast<Menus::NewGameMenu*>(statesMap[States::stateID::newGameMenu])->PushLevel(static_cast<Levels::Level*>(statesMap[States::stateID::vulcano]));
    
    currentState = States::stateID::mainMenu;
    Run();
}

Game::~Game()
{
    std::cout << "Game Destructor" << std::endl;
    std::map<States::stateID ,States::State*>::iterator it;
    for(it = statesMap.begin(); it != statesMap.end(); it++)
        delete it->second;
    if(iManager)
        delete iManager;
    iManager = NULL;
    if(eManager)
        delete eManager;
    eManager = NULL;
    if(pGM)
        delete pGM;
    pGM = NULL;
    Instance = NULL;
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

Game* Game::getInstance()
{
    if(!Instance)
	{
		try { Instance = new Game();} catch(int error)
		{ if(!error){
			std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        	exit(1);
		}}
	}
	return Instance;
}

Game* Game::Instance(NULL);