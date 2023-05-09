#pragma once

#include "../Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define LIVES 5
#define MAXV 10
#define ATRITO 0.45
#define JUMPHEIGHT -15
#define PSPEED 1
#define MULT 60
namespace Entities
{
	namespace Characters
	{
		class Player: public Characters::Character
		{
		private:
			const float maxVelocity;
			bool BoolMoveRight;
			bool boolMoveLeft;
			bool secondJump;
			bool fall;
			static sf::Texture texture;
			static bool textureLoaded;

		public:
			Player(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
			~Player();
			void Move();
			sf::Vector2f getPosition();
			const sf::Vector2f getVelocity() const;
			void setDead();
			void Jump();
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Attack(const bool b);
			void OnCollision(Entities::Entity* ent);
		};
	}
}