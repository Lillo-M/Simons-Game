#include "List.h"
#include "../Entities/Entity.h"

namespace Math
{
	class EntityList: public List
	{
	private:
		List<Entities::Entity> entity_list;
	public:
		EntityList();
		~EntityList();
		void MoveEntities();
		void UpdateEntities();
		void DrawEntities();
		void PushEntity(Entities::Entity* ent);
		void Clear();
		void DeleteEntities();
		/* **Terminar esta Classe . . .*/ 
	};
}
