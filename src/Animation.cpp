#include "../include/GraphicElements/Animation.h"

GraphicElements::Animation::Animation():
    currentImage(sf::Vector2u(0,0))
{
}

GraphicElements::Animation::~Animation()
{
}

void GraphicElements::Animation::AnimationReset(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    currentImage.x = 0;


    uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
    uvRect.height = texture->getSize().y / static_cast<float>(imageCount.y);
}

void GraphicElements::Animation::update(sf::Vector2f position)
{
    totalTime += Managers::GraphicManager::getDeltaTime();
    
    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
}