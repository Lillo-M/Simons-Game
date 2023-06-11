#pragma once

#include "../Character.h"
#include "../../../GraphicElements/ComplexAnimation.h"
namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
        class Enemy : public Character
        {
        public:
            Enemy(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), ID id = ID::empty, int lves = 0);
            virtual ~Enemy();
            virtual void Move() = 0;
            virtual void Attack(const bool b) = 0;
            virtual void Update() = 0;
            virtual void Draw() = 0;
            virtual void OnCollision(Entity* ent) = 0;
            virtual void Save(std::ofstream& savefile) = 0;
            virtual void Load(std::ifstream& savefile) = 0;
        protected:
            float attackTimer;
            GraphicElements::ComplexAnimation animation;
        };
        }
    }
}