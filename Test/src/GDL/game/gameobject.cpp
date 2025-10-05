#include "../../../include/GDL/game/gameobject.h"

#include "../../../include/GDL/components/transform.h"
#include "../../../include/GDL/components/renderer.h"


namespace gdl {


GameObject::GameObject(entt::registry& reg,  bool add_trans, bool add_rend) : reg(&reg) {
	id = this->reg->create();

	if(add_trans) this->reg->emplace<gdl::components::Transform>(id);

	if(add_rend)  this->reg->emplace<gdl::components::Renderer>(
		id,
		this->reg->get<gdl::components::Transform>(id)
	);
}



}






