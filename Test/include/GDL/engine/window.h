#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

#include "../tools/typedefs.h"


namespace gdl {


class Window{
private:
	GLFWwindow* window;
	u16 width;
	u16 height;
	str title;

public:
	Window(u16 w, u16 h, const str& t);

	GLFWwindow* get_win();
	bool should_close();
	void kill();
	void swap_buffers();

	u16 w();
	u16 h();
};


}








