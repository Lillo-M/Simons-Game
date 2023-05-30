#include "../include/GraphicElements/SimpleSprite.h"

GraphicElements::SimpleSprite::SimpleSprite():
    texture(NULL)
{
    pGM = Managers::GraphicManager::getInstance();
}

GraphicElements::SimpleSprite::~SimpleSprite()
{
}

void GraphicElements::SimpleSprite::Update(sf::Vector2f Position)
{
    HitBox.setPosition(Position);
}

void GraphicElements::SimpleSprite::Reset(const char* path, sf::Vector2f position, sf::Vector2f size, float scale)
{
    HitBox.setSize(size);
    HitBox.setOrigin(size.x/2, size.y/2);
    HitBox.setScale(scale, scale);
    HitBox.setPosition(position);
}
