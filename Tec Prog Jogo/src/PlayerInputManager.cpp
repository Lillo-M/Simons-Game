#include "../include/PlayerInputManager.h"


namespace Managers
{
	PlayerInputManager::PlayerInputManager(Entities::Player* pP) :
		pPlayer(pP),
		jumpKeyReleased(true)
	{
		inputSets["Jump"] = "W";
		inputSets["Right"] = "D";
		inputSets["Left"] = "A";
		inputSets["Down"] = "S";
		inputSets["Attack"] = "F";
		mapIt = inputSets.begin();
	}

	PlayerInputManager::~PlayerInputManager()
	{
		pPlayer = NULL;
	}

	void PlayerInputManager::pressedInput(std::string s)
	{
		for (mapIt; mapIt != inputSets.end(); mapIt++)
		{
			if (mapIt->second == s)
			{
				if (mapIt->first == "Jump")
				{
					if (jumpKeyReleased)
					{
						std::cout << std::endl << "jump!" << std::endl;
						pPlayer->Jump();
						jumpKeyReleased = false;
					}
				}
				if (mapIt->first == "Right")
				{
					pPlayer->MoveRight(true);
				}
				if (mapIt->first == "Left")
				{
					pPlayer->MoveLeft(true);
				}
				if (mapIt->first == "Down")
				{
					pPlayer->Fall();
				}
				if (mapIt->first == "Attack")
				{
					std::cout << std::endl << "attack!" << std::endl;
					pPlayer->Attack(true);
				}
			}
		}
		mapIt = inputSets.begin();
	}

	void PlayerInputManager::releasedInput(std::string s)
	{
		for (mapIt; mapIt != inputSets.end(); mapIt++)
		{
			if (mapIt->second == s)
			{
				if (mapIt->first == "Jump")
				{
					std::cout << std::endl << "jump Released!" << std::endl;
					jumpKeyReleased = true;
				}
				if (mapIt->first == "Right")
				{
					pPlayer->MoveRight(false);
				}
				if (mapIt->first == "Left")
				{
					pPlayer->MoveLeft(false);
				}
				if (mapIt->first == "Attack")
				{
					pPlayer->Attack(false);
					std::cout << std::endl << "attack Released!" << std::endl;
				}
			}
		}
		mapIt = inputSets.begin();
	}
	void PlayerInputManager::setpPlayer(Entities::Player* pP)
	{
		pPlayer = pP;
	}
}