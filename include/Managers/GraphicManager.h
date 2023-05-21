#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 768
namespace Managers
{
    class GraphicManager
    {
    private:
        GraphicManager();
        static GraphicManager* Instance;
        sf::RenderWindow window;
        sf::View view;
        static sf::Clock clock;
        static float dt;
        sf::ContextSettings settings;
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
        void CenterView(sf::Vector2f pos);
        void updateDeltaTime();
        float getDeltaTime();
    };
}