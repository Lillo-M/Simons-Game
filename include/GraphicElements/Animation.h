#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
public:
    Animation(sf::Texture* texture = nullptr, sf::Vector2u imageCount = sf::Vector2u(0,0), float switchTime = 0.f);
    ~Animation();
    sf::IntRect uvRect;
    void update(int row, float deltaTime);
    void AnimationReset(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;
};