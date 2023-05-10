#pragma once

#include "../Enemy.h"
#include "../Player.h"
#define ESPEED 1
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
                static sf::Texture texture; // Implementar em Enemy tipo A/B/C
                static bool textureLoaded;  //
            public:
                Warrior(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
                ~Warrior();
                void OnCollision(Entity* ent);
                void Move();
                void Attack(const bool b);
            };
        }
    }
}