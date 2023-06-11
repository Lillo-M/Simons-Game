#pragma once
#include "State.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/InputManager.h"
#include "../Levels/Level.h"
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
namespace Observers
{
    class TextInputObserver;
}
namespace States
{
    class GameOverState: public State
    {
    public:
        GameOverState(States::StateMachine* pSMachine, Managers::InputManager* pIM);
        ~GameOverState();
        void Update();
        void Draw();
        void inputKey(std::string key);
        void SaveData();
        void swap(std::vector<int> &A, int i, int j, std::vector<std::string> &B);
        void selection_sort (std::vector<int> &A, int n, std::vector<std::string> &B);
    private:
        Observers::TextInputObserver* tIObserver;
        Managers::InputManager* pIM;
        Managers::GraphicManager* pGM;
        std::string name;
        sf::Text gameOver;
        sf::Text writingName;
        sf::Text Score;
        sf::Font font;
    };
}