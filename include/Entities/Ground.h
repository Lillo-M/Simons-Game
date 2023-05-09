#pragma once
#include "Entity.h"
#include <iostream>
namespace Entities
{
	class Ground: public Entity
	{
	private:
		static sf::Texture texture;
		static bool textureLoaded;
	public:
		Ground(const sf::Vector2f pos, const sf::Vector2f size);
		~Ground();
		void Move();
	};
}