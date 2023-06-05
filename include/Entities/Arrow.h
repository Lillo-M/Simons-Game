#pragma once

#include "Projectile.h"
#include "../GraphicElements/SimpleSprite.h"

namespace Entities{
    class Arrow : public Entities::Projectile {
    private:
        GraphicElements::SimpleSprite animation;
    public:
        Arrow (sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f velocity = sf::Vector2f(0, 0), Entities::Characters::Character *owner = NULL);
        ~Arrow ();
        void Move();
        void Update();
        void Draw();
        void OnCollision(Entities::Entity *ent);
    };
}