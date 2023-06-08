#pragma once

#include "../States/State.h"
#include "../Menus/Menu.h"
#include "../Levels/Level.h"
#include "../Observers/MenuObserver.h"


namespace Menus
{
    class NewGameMenu: public Menu, public States::State
    {
    public:
        NewGameMenu(States::StateMachine* pSM, Managers::InputManager* pIM);
        ~NewGameMenu();
        void MoveUp();
        void MoveDown();
        void Select();
        void Draw();
        void Update();
        void PushLevel(Levels::Level* level);
        void LoadLevel1();
        void LoadLevel2();
    private:
        std::list<Levels::Level*> levels;
        Observers::MenuObserver* pMObserver;
        Managers::InputManager* pIM;
    };
}