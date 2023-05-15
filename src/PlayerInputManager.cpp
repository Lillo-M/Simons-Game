#include "../include/Managers/PlayerInputManager.h"

using namespace Managers;

PlayerInputManager::PlayerInputManager(Entities::Characters::Player *pP, Entities::Characters::Player *pP2) : 
	pPlayer(pP),																								  
	pPlayer2(pP2),
	jumpKeyReleased(true),
	jumpKeyReleased2(true)
{
	inputSetsPlayer["Jump"] = "W";
	inputSetsPlayer["Right"] = "D";
	inputSetsPlayer["Left"] = "A";
	inputSetsPlayer["Down"] = "S";
	inputSetsPlayer["Attack"] = "F";
	inputSetsPlayer2["Jump"] = "Up";
	inputSetsPlayer2["Right"] = "Right";
	inputSetsPlayer2["Left"] = "Left";
	inputSetsPlayer2["Down"] = "Down";
	inputSetsPlayer2["Attack"] = "rCtrl";
	mapIt = inputSetsPlayer.begin();
	mapIt2 = inputSetsPlayer2.begin();
}

PlayerInputManager::~PlayerInputManager()
{
	pPlayer = NULL;
	pPlayer2 = NULL;
}

void PlayerInputManager::pressedInput(std::string s)
{
	for (mapIt; mapIt != inputSetsPlayer.end(); mapIt++)
	{
		if (mapIt->second == s)
		{
			if (mapIt->first == "Jump")
			{
				if (jumpKeyReleased)
				{
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
				std::cout << std::endl
						  << "attack!" << std::endl;
				pPlayer->Attack(true);
			}
		}
	}
	mapIt = inputSetsPlayer.begin();
	if (pPlayer2)
		for (mapIt2; mapIt2 != inputSetsPlayer2.end(); mapIt2++)
		{
			if (mapIt2->second == s)
			{
				if (mapIt2->first == "Jump")
				{
					if (jumpKeyReleased2)
					{
						pPlayer2->Jump();
						jumpKeyReleased2 = false;
					}
				}
				if (mapIt2->first == "Right")
				{
					pPlayer2->MoveRight(true);
				}
				if (mapIt2->first == "Left")
				{
					pPlayer2->MoveLeft(true);
				}
				if (mapIt2->first == "Down")
				{
					pPlayer2->Fall();
				}
				if (mapIt2->first == "Attack")
				{
					pPlayer2->Attack(true);
				}
			}
		}
	if(pPlayer2)
		mapIt2 = inputSetsPlayer2.begin();
}

void PlayerInputManager::releasedInput(std::string s)
{
	for (mapIt; mapIt != inputSetsPlayer.end(); mapIt++)
	{
		if (mapIt->second == s)
		{
			if (mapIt->first == "Jump")
			{
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
			}
		}
	}
	mapIt = inputSetsPlayer.begin();
	if (pPlayer2)
		for (mapIt2; mapIt2 != inputSetsPlayer2.end(); mapIt2++)
		{
			if (mapIt2->second == s)
			{
				if (mapIt2->first == "Jump")
				{
					jumpKeyReleased2 = true;
				}
				if (mapIt2->first == "Right")
				{
					pPlayer2->MoveRight(false);
				}
				if (mapIt2->first == "Left")
				{
					pPlayer2->MoveLeft(false);
				}
				if (mapIt2->first == "Attack")
				{
					pPlayer2->Attack(false);
				}
			}
		}
	if(pPlayer2)
		mapIt2 = inputSetsPlayer2.begin();
}

void PlayerInputManager::setpPlayer(Entities::Characters::Player *pP)
{
	pPlayer = pP;
}

void PlayerInputManager::setpPlayer2(Entities::Characters::Player *pP)
{
	pPlayer2 = pP;
}
