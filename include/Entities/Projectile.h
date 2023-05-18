#pragma once
#include "Characters/Character.h"

class Projectile: public Entities::Entity
{
private:
    Entities::Characters::Character* owner;
    static sf::Texture texture;
    static bool textureLoaded;
public:
    Projectile(sf::Vector2f pos, sf::Vector2f velocity, Entities::Characters::Character* owner);
    ~Projectile();
    void Move();
};