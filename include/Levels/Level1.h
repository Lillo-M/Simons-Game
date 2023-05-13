#include "Level.h"
#include <fstream>
namespace Levels{
    class Level1 : public Levels::Level
    {
    private:
        
    public:
        void CreateMap();
        Level1(Managers::EventsManager* pEM);
        ~Level1();
    };
}