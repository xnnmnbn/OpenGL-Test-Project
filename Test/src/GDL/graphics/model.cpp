#include "../../../include/GDL/graphics/model.h"
#include <glm/gtc/matrix_transform.hpp>

namespace gdl {


Model::Model(const std::vector<gdl::Mesh>& meshes) : meshes(meshes) {}

Model::Model(const gdl::Mesh& mesh) {
	meshes.push_back(mesh);
}

std::vector<gdl::Mesh>& Model::get_meshes(){
	return meshes;
}



}








