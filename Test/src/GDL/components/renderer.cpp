#include "../../../include/GDL/components/renderer.h"



namespace gdl::components {

Renderer::Renderer(gdl::components::Transform& t) : t(&t), m(t.get_model()) {}

void Renderer::draw(gdl::Shader& shader, gdl::Camera& camera){

	shader.use();

	shader.setMat4("model", t->get_matrix());
	shader.setMat4("view", camera.get_view_matrix());
	shader.setMat4("projection", camera.get_proj_matrix());

	for(gdl::Mesh& mesh : t->get_model()->get_meshes()){
		mesh.draw(shader);
	}
}


}





