#include "../include/Menus/Menu.h"

Menus::Menu::Menu():
    Being(ID::menu),
    currentButtom(0),
    buttomCont(0)
{
}

Menus::Menu::~Menu()
{
}

void Menus::Menu::PushButtom(GraphicElements::Buttom* buttom)
{
    buttons.push_back(buttom);
    buttomCont++;
}