#pragma once
#include <list>
#include "Entity.h"
namespace Managers
{

	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();
		void getList(std::list<Entities::Entity*>& ents);
		void Manage();
	private:
		std::list<Entities::Entity*>* entities;
		std::list<Entities::Entity*>::iterator entIt;
	};
}