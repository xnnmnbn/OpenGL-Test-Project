#pragma once

#include "transform.h"
#include "../graphics/shader.h"
#include "../engine/camera.h"

namespace gdl::components {

class Renderer{
private:
	gdl::components::Transform* t;
	gdl::graphics::Model* m;

public:
	Renderer(gdl::components::Transform& t);

	void draw(gdl::graphics::Shader& shader, gdl::engine::Camera& camera);
};

}





