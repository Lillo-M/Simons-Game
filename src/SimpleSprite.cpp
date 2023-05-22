#include "../include/GraphicElements/SimpleSprite.h"

GraphicElements::SimpleSprite::SimpleSprite(const char* path, sf::Vector2u imageCount, float switchTime)
    currentImage(sf::Vector2u(0,0)),
    texture()
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    currentImage.x = 0;


    uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
    uvRect.height = texture->getSize().y / static_cast<float>(imageCount.y);
}

GraphicElements::SimpleSprite::~Animation()
{
}

void GraphicElements::SimpleSprite::AnimationReset(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    currentImage.x = 0;


    uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
    uvRect.height = texture->getSize().y / static_cast<float>(imageCount.y);
}

void GraphicElements::SimpleSprite::update()
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