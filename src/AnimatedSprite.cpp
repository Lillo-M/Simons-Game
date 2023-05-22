#include "../include/GraphicElements/AnimatedSprite.h"

GraphicElements::AnimatedSprite::AnimatedSprite(const char* path, sf::Vector2f size, sf::Vector2f pos):
    texture(Managers::GraphicManager::getInstance()->loadTexture(path))/*,
    HitBox(size)*/
{
    /*HitBox.setTexture(texture);
	HitBox.setTextureRect(animation.uvRect);*/
}

GraphicElements::AnimatedSprite::~AnimatedSprite()
{
}

GraphicElements::AnimatedSprite::Update(sf::Vector2f position)
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

GraphicElements::AnimatedSprite::AnimationReset(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
}