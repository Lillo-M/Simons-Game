#pragma once

#include <SFML/Graphics.hpp>
namespace Entities
{
	class Entity
	{
	public:
		Entity(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0), const bool isG = false);
		virtual ~Entity();
		void Draw();
		virtual void Move() = 0;
		static void setWindow(sf::RenderWindow& wds);
		void Gravity();
		const bool getGrounded() const;
		void setGrounded(bool b);
		sf::Vector2f getPosition() const;
		sf::Vector2f getSize() const;
		bool getIsGround();
		virtual void OnCollision(Entity* ent);
		static void updateDeltaTime();
		static unsigned int getContEntities();
	private:
		static sf::RenderWindow* window;
		static unsigned int Cont;
	protected:
		static float dt;
		const bool isGround;
		sf::Vector2f velocity;
		static sf::Clock clock;
		static const float gravity;
		sf::Vector2f Position;
		bool grounded;
		sf::RectangleShape HitBox;
		sf::Texture texture;
	};
}