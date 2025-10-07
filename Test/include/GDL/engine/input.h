#pragma once

#include <array>
#include <GLFW/glfw3.h>

namespace gdl {

#define MAX_KEYS (GLFW_KEY_LAST + 1)
#define MAX_BUTTONS (GLFW_MOUSE_BUTTON_LAST + 1)

class Input{
	static std::array<bool, MAX_KEYS> key_now;
	static std::array<bool, MAX_KEYS> key_last;

	static std::array<bool, MAX_BUTTONS> button_now;
	static std::array<bool, MAX_BUTTONS> button_last;

public:
	static void update(GLFWwindow* win);

	static bool key_click(int k);
	static bool key_hold(int k);
	static bool key_release(int k);

	static bool mouse_click(int k);
	static bool mouse_hold(int k);
	static bool mouse_release(int k);
};

}







