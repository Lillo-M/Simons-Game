#pragma once
#include <map>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <list>
#include "Observers/Observer.h"

namespace Managers
{

	class InputManager
	{
	public:
		~InputManager();
		void pressedInput(sf::Event::KeyEvent key);
		void releasedInput(sf::Event::KeyEvent key);
        void addObserver(Observers::Observer* observer);
		void removeObserver(Observers::Observer* observer);
		static InputManager* getInstance();
	private:
		InputManager();
        static InputManager* Instance;
		std::list<Observers::Observer*> subObservers;
        std::list<Observers::Observer*>::iterator listIt;
    	std::map<sf::Keyboard::Key, std::string> keyMap;
		std::map<sf::Keyboard::Key, std::string>::const_iterator mapIt;
	};
}
