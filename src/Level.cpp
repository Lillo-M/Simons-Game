#include "../include/Levels/Level.h"

Levels::Level::Level(const ID id, const States::stateID sid, States::StateMachine* pSM, Managers::InputManager* pIM) : 
    State(pSM, sid),
    Being(id),
    pIM(pIM),
    pPlayer(NULL),
    pPlayer2(NULL),
    levelStarted(false),
    totalScore(0),
    ArcherInstances(0)
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
        pPIM = new Observers::PlayerInputManager(NULL, NULL, static_cast<States::State*>(this));
    }
    catch (int error){
        if(!error){
            std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
            exit(1);
        }
    }
    this->pIM->addObserver(static_cast<Observers::Observer*>(pPIM));
}

Levels::Level::~Level()
{
    std::cout << "Abstract Level Destructor" << std::endl;
    this->pIM->removeObserver(static_cast<Observers::Observer*>(pPIM));
    if(pPIM)
        delete pPIM;
    pPIM = NULL;
    DentitiesList.DeleteEntities();
    SentitiesList.DeleteEntities();
    if(pCManager)
        delete pCManager;
    pCManager = NULL;
    /* */
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
    std::vector<Entities::Projectiles::PlasmaBall*>::iterator it;
    for(it = pAux->getShots()->begin(); it != pAux->getShots()->end(); it++)
    {
	    DentitiesList.Push_FrontEntity(static_cast<Entities::Entity *>(*it));
    }

    DentitiesList.Push_FrontEntity(static_cast<Entities::Entity *>(pAux));
    pAux = NULL;
}

void Levels::Level::CreateArcher(const sf::Vector2f pos, bool isRandom)
{
    Entities::Characters::Enemies::Archer *pAux = new Entities::Characters::Enemies::Archer(pos);
    if (!pAux)
    {
        std::cout << std::endl
                  << "ERROR: Failed to Allocate Memory" << std::endl;
        exit(1);
    }
    std::cout << pAux->getID() << std::endl;
    DentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
    std::vector<Entities::Projectiles::Arrow*>::iterator it;
    for (it = pAux->getShots()->begin(); it != pAux->getShots()->end(); it++)
    {
        DentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(*it));
    }

    srand(time(NULL) + rand());
    if(isRandom && rand() % 2)
        pAux->setAlive(false);
    pAux = NULL;
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
    SentitiesList.Push_BackEntity(static_cast<Entities::Entity *>(pAux));
    pAux = NULL;
}

void Levels::Level::SaveLevel()
{
    std::ofstream savefile("Assets/levelSave.txt", std::ofstream::binary);
	std::string line;
	savefile << this->getID() << std::endl;
    savefile << twoPlayers << std::endl;
    savefile.close();
    savefile.open("Assets/dynamicEntitiesSave.txt", std::ofstream::binary);
    DentitiesList.Save(savefile);
    savefile.close();
    savefile.open("Assets/staticEntitiesSave.txt", std::ofstream::binary);
    SentitiesList.Save(savefile);
    savefile.close();
}

void Levels::Level::LoadLevel()
{
    int iread;
    float x;
    float y;
    std::ifstream savefile("Assets/savefile.txt", std::ifstream::binary);
    std::string line;
    savefile >> iread;
    savefile >> iread;
    twoPlayers = static_cast<bool>(iread);
    savefile.close();
    savefile.open("Assets/dynamicEntitiesSave.txt", std::ifstream::binary);
    DentitiesList.Load(savefile);
    savefile.close();
    savefile.open("Assets/staticEntitiesSave.txt", std::ifstream::binary);
    SentitiesList.Load(savefile);
    savefile.close();
    /*  */
}

void Levels::Level::Reset()
{
    ArcherInstances = 0;
    //std::cout<< "reset" << std::endl;
    DentitiesList.DeleteEntities();
    SentitiesList.DeleteEntities();
    /*  */

    pPlayer = NULL;
    pPlayer2 = NULL;
    this->CreateMap();
    //std::cout<< "Reset Complete" << std::endl;
}

int Levels::Level::getScore() const {return totalScore;}

int Levels::Level::getPlayerScore() const {return pPlayer->getPoints();}

int Levels::Level::getPlayer2Score() const {return pPlayer2->getPoints();}

const bool Levels::Level::getLevelStarted() const {return levelStarted;}

void Levels::Level::setTwoPlayers(bool twoPlayers) {Levels::Level::twoPlayers = twoPlayers;}

Observers::PlayerInputManager* Levels::Level::getPlayerInputManager() const { return pPIM;}

bool Levels::Level::twoPlayers(false);