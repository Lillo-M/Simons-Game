#include "../include/Menus/Menu.h"
#include "../include/Observers/MenuObserver.h"

Menus::Menu::Menu():
    Being(ID::menu),
    currentButton(0),
    buttonCont(0),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this)))
{
}

Menus::Menu::~Menu()
{
    std::cout << "Abstract Menu Destructor" << std::endl;
    if(pMObserver)
        delete pMObserver;
}

void Menus::Menu::PushButton(GraphicElements::Button* button)
{
    buttons.push_back(button);
    buttonCont++;
}

const Observers::Observer* Menus::Menu::getObserver() const {return static_cast<Observers::Observer*>(pMObserver);}