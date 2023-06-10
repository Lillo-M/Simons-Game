#pragma once
#include "Enemy.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../../../GraphicElements/ComplexAnimation.h"
#include "../../Projectiles/Arrow.h"
#include "../Player.h"

#define MULT 60
#define DISTANCE_ARCHER_ATTACK 500.f

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
            class Archer : public Enemy
            {
            private:
                std::vector<Entities::Projectiles::Arrow*> aShots;
                static Player* p1;
                static Player* p2;
                bool attackcooled;
                bool faceRight;
                bool meele;
                bool shooting;
                bool aiming;
                float shoottimer;
                float meeletimer;
                float attackcd;
                int shootCount;
            public:
                Archer(const sf::Vector2f pos = sf::Vector2f(0, 0));
                ~Archer();
                void Update();
                void Move();
                void Draw();
                void Attack(const bool b);
                void Save(std::ofstream& savefile);
                void Load(std::ifstream& savefile);
                std::vector<Entities::Projectiles::Arrow*>* getShots();
                Player* getNearest ();
                static void setPlayer (Player* pPlayer);
                static void setPlayer2 (Player* pPlayer2);
                void OnCollision(Entities::Entity* ent);
            };
        }
    }
}