#include "Level.h"
#include <fstream>
namespace Levels{
    class Alaska : public Levels::Level
    {
    public:
        void CreateMap();
        Alaska(States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        ~Alaska();
        void Draw();
        void Update();
        void CreateEntity(char id, sf::Vector2f pos);
        void CreateWarrior(const sf::Vector2f pos = sf::Vector2f(0, 0), bool isRandom = false);
        void CreateIce(const sf::Vector2f pos = sf::Vector2f(0, 0));
    private:
        bool isIcePool;
        int pool;
        sf::Sprite background;
        sf::Texture* texture;
    };
}