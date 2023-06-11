#pragma once

#include "../Characters/Character.h"
#include "../Entity.h"
namespace Entities::Projectiles
{
    class Projectile : public Entity
    {
    public:
        Projectile(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f Velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Projectile();
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Move() = 0;
        virtual void OnCollision(Entities::Entity *ent) = 0;
        virtual void Shoot(sf::Vector2f pos, sf::Vector2f vel);
        const bool getCollided() const;
        void Save(std::ofstream& savefile);
        void Load(std::ifstream& savefile);
        Entities::Characters::Character* getOwner();
    protected:
        Entities::Characters::Character *owner;
        bool collided;
    };
}