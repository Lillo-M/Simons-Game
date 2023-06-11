#include "../include/Observers/TextInputObserver.h"

Observers::TextInputObserver::TextInputObserver(States::GameOverState* pGameOver):
    pGameOver(pGameOver)
{
    inputSets["A"] = "A";
	inputSets["B"] = "B";
	inputSets["C"] = "C";
	inputSets["D"] = "D";
	inputSets["E"] = "E";
	inputSets["F"] = "F";
	inputSets["G"] = "G";
	inputSets["H"] = "H";
	inputSets["I"] = "I";
	inputSets["J"] = "J";
	inputSets["K"] = "K";
	inputSets["L"] = "L";
	inputSets["M"] = "M";
	inputSets["N"] = "N";
	inputSets["O"] = "O";
	inputSets["P"] = "P";
	inputSets["Q"] = "Q";
	inputSets["R"] = "R";
	inputSets["S"] = "S";
	inputSets["T"] = "T";
	inputSets["U"] = "U";
	inputSets["V"] = "V";
	inputSets["W"] = "W";
	inputSets["X"] = "X";
	inputSets["Y"] = "Y";
	inputSets["Z"] = "Z";
	inputSets["Enter"] = "Enter";
	inputSets["BackSpace"] = "BackSpace";
	inputSets["Space"] = "Space";
}

Observers::TextInputObserver::~TextInputObserver()
{

}

void Observers::TextInputObserver::notifyKeyPressed(std::string key)
{
    mapIt = inputSets.begin();
	for (mapIt; mapIt != inputSets.end(); mapIt++)
	{
        if(mapIt->second == key)
        {
            pGameOver->inputKey(key);
            break;
        }
    }
}

void Observers::TextInputObserver::notifyKeyReleased(std::string key)
{

}