#pragma once
#include <string>
#include <map>
namespace Observers
{
    class Observer
    {
    public:
        Observer();
        virtual ~Observer();
        virtual void notifyKeyPressed(std::string key) = 0;
        virtual void notifyKeyReleased(std::string key) = 0;
    protected:
    	std::map<std::string, std::string> inputSets;
        std::map<std::string, std::string>::iterator mapIt;
    };
}