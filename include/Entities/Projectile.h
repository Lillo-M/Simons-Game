#pragma once

#include "Characters/Character.h"
#include "Entity.h"

class Projectile: public Entities::Entity
{
private:
    Entities::Characters::Character* owner;
    //static sf::Texture texture;
    //static bool textureLoaded;
    bool collided;
public:
    Projectile(sf::Vector2f pos = sf::Vector2f(0,0), sf::Vector2f velocity = sf::Vector2f(0,0), Entities::Characters::Character* owner = NULL);
    ~Projectile();
    void Move();
    void Shoot(sf::Vector2f pos, sf::Vector2f vel);
    void OnCollision(Entities::Entity* ent);
    const bool getCollided() const;
};
