#include "../include/Managers/GraphicManager.h"

Managers::GraphicManager::GraphicManager() : 
    window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"), // incializa a janela
    view(window.getView())
{
}

Managers::GraphicManager::~GraphicManager()
{
    if(Instance)
        delete Instance;
    Instance = NULL;
}

Managers::GraphicManager* Managers::GraphicManager::getInstance()
{
    if (!Instance) // se não houver ainda uma instancia de gerenciador grafico
    {
        Instance = new GraphicManager; // ele cria uma
        if (!Instance)
        {
            std::cout << std::endl << "ERROR: Failed to Allocate Memory" << std::endl;
            return NULL;
        }
    }
    return Instance; // e por fim retorna ela ou se já havia ele retorna direto.
}

void Managers::GraphicManager::Draw(sf::RectangleShape &hitbox)
{
    window.draw(hitbox); // literalmente só desenha na tela o hitbox que entrou como parametro
}

void Managers::GraphicManager::Draw(sf::Text &text)
{
    window.draw(text); // desenha texto
}
void Managers::GraphicManager::Display()
{
    window.display(); // mostra na tela tudo que foi desenhado até o momento
}

void Managers::GraphicManager::Clear()
{
    window.clear(); // limpa a janela
}

void Managers::GraphicManager::Close()
{
    window.close(); // fecha a janela
}

sf::RenderWindow* Managers::GraphicManager::getWindow() { return &window;} //retorna um ponteiro para a janela (usado no EventManager que depende da janela)

const bool Managers::GraphicManager::isWindowOpen() const { return window.isOpen(); } // retorna se a janela está aberta ou não

void Managers::GraphicManager::CenterView(sf::Vector2f pos)
{
    if(pos.y < 300)
        pos = sf::Vector2f(pos.x, HEIGHT/2 + (pos.y - 300 ) );
    else if(pos.y > 564)
        pos = sf::Vector2f(pos.x, HEIGHT/2 + (pos.y - 564));
    else
        pos = sf::Vector2f(pos.x, HEIGHT/2);
    view.setCenter(pos);
    window.setView(view);
}

Managers::GraphicManager *Managers::GraphicManager::Instance(NULL); // incializa o ponteiro estatico para a instancia de Gerenciador grafico