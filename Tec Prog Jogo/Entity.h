#pragma once

#include <SFML/Graphics.hpp>
#define WIDTH 1280
#define HEIGHT 720

class Entity
{
public:
	Entity(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Vector2f size = sf::Vector2f(0, 0));
	virtual ~Entity();
	void Draw();
	virtual void Move() = 0;
	static void setWindow(sf::RenderWindow& wds);
	virtual void Gravity() = 0;
	const bool getGrounded() const;
	void setGrounded(bool b);
private:
	sf::RectangleShape HitBox;
	static sf::RenderWindow* window;
	static unsigned int Cont;
protected:
	static const float gravity;
	sf::Vector2f Position;
	bool grounded;
};