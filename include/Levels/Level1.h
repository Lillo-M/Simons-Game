#include "Level.h"
#include <fstream>
namespace Levels{
    class Level1 : public Levels::Level
    {
    private:
        //sf::Image background;
    public:
        void CreateMap();
        Level1(Managers::EventsManager* pEM, States::StateMachine* pSM = NULL);
        ~Level1();
    };
}