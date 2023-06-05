#pragma once
#include "Menu.h"
#include "../States/State.h"
#include "../Observers/MenuObserver.h"
#include <vector>
#include <fstream>

namespace Menus
{
    class LeaderBoard : public Menu, public States::State
    {
    public:
        LeaderBoard(States::StateMachine* pSM, Managers::InputManager* pIM);
        ~LeaderBoard();
        void Select();
        void Draw();
        void Update();
        void MoveUp();
        void MoveDown();
        void Reset();
    private:
        int textCount;
        Observers::MenuObserver* pMObserver;
        Managers::InputManager* pIM;
        std::vector<sf::Text*> Leaders;
        std::vector<std::string> names;
        std::vector<int> points;
        sf::Font font;
    };
}