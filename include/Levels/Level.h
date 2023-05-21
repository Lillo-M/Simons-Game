#pragma once
#include <vector>
#include "../Managers/CollisionManager.h"
#include "../Managers/EventsManager.h"
#include "../Math/List.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Characters/Enemies/Warrior.h"
#include "../Entities/Obstacles/Ground.h"
#include "../States/State.h"

namespace Levels
{
    class Level: public Being, public States::State
    {
    private:
    public:
        Level(const ID id = ID::level, Managers::EventsManager* pEM = NULL, States::StateMachine* pSM = NULL);
        virtual ~Level();
        virtual void Draw() ;
        virtual void Update();
        void CreateWarrior(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreatePlayer(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateGround(const sf::Vector2f pos = sf::Vector2f(0, 0));
        virtual void CreateMap() = 0;
        void CreateEntity(char id, sf::Vector2f pos);
    protected:
        Entities::Characters::Player* pPlayer;
        Entities::Characters::Player* pPlayer2;
        Managers::EventsManager* pEManager;
        Managers::CollisionManager* pCManager;
        Math::EntityList SentitiesList;
        Math::EntityList DentitiesList;
    };
}
