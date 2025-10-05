#pragma once

#include <entt/entt.hpp>
#include <functional>
#include <vector>

#include "gameobject.h"
#include "camera.h"

namespace gdl {

class Scene{
public:
	entt::registry registry;



	static void hidden_update(Scene* scene);

	Scene();
};




}
