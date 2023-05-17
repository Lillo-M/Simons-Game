#pragma once
#include <SFML/Graphics.hpp>

namespace GraphicElements
{
    class Animation
    {
    public:
        Animation();
        ~Animation();
        sf::IntRect uvRect;
        void update(int row, float deltaTime);
        void AnimationReset(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
    };
}