#pragma once

#include "shader.h"
#include "../engine/camera.h"

#include <vector>
#include "../tools/typedefs.h"
#include "../tools/vector3.h"

namespace gdl::graphics {




struct Vertex{
	gdl::tools::Vector3 position;
};

class Mesh{
private:
	u32 VAO, VBO, EBO;
public:
	std::vector<Vertex> vertices;
	std::vector<u32> indices;

	Mesh(const std::vector<Vertex>& vert, const std::vector<u32> idx);

	void draw(gdl::graphics::Shader& shader);
};


}  // gdl::graphics







