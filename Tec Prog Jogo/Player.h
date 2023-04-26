#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
private:
	sf::Vector2f velocity;
	int lives;
	bool alive;
public:
	Player(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
	~Player();
	void Move();
	const bool getAlive() const;
	void setDead();
};