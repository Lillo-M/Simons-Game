#pragma once

#include <SFML/Graphics.hpp>
#include "../Ente.h"
#include <iostream>
#include <math.h> //Fazer uma Fun��o ABS

namespace Entities
{
	class Entity : public Ente
	{
	public:
		Entity(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isS = false, std::string id = "BackStageEnte");
		virtual ~Entity();
		virtual void Move() = 0;
		void Gravity();
		const bool getGrounded() const;
		void setGrounded(bool b);
		sf::Vector2f getPosition() const;
		sf::Vector2f getSize() const;
		bool getisStatic();
		virtual void OnCollision(Entity* ent);
		void normalCollision(Entity* ent);
		static void updateDeltaTime();
		static unsigned int getContEntities();
		static float getDt();
	private:
		static unsigned int Cont;
	protected:
		static float dt;
		const bool isStatic;
		sf::Vector2f velocity;
		static sf::Clock clock;
		static const float gravity;
		sf::Vector2f Position;
		bool grounded;
	};
}