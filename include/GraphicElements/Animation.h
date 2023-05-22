#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/GraphicManager.h"
#include "../Being.h"

namespace GraphicElements
{
    class Animation
    {
    public:
        Animation();
        virtual ~Animation();
        virtual void update(sf::Vector2f position);
        void AnimationReset(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
        sf::IntRect uvRect;
    protected:
        //sf::IntRect uvRect;
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
        float totalTime;
        float switchTime;
        //sf::RectangleShape HitBox;
    };
}