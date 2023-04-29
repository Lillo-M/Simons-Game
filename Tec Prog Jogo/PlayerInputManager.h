#pragma once

#include "Player.h"
#include <map>
#include <iostream>


namespace Managers
{

	class PlayerInputManager
	{
	public:
		PlayerInputManager(Entities::Player* pP);
		~PlayerInputManager();
		void pressedInput(std::string s);
		void releasedInput(std::string s);
		bool jumpKeyReleased;
		void setpPlayer(Entities::Player* pP);
	private:
		Entities::Player* pPlayer;
		std::map<std::string, std::string> inputSets;
		std::map<std::string, std::string>::const_iterator mapIt;
	};
}