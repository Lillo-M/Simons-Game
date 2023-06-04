#include "Level.h"
#include <fstream>
namespace Levels{
    class Level1 : public Levels::Level
    {
    public:
        void CreateMap();
        Level1(States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        ~Level1();
        void Draw();
    private:
        sf::Sprite background;
        sf::Texture* texture;
    };
}