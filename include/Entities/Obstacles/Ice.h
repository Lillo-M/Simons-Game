#include "Obstacle.h"
#include "../Characters/Character.h"
#include "../../GraphicElements/SimpleSprite.h"

namespace Entities
{
	namespace Obstacles
	{

    class Ice: public Obstacle 
    {
    public:
        Ice(const sf::Vector2f pos);
        ~Ice();
        void Move();
        void Update();
        void OnCollision(Entities::Entity* ent);
    };
    }
}