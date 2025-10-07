#pragma once

#include "shader.h"
#include "../tools/typedefs.h"
#include <vector>
#include <glm/glm.hpp>

namespace gdl {




struct Vertex{
	glm::vec3 position;
};

class Mesh{
private:
	u32 VAO, VBO, EBO;
public:
	std::vector<Vertex> vertices;
	std::vector<u32> indices;

	Mesh(const std::vector<Vertex>& vert, const std::vector<u32> idx);

	void draw(gdl::Shader& shader);
};


}  // gdl::graphics







