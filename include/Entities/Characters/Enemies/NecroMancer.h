#pragma once

#include "Enemy.h"
#include "Warrior.h"
#include "Archer.h"
#include "../Player.h"
#include <vector>

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
            class NecroMancer : public Enemy
            {
            public:
                NecroMancer(sf::Vector2f pos);
                ~NecroMancer();
                void Move();
                void Attack(const bool b);
                void Update();
                void Draw();
                void OnCollision(Entities::Entity* ent);
                void Save(std::ofstream& savefile);
                void Load(std::ifstream& savefile);
                void Damage();
                static void NMsetPlayer(Player* p1);
                static void NMsetPlayer2(Player* p2);
                Player* getNearest ();
            private:
                static Player* p1;
                static Player* p2;
                bool faceLeft;
                float dashCharged;
                bool vulnerable;
                bool crash;
                bool attacking;
                float dTime;
            };
        }
    }
}