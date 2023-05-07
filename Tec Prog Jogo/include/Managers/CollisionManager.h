#pragma once
#include "../Entities/Entity.h"
#include "../Math/List.h"
namespace Managers
{

	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();
		void getList(Math::List<Entities::Entity>& ents);
		void Manage();
	private:
		Math::List<Entities::Entity>* entities;
	};
}