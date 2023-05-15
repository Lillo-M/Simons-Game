#pragma once

#include "../Entities/Characters/Player.h"
#include <map>
#include <iostream>


namespace Managers
{

	class PlayerInputManager
	{
	public:
		PlayerInputManager(Entities::Characters::Player* pP, Entities::Characters::Player* pP2);
		~PlayerInputManager();
		void pressedInput(std::string s);
		void releasedInput(std::string s);
		bool jumpKeyReleased;
		bool jumpKeyReleased2;
		void setpPlayer(Entities::Characters::Player* pP);
		void setpPlayer2(Entities::Characters::Player* pP);
	private:
		Entities::Characters::Player* pPlayer;
		Entities::Characters::Player* pPlayer2;
		std::map<std::string, std::string> inputSetsPlayer;
		std::map<std::string, std::string> inputSetsPlayer2;
		std::map<std::string, std::string>::const_iterator mapIt;
		std::map<std::string, std::string>::const_iterator mapIt2;
	};
}