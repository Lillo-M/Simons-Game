#pragma once

#include "Player.h"
#include <map>
#include <iostream>
class PlayerInputManager
{
public:
	PlayerInputManager( Entities::Player* pP );
	~PlayerInputManager();
	void pressedInput(std::string s);
	void releasedInput(std::string s);
	bool jumpKeyReleased;
private:
	Entities::Player* pPlayer;
	std::map<std::string, std::string> inputSets;
	std::map<std::string, std::string>::const_iterator mapIt;
};