#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../../GraphicElements/ComplexAnimation.h"
#include "../Projectile.h"
#define LIVES 5
#define MAXV 10
#define ATRITO 0.45
#define JUMPHEIGHT -15
#define PSPEED 1
namespace Entities
{
	namespace Characters
	{
		class Player: public Characters::Character
		{
		private:
			std::vector<Projectile*> shots;
			int shotcount;
			const float maxVelocity;
			bool BoolMoveRight;
			bool BoolMoveLeft;
			bool secondJump;
			bool fall;
			bool attackcooled;
			bool faceRight;
			bool isJumping;
			//bool isAttacking;
			static sf::Texture* texture;
			//GraphicElements::Animation animation;
			GraphicElements::ComplexAnimation animation;
			float attackcd;	
		public:
			Player(const sf::Vector2f pos = sf::Vector2f(0, 0));
			~Player();
			void Move();
			void Update();
			void Draw();
			void Save(std::ofstream& savefile);
			sf::Vector2f getPosition();
			const sf::Vector2f getVelocity() const;
			void setFacing(int side);
			void Jump();
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Attack(const bool b);
			void OnCollision(Entities::Entity* ent);
			std::vector<Projectile*>* getShots();
		};
	}
}
