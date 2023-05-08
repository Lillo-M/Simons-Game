#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Ente
{
public:
    Ente(const sf::Vector2f size = sf::Vector2f(0, 0), std::string id = "BackStageEnte");
    virtual ~Ente();
    void Draw();
    //virtual void Move() = 0;
    static void setWindow(sf::RenderWindow& wds);
    const std::string getID() const; 

private:
    static sf::RenderWindow* window;
    const std::string ID;
protected:
	sf::RectangleShape HitBox;
};