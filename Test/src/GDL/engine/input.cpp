#include "../../../include/GDL/engine/input.h"

#include <GLFW/glfw3.h>

namespace gdl {

std::array<bool, MAX_KEYS> Input::key_now;
std::array<bool, MAX_KEYS> Input::key_last;

std::array<bool, MAX_BUTTONS> Input::button_now;
std::array<bool, MAX_BUTTONS> Input::button_last;





void Input::update(GLFWwindow* win){
	key_last = key_now;
	button_last = button_now;

	for(int i = 32; i < MAX_KEYS; i++){
		key_now[i] = glfwGetKey(win, i) == GLFW_PRESS;
	}

	for(int i = 0; i < MAX_BUTTONS; i++){
		button_now[i] = glfwGetMouseButton(win, i);
	}
}

bool Input::key_click(int k){
	return key_now[k] && !key_last[k];
}
bool Input::key_hold(int k){
	return key_now[k];
}
bool Input::key_release(int k){
	return !key_now[k] && key_last[k];
}

bool Input::mouse_click(int k){
	return button_now[k] && !button_last[k];
}
bool Input::mouse_hold(int k){
	return button_now[k];
}
bool Input::mouse_release(int k){
	return !button_now[k] && button_last[k];
}

}







