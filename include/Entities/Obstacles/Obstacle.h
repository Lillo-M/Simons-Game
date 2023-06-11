#pragma once
#include "../Entity.h"

#include "../../GraphicElements/SimpleSprite.h"

namespace Entities
{
    namespace Obstacles
    {
        class Obstacle : public Entities::Entity
        {
        protected:
            GraphicElements::SimpleSprite animation;
        public:
            Obstacle(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), ID id = ID::obstacle);
            virtual ~Obstacle();
            virtual void OnCollision(Entities::Entity* ent) = 0;
            virtual void Move() = 0;
            virtual void Update() = 0;
            void Draw();
            void Save(std::ofstream& savefile);
            void Load(std::ifstream& savefile);
        };
    }
}