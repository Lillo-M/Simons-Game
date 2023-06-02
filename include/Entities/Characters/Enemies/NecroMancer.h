#pragma once

#include "Enemy.h"

namespace Entities
{
    namespace Characters
    {
        namespace Enemies
        {
            class NecroMancer : public Enemy
            {
            public:
                NecroMancer();
                ~NecroMancer();
                void Move();
                void Attack(const bool b);
                void Update();
                void Draw();
            private:

            };
        }
    }
}