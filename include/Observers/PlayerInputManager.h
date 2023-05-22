#pragma once
#include "Observer.h"
#include "../Entities/Characters/Player.h"
#include "../States/StateMachine.h"

namespace Observers
{
    class PlayerInputManager : public Observers::Observer
    {
    public:
		PlayerInputManager(Entities::Characters::Player* pP = NULL, Entities::Characters::Player* pP2 = NULL);
		~PlayerInputManager();
		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);
		bool jumpKeyReleased;
		bool jumpKeyReleased2;
		bool attackKeyReleased;	
		bool attackKeyReleased2;
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