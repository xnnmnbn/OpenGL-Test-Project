#include "../../../include/GDL/components/renderer.h"



namespace gdl::components {

Renderer::Renderer(gdl::components::Transform& t) : t(&t), m(t.get_model()) {}

void Renderer::draw(gdl::graphics::Shader& shader, gdl::engine::Camera& camera){

	shader.use();

	shader.setMat4("model", t->get_matrix());
	shader.setMat4("view", camera.GetViewMatrix());
	shader.setMat4("projection", camera.getProjectionMatrix());

	for(gdl::graphics::Mesh& mesh : t->get_model()->get_meshes()){
		mesh.draw(shader);
	}
}


}





