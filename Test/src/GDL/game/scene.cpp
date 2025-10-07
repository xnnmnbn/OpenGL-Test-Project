#include "../../../include/GDL/game/scene.h"
#include "../../../include/GDL/game/camera.h"

#include "../../../include/GDL/game/gameobject.h"

#include "../../../include/GDL/components/transform.h"
#include "../../../include/GDL/components/renderer.h"


namespace gdl {

Scene::Scene(){
	camera = new GameObject(this->registry);

	camera->add_component<gdl::Camera>();
}

GameObject* Scene::create_object(Model* model){

	GameObject* obj = new GameObject(this->registry);

	if(!model) return obj;

	return obj
			->add_component<gdl::components::Transform>(model)
			->add_component<gdl::components::Renderer>(
				obj->get_component<gdl::components::Transform>()
			);
}


void Scene::hidden_update(Scene* scene){
	auto view_transform = scene->registry.view<gdl::components::Transform>();

	for (auto& e : view_transform) {
		gdl::components::Transform& t = view_transform.get<gdl::components::Transform>(e);

		gdl::components::Transform::update(t);
	}
}




}
