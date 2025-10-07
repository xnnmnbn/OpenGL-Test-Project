#pragma once

#include "transform.h"
#include "../graphics/shader.h"
#include "../game/camera.h"

namespace gdl::components {

class Renderer{
private:
	gdl::components::Transform* t;
	gdl::Model* m;

public:
	Renderer(gdl::components::Transform& t);

	void draw(gdl::Shader& shader, gdl::Camera& camera);
};

}





