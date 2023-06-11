#pragma once
#include "Menu.h"
#include "../Observers/MenuObserver.h"
#include "../States/State.h"
#include "../Levels/Level.h"

namespace Menus
{
    class MainMenu: public Menu, public States::State
    {
    public:
        MainMenu(States::StateMachine* pSM, Managers::InputManager* pIM);
        ~MainMenu();
        void Select();
        void Draw();
        void Update();
        void MoveUp();
        void MoveDown();
    private:
        Managers::InputManager* pIM;
        bool twoPlayers;
        //sf::Image background;
    };
}