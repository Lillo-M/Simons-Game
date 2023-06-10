#pragma once
#include "Projectile.h"
#include "../../GraphicElements/ComplexAnimation.h"

namespace Entities::Projectiles
{
    class Skull : public Projectile
    {
    public:
        Skull(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Skull();
        void Update();
        void Draw();
        void Move();
        void OnCollision(Entities::Entity *ent);

    private:
        double restorationCoeficient;
        GraphicElements::ComplexAnimation animation;
        float timeCont;
    };
}