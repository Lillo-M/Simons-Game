#include "Obstacle.h"
#include "../Characters/Character.h"

namespace Entities
{
	namespace Obstacles
	{

    class Lava: public Obstacle 
    {
    public:
        Lava(const sf::Vector2f pos);
        ~Lava();
        void Move();
        void Update();
        void OnCollision(Entities::Entity* ent);
    
    private:

    };
    }
}