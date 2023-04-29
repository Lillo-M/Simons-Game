#pragma once
#include "Entity.h"
#include <iostream>
namespace Entities
{
	class Ground: public Entities::Entity
	{
	private:


	public:
		Ground(const sf::Vector2f pos, const sf::Vector2f size);
		~Ground();
		void Move();

	};
}