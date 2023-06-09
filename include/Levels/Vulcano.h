#include "Level.h"
#include <fstream>
namespace Levels{
    class Vulcano : public Levels::Level
    {
    public:
        Vulcano(States::StateMachine* pSM = NULL, Managers::InputManager* pIM = NULL);
        ~Vulcano();
        void CreateMap();
        void Draw();
        void Update();
        void CreateEntity(char id, sf::Vector2f pos);
        void CreateNecroMancer(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateLava(const sf::Vector2f pos = sf::Vector2f(0, 0));
    private:
        int pool;
        bool isLavaPool;
        sf::Sprite background;
        sf::Texture* texture;
    };
}