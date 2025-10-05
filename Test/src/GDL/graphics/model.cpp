#include "../../../include/GDL/graphics/model.h"
#include <glm/gtc/matrix_transform.hpp>

namespace gdl::graphics {


Model::Model(const std::vector<gdl::graphics::Mesh>& meshes) : meshes(meshes) {}

Model::Model(const gdl::graphics::Mesh& mesh) {
	meshes.push_back(mesh);
}

std::vector<gdl::graphics::Mesh>& Model::get_meshes(){
	return meshes;
}



}








