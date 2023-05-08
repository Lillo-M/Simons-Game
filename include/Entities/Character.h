#pragma once
#include "Entity.h"

class Character: public Entities::Entity
{
public:
    Character(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isG = false, std::string id = "Character");
	virtual ~Character();
    void operator--();
    const bool getAlive() const;
protected:
	int lives;
    bool alive;
};