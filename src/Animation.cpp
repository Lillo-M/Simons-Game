#include "../include/GraphicElements/Animation.h"

GraphicElements::Animation::Animation()
{
}

GraphicElements::Animation::~Animation()
{
}

void GraphicElements::Animation::Draw()
{
    sf::RectangleShape shape(sf::Vector2f(5.f,5.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(HitBox.getPosition());
    pGM->Draw(HitBox);
    pGM->Draw(shape);
}

Managers::GraphicManager* GraphicElements::Animation::pGM(Managers::GraphicManager::getInstance());

