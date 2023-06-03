#pragma once

#include "Enemy.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../../../GraphicElements/ComplexAnimation.h"
#include "../../Arrow.h"
#include "../Player.h"
#define MULT 60
#define DISTANCE_ARCHER_ATTACK 500

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
                static sf::Texture* texture; 
                GraphicElements::ComplexAnimation animation;
                static Player* p1;
                static Player* p2;
                bool attackcooled;
                const bool faceRight;
                float attackcd;
                int count;
            public:
                Archer(const sf::Vector2f pos = sf::Vector2f(0, 0));
                ~Archer();
                void Update();
                void Move();
                void Draw();
                void Attack(const bool b);
                std::vector<Arrow*>* getShots();
                Player* getNearest ();
                static void setPlayer (Player* pPlayer);
                static void setPlayer2 (Player* pPlayer2);
            };
        }
    }
}