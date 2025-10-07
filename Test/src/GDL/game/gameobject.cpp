#include "../../../include/GDL/game/gameobject.h"

#include "../../../include/GDL/components/transform.h"
#include "../../../include/GDL/components/renderer.h"


namespace gdl {


GameObject::GameObject(entt::registry& reg) : reg(&reg) {
	id = this->reg->create();
}



}






