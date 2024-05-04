#include "../include/GraphicElements/SimpleSprite.h"

GraphicElements::SimpleSprite::SimpleSprite():
    texture(NULL),
    Animation()
{
}

GraphicElements::SimpleSprite::~SimpleSprite()
{
    //std::cout << "SimpleSprite Destructor" << std::endl;
}

void GraphicElements::SimpleSprite::Update(sf::Vector2f Position)
{
    HitBox.setPosition(Position);
}

void GraphicElements::SimpleSprite::Reset(const char* path, sf::Vector2f position, sf::Vector2f size)
{
    texture = pGM->loadTexture(path);
    HitBox.setTexture(texture);
    HitBox.setSize(size);
    HitBox.setOrigin(size.x/2, size.y/2);
    HitBox.setPosition(position);
}

void GraphicElements::SimpleSprite::faceRight(bool b)
{
    if(b)
        HitBox.setScale(1.f,1.f);
    else
        HitBox.setScale(-1.f,1.f);
}
