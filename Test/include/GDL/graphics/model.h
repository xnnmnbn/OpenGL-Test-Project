#pragma once

#include "mesh.h"

namespace gdl {

class Model{
private:
	std::vector<gdl::Mesh> meshes;

public:

	Model(const std::vector<gdl::Mesh>& meshes);
	Model(const gdl::Mesh& mesh);

	std::vector<gdl::Mesh>& get_meshes();
};






}
