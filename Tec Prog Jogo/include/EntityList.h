#pragma once
#include "Entity.h"

namespace GameTools
{
	class EntityNode
	{
	private:
		EntityNode* next;
		EntityNode* prev;
		Entities::Entity* data;
	public:
	};
}