#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define LIVES 5
#define MAXV 20
namespace Entities
{
	class Player : public Entity
	{
	private:
		sf::Vector2f velocity;
		int lives;
		bool alive;
		const float maxVelocity;
		bool BoolMoveRight;
		bool boolMoveLeft;
		bool secondJump;
		sf::Texture texture;
	public:
		Player(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
		~Player();
		void Move();
		void operator--();
		sf::Vector2f getPosition();
		const sf::Vector2f getVelocity() const;
		void addVelocity(sf::Vector2f vel);
		void Gravity();
		const bool getAlive() const;
		void setDead();
		void Jump();
		void MoveRight(const bool b);
		void MoveLeft(const bool b);
		void Fall();
	};
}