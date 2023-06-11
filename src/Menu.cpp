#include "../include/Menus/Menu.h"
#include "../include/Observers/MenuObserver.h"

Menus::Menu::Menu():
    Being(ID::menu),
    currentButtom(0),
    buttomCont(0),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this)))
{
}

Menus::Menu::~Menu()
{
    std::cout << "Abstract Menu Destructor" << std::endl;
    if(pMObserver)
        delete pMObserver;
}

void Menus::Menu::PushButtom(GraphicElements::Button* button)
{
    buttons.push_back(button);
    buttomCont++;
}

const Observers::Observer* Menus::Menu::getObserver() const {return static_cast<Observers::Observer*>(pMObserver);}