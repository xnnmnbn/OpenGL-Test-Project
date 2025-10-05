#include "../../../include/GDL/game/scene.h"
#include "../../../include/GDL/game/camera.h"

#include "../../../include/GDL/game/gameobject.h"
#include "../../../include/GDL/components/transform.h"


namespace gdl {

Scene::Scene(){
	GameObject camera(this->registry, true);

	camera.add_component<gdl::Camera>();
}


void Scene::hidden_update(Scene* scene){
	auto view_transform = scene->registry.view<gdl::components::Transform>();

	for (auto& e : view_transform) {
		gdl::components::Transform& t = view_transform.get<gdl::components::Transform>(e);

		gdl::components::Transform::update(t);
	}
}




}
