#pragma once

#include "../Entities/Characters/Player.h"
#include <map>
#include <iostream>


namespace Managers
{

	class PlayerInputManager
	{
	public:
		PlayerInputManager(Entities::Characters::Player* pP);
		~PlayerInputManager();
		void pressedInput(std::string s);
		void releasedInput(std::string s);
		bool jumpKeyReleased;
		void setpPlayer(Entities::Characters::Player* pP);
	private:
		Entities::Characters::Player* pPlayer;
		std::map<std::string, std::string> inputSets;
		std::map<std::string, std::string>::const_iterator mapIt;
	};
}