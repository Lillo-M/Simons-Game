#pragma once
#include "Animation.h"
namespace GraphicElements
{
    class AnimatedSprite: public Animation
    {
    public:
        AnimatedSprite(const char* path, sf::Vector2f size, sf::Vector2f pos, sf::Vector2u imageCount, float switchTime);
        ~AnimatedSprite();    
        void Update(sf::Vector2f position);
    private:
        sf::Texture* texture;
    };
}