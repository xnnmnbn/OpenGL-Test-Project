#include "../../../include/GDL/game/camera.h"

#include <glm/gtc/matrix_transform.hpp>


namespace gdl {

Camera::Camera(CameraMode mode, f32 w, f32 h, f32 f, f32 n, f32 z, f32 fov) :
	mode(mode),
	width(w),
	height(h),
	far(f),
	near(n),
	zoom(z),
	fovy(fov)
{}

glm::mat4 Camera::get_proj_matrix(){
	if(mode == CameraMode::PERSPECTIVE){
		return glm::perspective(glm::radians(fovy), (width / height), near, far);
	} else {
		return glm::ortho(-(width / 2), (width / 2), -(height / 2), (height / 2));
	}
}

glm::mat4 Camera::get_view_matrix(){
	return glm::lookAt(position, target, glm::vec3(0, 1, 0));
}



}







