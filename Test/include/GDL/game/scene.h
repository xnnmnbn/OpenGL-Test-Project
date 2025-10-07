#pragma once

#include <entt/entt.hpp>
#include <functional>
#include <vector>

#include "gameobject.h"
#include "camera.h"
#include "../graphics/model.h"

namespace gdl {

class Scene{
public:
	entt::registry registry;
	GameObject* camera;

	GameObject* create_object(Model* model = NULL);



	static void hidden_update(Scene* scene);

	Scene();
};




}
