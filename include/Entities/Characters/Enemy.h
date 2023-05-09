#pragma once

#include "../Character.h"

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
        class Enemy : public Character
        {
        private:
        public:
            Enemy(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, std::string id = "Enemy");
            virtual ~Enemy();
            void operator--();
            virtual void Move() = 0;
            virtual void Attack(const bool b) = 0;
            virtual void OnCollision(Entity* ent);
            const bool getAlive() const;
        protected:
        };
        }
    }
}