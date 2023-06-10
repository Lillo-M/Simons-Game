#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../../GraphicElements/ComplexAnimation.h"
#include "../Projectiles/PlayerProjectile.h"

namespace Entities
{
	namespace Characters
	{
		class Player: public Character
		{
		private:
			std::vector<Entities::Projectiles::PlayerProjectile*> shots;
			int shootCount;
			float maxVelocity;
			float friction;
			bool BoolMoveRight;
			bool BoolMoveLeft;
			bool secondJump;
			bool fall;
			bool attackcooled;
			bool faceRight;
			bool isJumping;
			bool onIce;
			GraphicElements::ComplexAnimation animation;
			float attackcd;	/*Cooldown do ataque*/
			int Points;
		public:
			Player(const sf::Vector2f pos = sf::Vector2f(0, 0));
			~Player();
			void Move();
			void Update();
			void Draw();
			void Save(std::ofstream& savefile);
			void Load(std::ifstream& savefile);
			sf::Vector2f getPosition();
			const sf::Vector2f getVelocity() const;
			void setFacing(int side);
			void Jump();
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Attack(const bool b);
			void OnCollision(Entities::Entity* ent);
			void Score(ID id);
			void setPoints(int Points);
			void setFriction(float friction);
			const int getPoints() const;
			std::vector<Entities::Projectiles::PlayerProjectile*>* getShots();
		};
	}
}
