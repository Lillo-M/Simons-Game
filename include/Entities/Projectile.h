#pragma once

#include "Characters/Character.h"
#include "Entity.h"
namespace Entities
{
    class Projectile : public Entity
    {
    public:
        Projectile(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Projectile();
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Shoot(sf::Vector2f pos, sf::Vector2f vel);
        virtual void OnCollision(Entities::Entity *ent) = 0;
        const bool getCollided() const;
        void Save(std::ofstream& savefile);
        void Load(std::ifstream& savefile);
        virtual void Move() = 0;
        Entities::Characters::Character* getOwner();
    protected:
        Entities::Characters::Character *owner;
        bool collided;
    };
}