#include "../include/GraphicElements/Animation.h"

GraphicElements::Animation::Animation()
{
}

GraphicElements::Animation::~Animation()
{
}

void GraphicElements::Animation::Draw()
{
    sf::RectangleShape shape(sf::Vector2f(5.f,5.f));// teste
    shape.setFillColor(sf::Color::Green);// teste
    shape.setPosition(HitBox.getPosition());// teste
    pGM->Draw(HitBox);
    pGM->Draw(shape);// teste
}

Managers::GraphicManager* GraphicElements::Animation::pGM(Managers::GraphicManager::getInstance());

