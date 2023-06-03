#pragma once

#include "Enemy.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../../../GraphicElements/ComplexAnimation.h"
#include "../../Arrow.h"
#include "../Player.h"

#define MULT 60

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
            class Archer : public Enemy
            {
            private:
                std::vector<Arrow*> aShots;
                int shotcount;
                bool attackCD;
                GraphicElements::ComplexAnimation animation;
            public:
                Archer(const sf::Vector2f pos = sf::Vector2f(0, 0));
                ~Archer();
                void Update();
                void Move();
                void Draw();
                void Attack(const bool b);
                void Save(std::ofstream& savefile);
                void Load(std::ifstream& savefile);
                std::vector<Arrow*>* getShots();
            };
        }
    }
}