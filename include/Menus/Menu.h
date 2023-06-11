#pragma once
#include "../Being.h"
#include <vector>
#include "../GraphicElements/Buttom.h"
#include "../Managers/InputManager.h"

namespace Observers
{
    class MenuObserver;
}

namespace Menus
{
    class Menu : public Being
    {
    public:
        Menu();
        virtual ~Menu();
        virtual void MoveUp() = 0;
        virtual void MoveDown() = 0;
        virtual void Select() = 0;
        virtual void Draw() = 0;
        virtual void Update() = 0;
        void PushButtom(GraphicElements::Buttom* buttom);
        const Observers::Observer* getObserver() const;
    protected:
        Observers::MenuObserver* pMObserver;
        std::vector<GraphicElements::Buttom*> buttons;
        int buttomCont;
        int currentButtom;
    };
}