#pragma once
#include <list>
#include <string>

namespace Observers
{
    class Observer
    {
    private:
        
    public:
        Observer();
        virtual ~Observer();
        virtual void notifyKeyPressed(std::string) = 0;
        virtual void notifyKeyReleased(std::string) = 0;
    };
}