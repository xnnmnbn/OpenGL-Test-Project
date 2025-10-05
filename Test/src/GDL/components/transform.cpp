#include "../../../include/GDL/components/transform.h"
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <algorithm>

namespace gdl::components {

Transform::Transform(gdl::graphics::Model* m) : model(m) {
	this->local_position = {0, 0, 0};
	this->local_rotation = {0, 0, 0};
	this->local_scale = {1, 1, 1};

	this->position = {0, 0, 0};
	this->rotation = {0, 0, 0};
	this->scale = {1, 1, 1};

	parent = NULL;
}

glm::mat4& Transform::get_matrix(){
	return world_matrix;
}

gdl::graphics::Model* Transform::get_model(){

	if(model) return model;

	return NULL;
}


Transform* Transform::get_child(u32 idx){
	return children[idx];
}

void Transform::set_parent(Transform* t){

	if(t == this) return;
	if(t){
		if(t->parent == this) return;
	}

	if(parent){
		parent->children.erase(std::remove(
			parent->children.begin(),
			parent->children.end(),
			this
		));
	}

	if(t){
		t->children.push_back(this);
		this->local_position = t->position - this->position;
	}

	this->parent = t;
}

void Transform::remove_child(Transform* t){
	if(!t || t == this || t == this->parent) return;

	children.erase(std::remove(
		children.begin(),
		children.end(),
		t
	));
}


void Transform::update(Transform& t){


	t.local_matrix = glm::mat4(1.0);

	t.local_matrix = glm::translate(t.local_matrix, glm::vec3(t.local_position.x, -t.local_position.y, t.local_position.z));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.x), glm::vec3(1, 0, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.y), glm::vec3(0, 1, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.z), glm::vec3(0, 0, 1));
	t.local_matrix = glm::scale(t.local_matrix, glm::vec3(t.local_scale.x, t.local_scale.y, t.local_scale.z));

	if (t.parent){
		t.world_matrix = t.parent->world_matrix * t.local_matrix;

	} else {
		t.world_matrix = t.local_matrix;
	}

	t.position = glm::vec3(t.world_matrix[3]);

	t.right = glm::normalize(glm::vec3(t.world_matrix[0]));
	t.up = glm::normalize(glm::vec3(t.world_matrix[1]));
	t.forward = glm::normalize(glm::vec3(t.world_matrix[2]));

	glm::mat3 rot(t.right, t.up, t.forward);

	t.rotation = glm::degrees(glm::eulerAngles(glm::quat_cast(rot)));

}




}



