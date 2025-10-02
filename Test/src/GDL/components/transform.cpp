#include "../../../include/GDL/components/transform.h"
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

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

	t.local_matrix = glm::translate(t.local_matrix, glm::vec3(t.local_position.x, t.local_position.y, t.local_position.z));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.x), glm::vec3(1, 0, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.y), glm::vec3(0, 1, 0));
	t.local_matrix = glm::rotate(t.local_matrix, glm::radians(t.local_rotation.z), glm::vec3(0, 0, 1));
	t.local_matrix = glm::scale(t.local_matrix, glm::vec3(t.local_scale.x, t.local_scale.y, t.local_scale.z));

	if (t.parent){
		t.world_matrix = t.parent->world_matrix * t.local_matrix;

	} else {
		t.world_matrix = t.local_matrix;
	}

	glm::vec3 pos(t.world_matrix[3]);

	t.position.x = pos.x;
	t.position.y = pos.y;
	t.position.z = pos.z;

	glm::vec3 r = glm::normalize(glm::vec3(t.world_matrix[0]));
	glm::vec3 u = glm::normalize(glm::vec3(t.world_matrix[1]));
	glm::vec3 f = glm::normalize(glm::vec3(t.world_matrix[2]));

	t.right.x = r.x;
	t.right.y = r.y;
	t.right.z = r.z;

	t.up.x = u.x;
	t.up.y = u.y;
	t.up.z = u.z;

	t.forward.x = f.x;
	t.forward.y = f.y;
	t.forward.z = f.z;

	glm::mat3 rot(r, u, f);

	glm::vec3 euler = glm::degrees(glm::eulerAngles(glm::quat_cast(rot)));

	t.rotation.x = euler.x;
	t.rotation.y = euler.y;
	t.rotation.z = euler.z;

}




}



