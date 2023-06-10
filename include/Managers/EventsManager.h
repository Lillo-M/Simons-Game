#pragma once

#include "GraphicManager.h"
#include <SFML/Window.hpp>
#include "InputManager.h"

namespace Managers
{
	class EventsManager
	{
	public:
		~EventsManager();
		void Manage();
		void setpInputManager(Managers::InputManager* pIM);
		static EventsManager* getInstance();
	private:
		EventsManager();
		static EventsManager* Instance;
		Managers::GraphicManager* pGM;
		Managers::InputManager* pIM;
	};
}