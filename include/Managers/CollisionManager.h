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
		void getSList(Math::List<Entities::Entity>& ents);
		void getDList(Math::List<Entities::Entity>& ents);
		void Manage();
	private:
		Math::List<Entities::Entity>* Dentities;
		Math::List<Entities::Entity>* Sentities;
	};
}