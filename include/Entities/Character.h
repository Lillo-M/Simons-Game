#pragma once
#include "Entity.h"
namespace Entities
{
    namespace Characters
    {
        class Character : public Entities::Entity
        {    
        private:
            bool damaged;
            float timecont;
        public:
            Character(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, ID id = ID::empty, int lves = 0);
            virtual ~Character();
            void operator--();
            virtual void Move() = 0;
            virtual void Attack(const bool b) = 0;
            const bool getAlive() const;
            virtual void OnCollision(Entity *ent);
            void Damage();
            void Damage(bool b);
        protected:
            int lives;
            bool alive;
        };
    }
}