#pragma once

#include "../tools/vector3.h"
#include "../graphics/model.h"
#include <vector>

namespace gdl::components {

class Transform{
public:
private:
	Transform* parent;
	std::vector<Transform*> children;

	gdl::graphics::Model* model;

	glm::mat4 world_matrix;
	glm::mat4 local_matrix;


public:
	gdl::tools::Vector3 local_position;
	gdl::tools::Vector3 local_rotation;
	gdl::tools::Vector3 local_scale;

	gdl::tools::Vector3 position;
	gdl::tools::Vector3 rotation;
	gdl::tools::Vector3 scale;

	gdl::tools::Vector3 right;
	gdl::tools::Vector3 up;
	gdl::tools::Vector3 forward;

	Transform(gdl::graphics::Model* m = NULL);

	Transform* get_child(u32 idx);

	glm::mat4& get_matrix();
	gdl::graphics::Model* get_model();

	void set_parent(Transform* t);
	void remove_child(Transform* t);


	static void update(Transform& t);
};


}






