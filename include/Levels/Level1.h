#include "Level.h"
#include <fstream>
namespace Levels{
    class Level1 : public Levels::Level
    {
    public:
        void CreateMap();
        Level1(Managers::EventsManager* pEM, States::StateMachine* pSM = NULL);
        ~Level1();
    private:
        //sf::Image background;
    };
}