#pragma once
#include "Entity.h"
namespace Entities
{
    namespace Characters
    {
        class Character : public Entities::Entity
        {
        public:
            Character(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, ID id = ID::empty);
            virtual ~Character();
            void operator--();
            virtual void Move() = 0;
            virtual void Attack(const bool b) = 0;
            const bool getAlive() const;
            virtual void OnCollision(Entity *ent);

        protected:
            int lives;
            bool alive;
        };
    }
}