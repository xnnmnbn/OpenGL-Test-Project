#pragma once

#include "../tools/typedefs.h"

#include <glm/glm.hpp>

namespace gdl {

enum class CameraMode {
	PERSPECTIVE  = 0,
	ORTHOGRAPHIC = 1
};

struct Camera{

	CameraMode mode;

	f32 width;
	f32 height;
	f32 far;
	f32 near;

	f32 zoom;
	f32 fovy;

	glm::mat4 get_view_matrix();
	glm::mat4 get_proj_matrix();

	glm::vec3 position{0, 0, 0};
	glm::vec3 target{0, 0, 0};

	Camera(CameraMode mode = CameraMode::PERSPECTIVE, f32 w = 1280, f32 h = 720, f32 f = 1000, f32 n = 0.1, f32 z = 1, f32 fov = 45);

	static void update(Camera& camera);
};


}







