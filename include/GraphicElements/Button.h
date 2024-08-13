#pragma once
#include "Being.h"
#include <string>

namespace GraphicElements
{
    class Button : public Being
    {
    public:
        Button(sf::Vector2f pos, unsigned int size, const std::string text);
        ~Button();
        void Draw();
        void Update();
        void Selected();
        void UnSelected();
        void changeText(std::string newtext);
    private:
        sf::Vector2f Position;
        sf::Text text;
        sf::Font f;
    };
}
