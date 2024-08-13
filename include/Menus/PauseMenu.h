#pragma once

#include "Menu.h"
#include "Observers/MenuObserver.h"
#include "Levels/Level.h"

namespace Menus
{
    class PauseMenu: public Menu, public States::State
    {
    public:
        PauseMenu(States::StateMachine* pSM, Managers::InputManager* pIM);
        ~PauseMenu();
        void Select();
        void Draw();
        void Update();
        void MoveUp();
        void MoveDown();
    private:
        Managers::InputManager* pIM;
        sf::Font font;
        sf::Text text;
        //sf::Image background;
    };
}
