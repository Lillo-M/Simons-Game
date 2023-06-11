#pragma once

#include "Projectile.h"
#include "../../GraphicElements/ComplexAnimation.h"

namespace Entities::Projectiles{
    class PlasmaBall : public Projectile {
    private:
        GraphicElements::ComplexAnimation animation;
    public:
        PlasmaBall (sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~PlasmaBall ();
        void Shoot(sf::Vector2f pos, sf::Vector2f vel);
        void Move();
        void Update();
        void Draw();
        void OnCollision(Entities::Entity *ent);
    };
}