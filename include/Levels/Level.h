#pragma once

#include <stdlib.h>

#include "../Managers/CollisionManager.h"
#include "../Managers/EventsManager.h"
#include "../Math/List.h"// remover se a classe EntityList funcionar (e estiver corretamente implementado)
#include "../Math/EntityList.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Projectiles/Arrow.h"
#include "../Entities/Characters/Enemies/Warrior.h"
#include "../Entities/Characters/Enemies/Archer.h"
#include "../Entities/Characters/Enemies/Horse.h"
#include "../Entities/Obstacles/Ground.h"
#include "../Entities/Obstacles/Lava.h"
#include "../Entities/Obstacles/Ice.h"
#include "../States/State.h"
#include "../Observers/PlayerInputManager.h"

namespace Levels
{
    class Level: public Being, public States::State
    {
    public:
        Level(const ID id = ID::level, const States::stateID sid = States::stateID::empty, States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        virtual ~Level();
        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void CreateEntity(char id, sf::Vector2f pos) = 0;
        void CreatePlayer(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateGround(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateArcher(const sf::Vector2f pos = sf::Vector2f(0, 0), bool isRandom = false);
        virtual void CreateMap() = 0;
        Observers::PlayerInputManager* getPlayerInputManager() const;
        void SaveLevel();
        void LoadLevel();
        void Reset();
        const bool getLevelStarted() const;
        int getScore() const;
        int getPlayerScore() const;
        int getPlayer2Score() const;
        static void setTwoPlayers(bool twoPlayers);
    protected:
        int ArcherInstances;
        static bool                         twoPlayers;
        int                                 totalScore;
        bool                                levelStarted;
    	Managers::InputManager*             pIM;
        Observers::PlayerInputManager*      pPIM;
        Entities::Characters::Player*       pPlayer;
        Entities::Characters::Player*       pPlayer2;
        Managers::CollisionManager*         pCManager;
        //Math::EntityTList                   SentitiesList;
        //Math::EntityTList                   DentitiesList;
	    Math::EntityList		            DentitiesList;
        Math::EntityList		            SentitiesList;
    };
}
