#pragma once

#include "mesh.h"

namespace gdl::graphics {

class Model{
private:
	std::vector<gdl::graphics::Mesh> meshes;

public:

	Model(const std::vector<gdl::graphics::Mesh>& meshes);
	Model(const gdl::graphics::Mesh& mesh);

	std::vector<gdl::graphics::Mesh>& get_meshes();
};






}
