#pragma once
#include "List.h"
#include "../Entities/Characters/Character.h"
#include "../Entities/Projectile.h"
#include <iostream>

namespace Math
{
	class EntityList
	{
	private:
		EntityTList entity_list;
		EntityTList::Iterator listIt;
	public:
		EntityList();
		~EntityList();
		void UpdateEntities();
		void DrawEntities();
		void PushEntity(Entities::Entity* ent);
		void Clear();
		void DeleteEntities();
		Math::List<Entities::Entity>& getTList();
		/* **Terminar esta Classe . . .*/
	};
}
