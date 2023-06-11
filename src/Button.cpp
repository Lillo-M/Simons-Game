#include "../include/GraphicElements/Button.h"

GraphicElements::Button::Button(sf::Vector2f pos, unsigned int size, const std::string text):
    Being(ID::button)
{
    if(!f.loadFromFile("Assets/arial.ttf"))
    {
        std::cout << "ERROR: Failed to load font\n";
        exit(1);
    }
    this->text.setFont(f);
    this->text.setCharacterSize(size);
    this->text.setStyle(sf::Text::Bold);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    Position = pos;
}

GraphicElements::Button::~Button()
{
}

void GraphicElements::Button::Update()
{
    text.setPosition(Position);
}

void GraphicElements::Button::Draw()
{
    pGM->Draw(text);
}

void GraphicElements::Button::Selected()
{
    text.setFillColor(sf::Color::Red);
}

void GraphicElements::Button::UnSelected()
{
    text.setFillColor(sf::Color::White);
}

void GraphicElements::Button::changeText(std::string newtext)
{
    text.setString(newtext);
}