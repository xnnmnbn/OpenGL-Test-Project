#pragma once

#include "../graphics/model.h"
#include <vector>

namespace gdl::components {

class Transform{
public:
private:
	Transform* parent;
	std::vector<Transform*> children;

	gdl::Model* model;

	glm::mat4 world_matrix;
	glm::mat4 local_matrix;


public:
	glm::vec3 local_position;
	glm::vec3 local_rotation;
	glm::vec3 local_scale;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 forward;

	Transform(gdl::Model* m = NULL);

	Transform* get_child(u32 idx);

	glm::mat4& get_matrix();
	gdl::Model* get_model();

	void set_parent(Transform* t);
	void remove_child(Transform* t);


	static void update(Transform& t);
};


}






