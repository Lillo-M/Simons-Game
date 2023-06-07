#include "Level.h"
#include <fstream>
namespace Levels{
    class Level2 : public Levels::Level
    {
    public:
        Level2(States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        ~Level2();
        void CreateMap();
        void Draw();
        void Update();
    private:
        sf::Sprite background;
        sf::Texture* texture;
    };
}