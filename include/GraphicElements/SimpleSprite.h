#pragma once
#include "Animation.h"
namespace GraphicElements
{
    class SimpleSprite: public Animation
    {
    public:
        SimpleSprite();
        ~SimpleSprite();    
        void Update(sf::Vector2f position);
        void AnimationReset(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
    };
}