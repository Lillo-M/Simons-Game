#pragma once
#include "Obstacle.h"
#include <iostream>
#include "../../GraphicElements/SimpleSprite.h"
#include "../Characters/Player.h"

namespace Entities
{
	namespace Obstacles
	{
		class Ground : public Obstacle
		{
		private:
			const static float friction;
			const static float forca_empuxo;
		public:
			Ground(const sf::Vector2f pos);
			~Ground();
			void OnCollision(Entities::Entity* ent);
			void Move();
			void Update();
		};
	}
}