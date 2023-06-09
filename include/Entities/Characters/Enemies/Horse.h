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
            class Horse : public Enemy
            {
            public:
                Horse(sf::Vector2f pos);
                ~Horse();
                void Move();
                void Attack(const bool b);
                void Update();
                void Draw();
                void OnCollision(Entities::Entity* ent);
                void Save(std::ofstream& savefile);
                void Load(std::ifstream& savefile);
                void Damage(bool b);
                static void NMsetPlayer(Player* p1);
                static void NMsetPlayer2(Player* p2);
                Player* getNearest ();
            private:
                static Player* p1;
                static Player* p2;
                bool faceRight;
                float dashCharged;
                int damage;
                bool vulnerable;
                bool crash;
                bool attacking;
                bool fury;
                float dTime;
            };
        }
    }
}