#pragma once

#include "Enemy.h"
#include "../Player.h"
#include <stdlib.h>
#include "../../../GraphicElements/ComplexAnimation.h"
#define MULT 60

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
            class Warrior : public Enemy
            {
            private:
                float directiontimer;
                bool directionright;
                float attacktimer;
                bool isAttacking;
                static sf::Texture* texture; // Implementar em Enemy tipo A/B/C
                GraphicElements::ComplexAnimation animation;
            public:
                Warrior(const sf::Vector2f pos = sf::Vector2f(0, 0));
                ~Warrior();
                void OnCollision(Entity* ent);
                void Move();
                void Update();
                void Draw();
                void Attack(const bool b);
                void Load(std::ifstream& savefile);
                void Save(std::ofstream& savefile);
            };
        }
    }
}