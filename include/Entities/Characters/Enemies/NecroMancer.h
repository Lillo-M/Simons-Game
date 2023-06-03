#pragma once

#include "Enemy.h"
#include "Warrior.h"
#include "Archer.h"
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
                void Save(std::ofstream& savefile);
                void Load(std::ifstream& savefile);
                void SpawnDeadEnemies();
            private:
                std::vector<Archer*> archers;
                std::vector<Warrior*> warriors;
            };
        }
    }
}