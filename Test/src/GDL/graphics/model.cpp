#include "../../../include/GDL/graphics/model.h"
#include <glm/gtc/matrix_transform.hpp>

namespace gdl::graphics {


Model::Model(const std::vector<gdl::graphics::Mesh>& meshes) : meshes(meshes) {
/*
	position = glm::vec3(0);
	rotation = glm::vec3(0);
	scale = glm::vec3(1, 1, 1);
*/
}

Model::Model(const gdl::graphics::Mesh& mesh) {
	meshes.push_back(mesh);
/*
	position = glm::vec3(0);
	rotation = glm::vec3(0);
	scale = glm::vec3(1, 1, 1);
*/
}

std::vector<gdl::graphics::Mesh>& Model::get_meshes(){
	return meshes;
}



}








