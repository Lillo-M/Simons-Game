#include "Obstacle.h"
#include "../Characters/Character.h"
#include "../../GraphicElements/SimpleSprite.h"
#include "../Characters/Player.h"

namespace Entities
{
	namespace Obstacles
	{

    class Ice: public Obstacle 
    {
    private:
        const static float friction;
        const static float forca_empuxo;
    public:
        Ice(const sf::Vector2f pos);
        ~Ice();
        void Move();
        void Update();
        void OnCollision(Entities::Entity* ent);
    };
    }
}