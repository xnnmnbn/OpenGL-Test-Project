#include "../../../include/GDL/components/transform.h"
#include <glm/gtc/matrix_transform.hpp>

#include <algorithm>

namespace gdl::components {

Transform::Transform(gdl::graphics::Model* m) : model(m) {
	local_scale.x = 1;
	local_scale.y = 1;
	local_scale.z = 1;

	scale.x = 1;
	scale.y = 1;
	scale.z = 1;

	parent = NULL;
/*
	if(model){
		model->position = glm::vec3(position.x, position.y, position.z);
		model->rotation = glm::vec3(rotation.x, rotation.y, rotation.z);
		model->scale = glm::vec3(scale.x, scale.y, scale.z);
	}
*/
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

	t.local_matrix = glm::translate(t.local_matrix, glm::vec3(t.position.x, t.position.y, t.position.z));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.position.x), glm::vec3(1, 0, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.position.y), glm::vec3(0, 1, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.position.z), glm::vec3(0, 0, 1));
	t.local_matrix = glm::scale(t.local_matrix, glm::vec3(t.scale.x, t.scale.y, t.scale.z));

	if (t.parent){
		t.world_matrix = t.parent->world_matrix * t.local_matrix;
	} else {
		t.world_matrix = t.local_matrix;
	}
}




}



