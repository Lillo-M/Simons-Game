#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
	virtual ~Entity();
	void Draw();
	virtual void Move() = 0;
	static void setWindow(sf::RenderWindow& wds);
private:
	sf::RectangleShape HitBox;
	static sf::RenderWindow* window;
	static unsigned int Cont;
protected:
	sf::Vector2f Position;
};