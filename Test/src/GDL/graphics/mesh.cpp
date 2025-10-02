#include "../../../include/GDL/graphics/mesh.h"
#include "../../../include/glad/glad.h"

namespace gdl::graphics{


Mesh::Mesh(const std::vector<Vertex>& vert, const std::vector<u32> idx) : vertices(vert), indices(idx) {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(u32), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	glBindVertexArray(0);
}

void Mesh::draw(gdl::graphics::Shader& shader){

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, (u32)indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


}










