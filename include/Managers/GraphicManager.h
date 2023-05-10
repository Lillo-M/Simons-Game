#include <SFML/Graphics.hpp>
#include <iostream>
//#include "../Being.h"
#define WIDTH 1280
#define HEIGHT 720
namespace Managers
{
    class GraphicManager
    {
    private:
        GraphicManager();
        static GraphicManager* Instance;
        sf::RenderWindow window;
    public:
        ~GraphicManager();
        static GraphicManager* getInstance();
        void Draw(sf::RectangleShape &hitbox);
        void Draw(sf::Text &text);
        sf::RenderWindow* getWindow();
        void Close();
        void Display();
        void Clear();
        const bool isWindowOpen() const;
    };
}